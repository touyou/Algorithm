/**
 * 蟻本の実装
 */

#define MAX_E 100
#define MAX_V 100

// Util
typedef struct Edge {
    int u, v, cost;
} Edge;
int comp(Edge *e1, Edge *e2) {
    return e1->cost < e2->cost;
}
Edge es[MAX_E];
int V, E;

// Union find
int par[MAX_V];
int rank[MAX_V];
void init_union_find(int n) {
    for (int i=0; i<n; i++) {
        par[i] = i;
        rank[i] = 0;
    }
}
int find(int x) {
    if (par[x] == x) return x;
    else return par[x] = find(par[x]); // cでこれやっていいのか怪しい
}
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rank[x] < rank[y]) par[x] = y;
    else {
        par[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
    }
}
int same(int x, int y) {
    return find(x) == find(y);
}

// こっからクラスカル
int kruskal() {
    // esをcost順にソート。なんかしらで
    init_union_find(V);
    int res = 0;
    for (int i=0; i<E; i++) {
        Edge *e = es + i;   // ここ怪しい
        if (!same(e->u, e->v)) {
            unite(e->u, e->v);
            res += e->cost;
        }
    }
    return res;
}
