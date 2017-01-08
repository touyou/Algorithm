/**
 * 蟻本の実装
 */
#include <limits.h>

#define MAX_V 100
#define min(a,b) ((a)<(b)?a:b)

int cost[MAX_V][MAX_V];
int mincost[MAX_V];
int used[MAX_V];
int V;

int prim() {
    for (int i=0; i<V; i++) {
        mincost[i] = INT_MAX;
        used[i] = 0;
    }
    mincost[0] = 0;
    int res = 0;
    while (1) {
        int v = -1;
        for (int u=0; u<V; u++) {
            if (!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
        }
        if (v == -1) break;
        used[v] = true;
        res += mincost[v];

        for (int u=0; u<V; u++) {
            mincost[u] = min(mincost[u], cost[v][u]);
        }
    }
    return res;
}
