#include <stdio.h>
#include <stdlib.h>

// ノード構造体の定義
typedef struct Node {
    int parent;         // 親ノードのID
    int depth;          // ノードの深さ
    int *children;      // 子ノードのリスト
    int num_children;   // 子ノードの数
    int max_children;   // 現在確保している子ノードリストの最大容量
} Node;

// 初期化関数
void initialize_node(Node *node) {
    node->parent = -1;
    node->depth = -1;
    node->num_children = 0;
    node->max_children = 0;
    node->children = NULL;
}

// 深さと親を設定する再帰関数
void set_depths_and_parents(Node *nodes, int node_id, int depth) {
    nodes[node_id].depth = depth;   // 現在のノードの深さを設定
    // 子ノードに対して再帰的に深さと親を設定
    for (int i = 0; i < nodes[node_id].num_children; i++) {
        int child_id = nodes[node_id].children[i];
        nodes[child_id].parent = node_id; // 子ノードの親を設定
        set_depths_and_parents(nodes, child_id, depth + 1); // 再帰呼び出し
    }
}

int main() {
    int n;
    // ノード数を読み取る
    scanf("%d", &n);
    
    // ノード配列を動的に確保
    Node *nodes = (Node *)malloc(n * sizeof(Node));
    
    // 初期化
    for (int i = 0; i < n; i++) {
        initialize_node(&nodes[i]);
    }

    // 各ノードの情報を読み取る
    for (int i = 0; i < n; i++) {
        int id, k;
        scanf("%d %d", &id, &k);
        nodes[id].num_children = k; // 子ノード数を設定
        if (k > 0) {
            nodes[id].children = (int *)malloc(k * sizeof(int)); // 子ノードリストを動的に確保
            nodes[id].max_children = k; // 現在の子ノードリストの最大容量を設定
            for (int j = 0; j < k; j++) {
                int child_id;
                scanf("%d", &child_id);
                nodes[id].children[j] = child_id; // 子ノードのIDを設定
                nodes[child_id].parent = id;     // 子ノードの親を設定
            }
        }
    }

    // 根を特定（親が -1 のノード）
    int root = 0;
    for (int i = 0; i < n; i++) {
        if (nodes[i].parent == -1) {
            root = i;
            break;
        }
    }

    // 深さと親を初期化
    set_depths_and_parents(nodes, root, 0);

    // 各ノードの情報を出力
    for (int i = 0; i < n; i++) {
        printf("node %d: parent = %d, depth = %d, ", i, nodes[i].parent, nodes[i].depth);
        if (nodes[i].parent == -1) {
            printf("root, ");
        } else if (nodes[i].num_children == 0) {
            printf("leaf, ");
        } else {
            printf("internal node, ");
        }
        printf("[");
        for (int j = 0; j < nodes[i].num_children; j++) {
            if (j > 0) {
                printf(", ");
            }
            printf("%d", nodes[i].children[j]);
        }
        printf("]\n");
    }

    // 各ノードの子ノードリストを解放
    for (int i = 0; i < n; i++) {
        if (nodes[i].children != NULL) {
            free(nodes[i].children);
        }
    }

    // ノード配列を解放
    free(nodes);

    return 0;
}
