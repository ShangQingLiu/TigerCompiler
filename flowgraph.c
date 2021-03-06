#include "flowgraph.h"
#include "assem.h"

static void FG_completeEdges(TL_table t, G_node node);

Temp_tempList FG_def(G_node n)
{
	AS_instr instr = G_nodeInfo(n);
	if (n != NULL) {
		switch (instr->kind) {
			case I_OPER: return instr->u.OPER.dst;
			case I_LABEL: return NULL;
			case I_MOVE: return instr->u.MOVE.dst;
			default: assert(0 && "Invalid instruction kind");
		}
	}
	return NULL;
}

Temp_tempList FG_use(G_node n)
{
	AS_instr instr = G_nodeInfo(n);
	if (n != NULL) {
		switch (instr->kind) {
			case I_OPER: return instr->u.OPER.src;
			case I_LABEL: return NULL;
			case I_MOVE: return instr->u.MOVE.src;
			default: assert(0 && "Invalid instruction kind");
		}
	}
	return NULL;
}

bool FG_isMove(G_node n)
{
	AS_instr instr = G_nodeInfo(n);
	return (instr != NULL && instr->kind == I_MOVE);
}

G_graph FG_AssemFlowGraph(AS_instrList il)
{
	G_graph g = G_Graph();
	G_nodeList nodes = NULL;
	TL_table tl = TL_empty();
	AS_instrList cursor = il;
	AS_instr instr = NULL;
	G_node current = NULL, prev = NULL;
	for (; cursor; cursor = cursor->tail) {
		instr = cursor->head;
		switch (instr->kind) {
			case I_LABEL:
				// Add label->node mapping so we can retrieve the node
				// later.
				TL_enter(tl, instr->u.LABEL.label, current);
				break;
			case I_MOVE:
				
				break;
			case I_OPER:
				// Add to node list that we will complete later
				nodes = G_NodeList(current, nodes);
				break;
			default: assert(0 && "Invalid instruction kind");
		}
		current = G_Node(g, instr);
		if (prev) G_addEdge(prev, current);
		prev = current;
	}
	// Complete the edges
	for (; nodes; nodes = nodes->tail) {
		current = nodes->head;
		FG_completeEdges(tl, current);
	}
	return g;
}

static void FG_completeEdges(TL_table t, G_node node)
{
	AS_targets targets = ((AS_instr)G_nodeInfo(node))->u.OPER.jumps;
	if(!targets)
		return;
	Temp_labelList labelList = targets->labels;
	G_node neighbour = NULL;
	for (; labelList; labelList = labelList->tail) {
		// Look for the node that we could jump to from 'node'
		neighbour = TL_look(t, labelList->head);
		// Don't add if edge already exists
		if (neighbour && !G_goesTo(node, neighbour))
			G_addEdge(node, neighbour);
	}
}
