#include "liveness.h"
#include "utils.h"
#include "flowgraph.h"

static G_table liveMap;
static T_table tempMap;

//record MOVE edge
Live_moveList Live_MoveList(G_node src, G_node dst, Live_moveList tail)
{
	Live_moveList moves = checked_malloc(sizeof(*moves));
	moves->src = src;
	moves->dst = dst;
	moves->tail = tail;
	return moves;
}

Live_graph Live_Graph(G_graph graph, Live_moveList moves) {
	Live_graph lg = checked_malloc(sizeof(*lg));
	lg->graph = graph;
	lg->moves = moves;
	return lg;
}

static void enterLiveMap(G_table t, G_node flowNode, Temp_tempList temps) {
	G_enter(t, flowNode, temps);
}

static Temp_tempList lookupLiveMap(G_table t, G_node flowNode) {
	return (Temp_tempList)G_look(t, flowNode);
}

//duplicate the temp list
static Temp_tempList duplicateList(Temp_tempList l) {
	if(l == NULL)
		return NULL;
	if(l->tail)
		duplicateList(l->tail);
	return Temp_TempList(l->head, l->tail);
}

// small -> big, the key is cast Temp_temp to unsigned int
static Temp_tempList sortedInsert(Temp_tempList l, Temp_temp t){
	if(l == NULL) {
		l = Temp_TempList(t, NULL);
	}
	else {
		Temp_tempList p = l;
		while(p->tail) {
			if(p == l) {
				if(p->head == t) 
					return l;
				if((unsigned int)(p->head) > (unsigned int)(t))
					break;
			}
			else {
				if(p->tail->head == t)
					return l;
				if((unsigned int)(p->tail->head) > (unsigned int)(t))
					break;
			}
			p = p->tail;
		}
		if(p == l){
			l = Temp_TempList(t, p);
		}
		else {
			p->tail = Temp_TempList(t, p->tail);
		}
	}
	return l;
}

static Temp_tempList deleteTemp(Temp_tempList l, Temp_temp t) {
	Temp_tempList p = l, prev = NULL;
	while(p) {
		if(p->head == t) {
			if(p == l) {
				l = l->tail;
				break;
			}
			else {
				prev->tail = p->tail;
				break;
			}
		}
		prev = p;
		p = p->tail;
	}
	return l;
}

// l1 U l2
static Temp_tempList tempList_join(Temp_tempList l1, Temp_tempList l2) {
	Temp_tempList list = duplicateList(l1);
	Temp_tempList p = l2;
	for( ; p; p=p->tail) {
		list = sortedInsert(list, p->head);
	}
	return list;
}

// l1 - l2
static Temp_tempList tempList_diff(Temp_tempList l1, Temp_tempList l2) {
	Temp_tempList p = l2;
	Temp_tempList list = duplicateList(l1);
	if(list == NULL)
		return list;
	for( ; p; p=p->tail) {
		list = deleteTemp(list, p->head);
	}
	return list;
}

//test if l1 == l2
static bool tempList_Euqal(Temp_tempList l1, Temp_tempList l2) {
	Temp_tempList p1 = l1, p2 = l2;
	for(; p1&&p2; p1=p1->tail,p2=p2->tail) {
		if(p1->head != p2->head) 
			return FALSE;
	}
	if(p1 || p2)
		return FALSE;
	return TRUE;
}

//liveness analyze 
Live_graph Live_liveness(G_graph flow)
{
	liveMap = G_empty();
	tempMap = T_empty();
	Live_graph lg = Live_Graph(G_Graph(), NULL); //conflict graph

	//iterative compute the live-in and live-out
	Temp_tempList liveIn[flow->nodecount], liveInPrime[flow->nodecount];
	Temp_tempList liveOut[flow->nodecount], liveOutPrime[flow->nodecount];
	//initialize
	int i;
	for(i=0; i<flow->nodecount; i++) {
		liveIn[i] = liveOut[i] = NULL;
	}
	G_nodeList p, t;
	while(1) {
		for(p=flow->mynodes; p; p=p->tail) {
			//duplicate 
			int index = p->head->mykey;
			liveInPrime[index] = duplicateList(liveIn[index]);
			liveOutPrime[index] = duplicateList(liveOut[index]);
			//calculate live-in and live-out
			liveIn[index] = tempList_join(tempList_diff(liveOut[index], FG_def(p->head)),  
								FG_use(p->head));
			for(t=p->head->succs; t; t=t->tail)
				liveOut[index] = tempList_join(liveOut[index], liveIn[t->head->mykey]);
		}

		bool isEnd = TRUE;
		for(i=0; i<flow->nodecount; i++) {
			isEnd = isEnd & tempList_Euqal(liveInPrime[i], liveIn[i])\
						 & tempList_Euqal(liveOutPrime[i], liveOut[i]);
			if(!isEnd)
				break;
		}
		if(isEnd)
			break;
	}

	//store the live-out of each node
	for(p=flow->mynodes; p; p=p->tail) {
		enterLiveMap(liveMap, p->head, liveOut[p->head->mykey]);
	}

	//establish the conflict graph
	for(p=flow->mynodes; p; p=p->tail) {
		G_node n1, n2;
		Temp_tempList p1, p2;
		if(FG_isMove(p->head)) {
			p1 = FG_use(p->head);
			p2 = FG_def(p->head);
			if(p1 && (n1 = T_look(tempMap, p1->head)) == NULL) {
				n1 = G_Node(lg->graph, p1->head);
				T_enter(tempMap, p1->head, n1);
			} 
			if(p2 && (n2 = T_look(tempMap, p2->head)) == NULL) {
				n2 = G_Node(lg->graph, p2->head);
				T_enter(tempMap, p2->head, n2);
			}
			if(n1 && n2)
				lg->moves = Live_MoveList(n1, n2, lg->moves);
			continue;
		}
		Temp_tempList outList = lookupLiveMap(liveMap, p->head);
		Temp_tempList defList = FG_def(p->head);
		
		for(p1=defList; p1; p1=p1->tail) {	
			for(p2=outList; p2; p2=p2->tail) {
				if((n1 = T_look(tempMap, p1->head)) == NULL) {
					n1 = G_Node(lg->graph, p1->head);
					T_enter(tempMap, p1->head, n1);
				} 
				if((n2 = T_look(tempMap, p2->head)) == NULL) {
					n2 = G_Node(lg->graph, p2->head);
					T_enter(tempMap, p2->head, n2);
				}
				//bi-direction
				G_addEdge(n1, n2);
				G_addEdge(n2, n1);
			}
		}
	}

	return lg;
}

Temp_temp Live_gtemp(G_node node)
{
	return (Temp_temp) node->info;
}

T_table T_empty() {
	return TableEmpty();
}

void T_enter(T_table t, Temp_temp temp, G_node node) {
	TableEnter(t, temp, node);
}

G_node T_look(T_table t, Temp_temp temp) {
	return (G_node)TableLookup(t, temp);
}
