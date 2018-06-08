#ifndef TIGER_LIVENESS_H_
#define TIGER_LIVENESS_H_

#include "graph.h"
#include "temp.h"

typedef struct Live_moveList_ *Live_moveList;
struct Live_moveList_ {
	G_node src, dst;
	Live_moveList tail;
};

typedef struct Live_graph_ *Live_graph;
struct Live_graph_ {
	G_graph graph;
	Live_moveList moves;
};

Live_moveList Live_MoveList(G_node src, G_node dst, Live_moveList tail);
Live_graph Live_Graph(G_graph graph, Live_moveList moves);
Live_graph Live_liveness(G_graph flow);
Temp_temp Live_gtemp(G_node node);

typedef struct TAB_table_ *T_table;
T_table T_empty(void);
void T_enter(T_table t, Temp_temp temp, G_node value);
G_node T_look(T_table t, Temp_temp temp);

#endif // TIGER_LIVENESS_H_
