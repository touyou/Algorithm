/**
 * http://www.moon.sannet.ne.jp/okahisa/haskell-sort/t23-java.html
 * のC翻訳
 */

typedef struct Node {
    // 2: 2分岐、3:３分岐、-2:挿入時アクティブ、-1:削除時アクティブ
    int nways;
    int e1, e2;
    Node *lst, *mst, *rst;
} Node;

Node *new_node(int e) {
    Node *new = malloc(sizeof(Node));
    new->nways = -2;
    new->e1 = e;
    new->lst = NULL;
    new->mst = NULL;
    new->rst = NULL;
    return new;
}

int active(Node *t) {
    return t != NULL && t->nways < 0;
}

Node *insert(Node *t, int e) {
    if (t == NULL) return new_node(e);
    switch (t->nways) {
        case 2:
            if (e < t->e1) {
                t->lst = insert(t->lst, e);
                return balance2Li(t);
            } else if (e > t->e1) {
                t->rst = insert(t->rst, e);
                return balance2Ri(t);
            } else return t;
        case 3:
            if (e < t->e1) {
                t->lst = insert(t->lst, e);
                return balance3Li(t);
            } else if (e == t->e1) {
                return t;
            } else if (e < t->e2) {
                t->mst = insert(t->mst, e);
                return balance3Mi(t);
            } else if (e == t->e2) {
                return t;
            } else {
                t->rst = insert(t->rst, e);
                return balance3Ri(t);
            }
        default:
            break;
    }
    return NULL;
}

// バランス調整（挿入時）
