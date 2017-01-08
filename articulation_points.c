/**
 * http://judge.u-aizu.ac.jp/onlinejudge/commentary.jsp?id=GRL_3_A
 * の擬似コードに基づく実装。これをひな形に(ry
 */

#define V_NUM 50
#define min(a,b) ((a)<(b)?a:b)

typedef struct Edge {
    int t;
    struct Edge *next;
} Edge;

Edge edge[V_NUM];
int parent[V_NUM];
int prenum[V_NUM];
int lowest[V_NUM];
int visited[V_NUM];
int is_artic[V_NUM];
int timer;

void dfs(int u, int prev) {
    prenum[u] = timer;
    lowest[u] = timer;
    timer++;
    visited[u] = 1;

    Edge *e = edge[u];
    while (e != NULL) {
        if (!visited[e->t]) {
            parent[e->t] = u;
            dfs(e->t, u);
            lowest[u] = min(lowest[u], lowest[e->t]);
        } else if (e->t != prev) {
            lowest[u] = min(lowest[u], prenum[e->t]);
        }
        e = e->next;
    }
}

void artic_point() {
    // init_vertex
    for (int i=0; i<V_NUM; i++) visited[i] = 0;
    timer = 1;
    // lowest, lowlinkの計算
    dfs(0, -1);
    int cnt = 0;
    for (int i=0; i<V_NUM; i++) if (parent[i] == 0) cnt++;
    if (cnt >= 2) is_artic[0] = 1;
    for (int i=1; i<V_NUM; i++) {
        if (prenum[parent[i]] <= lowest[i]) is_artic[i] = 1;
    }
}
