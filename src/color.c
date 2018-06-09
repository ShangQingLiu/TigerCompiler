#include "color.h"
#include "utils.h"
#include <string.h>
#include <stdio.h>
#include "liveness.h"

#define COL_DEBUG

char **AdjMatrix;  // Adjacent matrix
G_node *Alias;     // Coalesced nodes, a disjoint set
int *Degree;       // Node degree
list_t *NodeMoves; // Move related node list
G_node *Stack;     // Stack for coloring
int sp;            // Stack pointer
list_t simplifyList, freezeList, spillList, coaList, actualSpill;

const int K = 6;

char isMoveRelated(G_node n)
{
    return NodeMoves[n->mykey] != NULL;
}

G_node Combine(G_node s, G_node t)
{
    int tNum = t->mykey;
    Alias[tNum] = s;
    return s;
}

G_node Find(G_node n)
{
    int num = n->mykey;
    if (Alias[num] == 0) return n;
    else return Alias[num] = Find(Alias[num]);
}

static void decDegree(G_node n)
{
    int num = n->mykey;
    if (Alias[num] || Degree[num]<0) return;
    Degree[num]--;
    if (Degree[num] == K-1)
    {
        deleteFrom(n, &spillList);
        if (isMoveRelated(n)) addTo(n, &freezeList);
        else addTo(n, &simplifyList);
    }
}

static void Simplify(Live_graph lg)
{
    list_t p;
    G_node n;
    G_nodeList l;

    while (simplifyList)
    {
        p = simplifyList;
        n = p->data;
        simplifyList = simplifyList->tail;
        free(p);
        for (l = n->succs; l; l = l->tail)
        {
            decDegree(l->head);
        }
        Degree[n->mykey] = -1; // Marked as simplified
        Stack[sp++] = n;
    }
}

static char Coalesce(Live_graph lg)
{
    Live_moveList mList, last = NULL;
    for (mList = lg->moves; mList; )
    {
        G_node src = mList->src, dst = mList->dst;
        src = Find(src);
        dst = Find(dst);
        if (src == dst)
        {
            // Delete from move list
            if (last == NULL)
            {
                last = mList;
                lg->moves = mList = mList->tail;
                free(last);
                last = NULL;
            }
            else
            {
                mList = last->tail = mList->tail;
                free(mList);
                mList = last->tail;
            }
            continue;
        }

        G_nodeList np;
        int srcNum = src->mykey, dstNum = dst->mykey;
        char flag = 1;
        for (np = src->succs; np; np = np->tail)
        {
            int nNum = np->head->mykey;
            if (AdjMatrix[nNum][dstNum]==1 || Degree[nNum] < K)
                continue;
            else
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        { // Valid to combine
            G_node r = Combine(src, dst);
            G_node s = (r == src) ? dst : src;
            int rNum = r->mykey;
            int sNum = s->mykey;
            for (np = s->succs; np; np = np->tail)
            {
                int nNum = np->head->mykey;
                if (Degree[nNum] < 0 || Alias[nNum] != 0)
                    continue;
                if (AdjMatrix[nNum][rNum]==1) // Adjacent to both nodes
                {
                    decDegree(np->head);
                }
                else
                {
                    G_addEdge(r, np->head);
                    G_addEdge(np->head, r);
                    AdjMatrix[nNum][rNum] = 1;
                    AdjMatrix[rNum][nNum] = 1;
                    Degree[rNum]++;
                }
            }
            if (!deleteFrom(s, &freezeList))
                deleteFrom(s, &spillList);
            #ifdef COL_DEBUG
            list_t temp;
            printf("list R %d:\n", r->mykey);
            for (temp=NodeMoves[rNum]; temp; temp=temp->tail) {
                printf("%d  ", ((G_node)(temp->data))->mykey);
            }
            printf("\nlist S %d:\n", s->mykey);
            for (temp=NodeMoves[sNum]; temp; temp=temp->tail) {
                printf("%d  ", ((G_node)(temp->data))->mykey);
            }
            #endif

            mergeList(&NodeMoves[rNum], &NodeMoves[sNum]);
            
            #ifdef COL_DEBUG
            printf("\nMerged list R:\n");
            for (temp=NodeMoves[rNum]; temp; temp=temp->tail) {
                printf("%d  ", ((G_node)(temp->data))->mykey);
            }
            #endif

            if (Degree[rNum] >= K && deleteFrom(r, &freezeList))
            {
                addTo(r, &spillList);
            }
            return 1;
        } // if flag
        mList = mList->tail;
    }
    return 0;
}

static void FreezeAdj(G_node n)
{
    list_t p, last, moveAdj = NodeMoves[n->mykey];
    while (moveAdj)
    {
        G_node m = moveAdj->data;
        int mNum = m->mykey;
        printf("Fadj %d\n", mNum);
        list_t iter = NodeMoves[mNum];
        last = NULL;
        while (iter)
        {
            G_node t = iter->data;
            int tNum = t->mykey;
            printf("\tMove to %d\n", tNum);
            if (t==n || Degree[tNum]<0 || Alias[tNum])
            {
                // Remove this node from move list
                p = iter;
                iter = iter->tail;
                printf("delete node move:%d %p %p\n", tNum, p, iter);
                free(p);
                if (last == NULL)
                    NodeMoves[mNum] = iter;
                else
                    last->tail = iter;
            }
            else
            {
                last = iter;
                iter = iter->tail;                
            }
        }   // while iter
        if (!NodeMoves[mNum] && Degree[mNum]<K)
        {
            deleteFrom(m, &freezeList);
            addTo(m, &simplifyList);
        }
        moveAdj = moveAdj->tail;
    }
}

static void Freeze()
{
    G_node n = freezeList->data;
    #ifdef COL_DEBUG
    printf("Freeze node: %x  %d\n", n, n->mykey);
    #endif
    deleteFrom(n, &freezeList);    
    addTo(n, &simplifyList);
    
    FreezeAdj(n);
    #ifdef COL_DEBUG
    printf("Freeze adj\n");
    #endif
}

static void SelectSpill()
{
    list_t p;
    G_node candid;
    int maxD = 0, pNum;
    
    for (p=spillList; p; p=p->tail)
    {     
        pNum = ((G_node)(p->data))->mykey;
        if (Degree[pNum] > maxD)
        {
            maxD = Degree[pNum];
            candid = p->data;
        }
    }
    pNum = candid->mykey;
    // Mark as potential spill
    Degree[pNum] = -2;
    printf("Selected Spill%d\n", pNum);
    
    Stack[sp++] = candid;
    deleteFrom(candid, &spillList);

    G_nodeList l;
    
    for (l=candid->succs; l; l=l->tail)
    {
        decDegree(l->head);
    }
}



static void preProc(Live_graph lg)
{
    int n, i, j;
    
    assert(lg);
    n = lg->graph->nodecount;

    #ifdef COL_DEBUG
    printf("preproc  %x\n", lg->graph);
    printf("Nodes: %d\n", n);
    #endif    

    // Init global variables    
    AdjMatrix = (char **)checked_malloc(n * sizeof(*AdjMatrix));
    for (i = 0; i < n; i++)
    {
        AdjMatrix[i] = (char *)checked_malloc(n * sizeof(char));
        memset(AdjMatrix[i], 0, n);
    }
    Alias = (G_node *)checked_malloc(n * sizeof(*Alias));
    memset(Alias, 0, n * sizeof(*Alias));
    Degree = (int *)checked_malloc(n * sizeof(*Degree));
    memset(Degree, 0, n * sizeof(*Degree));
    NodeMoves = (list_t *)checked_malloc(n * sizeof(*NodeMoves));
    memset(NodeMoves, 0, n * sizeof(*NodeMoves));
    Stack = (G_node *)checked_malloc(n * sizeof(*Stack));
    sp = 0;
    simplifyList = freezeList = spillList = coaList = NULL;

    #ifdef COL_DEBUG
    printf("Init finish\n");
    #endif

    // Count degrees
    G_nodeList p;
    for (p = lg->graph->mynodes; p; p = p->tail)
    {
        G_nodeList np;
        int dCount = 0, curNum = p->head->mykey;
        for (np = p->head->succs; np; np = np->tail)
        {
            dCount++;
            AdjMatrix[curNum][np->head->mykey] = 1;
            AdjMatrix[np->head->mykey][curNum] = 1;
        }
        Degree[curNum] = dCount;
    }

    // Build node movelist
    Live_moveList mList;
    for (mList = lg->moves; mList; mList = mList->tail)
    {
        G_node src = mList->src, dst = mList->dst;
        if (AdjMatrix[src->mykey][dst->mykey]) continue;
        if (src == dst) {
            assert(0);
        }
        addToOrder(src, &(NodeMoves[dst->mykey]));
        addToOrder(dst, &(NodeMoves[src->mykey]));
        AdjMatrix[src->mykey][dst->mykey] = 2;
        AdjMatrix[dst->mykey][src->mykey] = 2;
    }

    // Build freeze, simplify, spill list
    for (p = lg->graph->mynodes; p; p = p->tail)
    {
        int curNum = p->head->mykey;
        if (Degree[curNum] < K)
        {
            if (isMoveRelated(p->head))
                addTo(p->head, &freezeList);
            else
                addTo(p->head, &simplifyList);
        }
        else
            addTo(p->head, &spillList);
    }
    #ifdef COL_DEBUG
    printf("Build finish\n");
    #endif
}

static void endProc(Live_graph lg)
{
    int i, n = lg->graph->nodecount;
    AdjMatrix = (char **)checked_malloc(n * sizeof(*AdjMatrix));
    for (i = 0; i < n; i++)
    {
        free(AdjMatrix[i]);
    }
    free(AdjMatrix);
    free(Alias);
    free(Degree);
    free(NodeMoves);
    free(Stack);
}

static Temp_map AssignColor()
{
    char colorPad[K+1];
    int i, count = 0;
    Temp_map mmap = Temp_empty();
    while (sp)
    {
        G_node n = Stack[--sp];
        memset(colorPad, 0, (K+1)*sizeof(char));
        G_nodeList l;
        for (l=n->succs; l; l=l->tail)
        {
            G_node nei = l->head;
            if (Degree[nei->mykey] > 0 && Alias[nei->mykey] == 0)
            {
                int neiCol = (int)Temp_look(mmap, nei->info);
                printf("Nei %d\n", neiCol);
                colorPad[(int)Temp_look(mmap, nei->info)] = 1;
            }
        }
        for (i=1; i<=K; i++)
        {
            if (colorPad[i]) continue;
            else break;
        }

        if (i > K)
        {
            //Temp_enter(mmap, n->info, (string_t)0);
            addTo(n->info, &actualSpill);
            count ++;
        }
        else
        {
            Degree[n->mykey] = 1;
            Temp_enter(mmap, n->info, (string_t)i);
            printf("Enter %d\n", i);
        }
    }
    printf("%d Actual spills\n", count);
    return mmap;
}

struct COL_result COL_color(Live_graph lg, Temp_map initial, Temp_tempList regs)
{
    char tRes;
    printf("col begin\n");
    preProc(lg);
    
    while (simplifyList != NULL || freezeList != NULL || spillList != NULL)
    {
        if (simplifyList != NULL)
        {
            Simplify(lg);
            #ifdef COL_DEBUG
            printf("Simplify done: %x\n", simplifyList);
            #endif
        }
        else
        {
            tRes = Coalesce(lg);
            #ifdef COL_DEBUG
            printf("Coalesce done: %d\n", tRes);
            #endif
            if (tRes)
                continue;

            if (freezeList != NULL)
            {
                Freeze();
                #ifdef COL_DEBUG
                printf("Freeze done: %d\n", freezeList);
                #endif
            }
            else
            {
                SelectSpill();
                #ifdef COL_DEBUG
                printf("SelectSpill done\n");
                #endif
            }
        }
    }
printf("sp: %d\n", sp);
    struct COL_result rst;
    rst.coloring = AssignColor(lg);
    rst.spills = actualSpill;

    endProc(lg);
    printf("colend\n");
    return rst;
}
