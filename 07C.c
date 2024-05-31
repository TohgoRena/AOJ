#include <stdio.h>
#include <stdlib.h>

// ノード構造体の定義
typedef struct Node
{
    int parent; // 親ノードのID
    int left;   // 左の子ノードのID
    int right;  // 右の子ノードのID
    int depth;  // ノードの深さ
    int height; // ノードの高さ
    int type;   // ノードの種類（0: leaf, 1: internal node, 2: root）
} Node;

// 初期化関数
void initialize_node(Node *node)
{
    node->parent = -1;
    node->left = -1;
    node->right = -1;
    node->depth = -1;
    node->height = -1;
    node->type = 0; // 初期値として leaf を設定
}

// 深さと親を設定する再帰関数
void set_depths_and_parents(Node *nodes, int node_id, int depth)
{
    nodes[node_id].depth = depth; // 現在のノードの深さを設定

    // 左右の子ノードに対して再帰的に深さと親を設定
    if (nodes[node_id].left != -1)
    {
        nodes[nodes[node_id].left].parent = node_id;
        set_depths_and_parents(nodes, nodes[node_id].left, depth + 1);
    }
    if (nodes[node_id].right != -1)
    {
        nodes[nodes[node_id].right].parent = node_id;
        set_depths_and_parents(nodes, nodes[node_id].right, depth + 1);
    }
}

// 高さを計算する再帰関数
int calculate_height(Node *nodes, int node_id)
{
    int left_height = 0, right_height = 0;

    // 左右の子ノードの高さを計算
    if (nodes[node_id].left != -1)
    {
        left_height = calculate_height(nodes, nodes[node_id].left) + 1;
    }
    if (nodes[node_id].right != -1)
    {
        right_height = calculate_height(nodes, nodes[node_id].right) + 1;
    }

    // 高い方の高さを返す
    return (left_height > right_height) ? left_height : right_height;
}

void pre_parse(Node *node, int root)
{
    if (root == -1)
    {
        return;
    }
    printf(" %d", root);
    pre_parse(node, node[root].left);
    pre_parse(node, node[root].right);
}

void in_parse(Node *node, int root)
{
    if (root == -1)
    {
        return;
    }
    in_parse(node, node[root].left);
    printf(" %d", root);
    in_parse(node, node[root].right);
}

void post_parse(Node *node, int root)
{
    if (root == -1)
    {
        return;
    }
    post_parse(node, node[root].left);
    post_parse(node, node[root].right);
    printf(" %d", root);
}

int main()
{
    int n;
    // ノード数を読み取る
    scanf("%d", &n);

    // ノード配列を動的に確保
    Node *nodes = (Node *)malloc(n * sizeof(Node));

    // 初期化
    for (int i = 0; i < n; i++)
    {
        initialize_node(&nodes[i]);
    }

    // 各ノードの情報を読み取る
    for (int i = 0; i < n; i++)
    {
        int id, left, right;
        scanf("%d %d %d", &id, &left, &right);
        nodes[id].left = left;
        nodes[id].right = right;
        if (left != -1)
        {
            nodes[left].parent = id;
        }
        if (right != -1)
        {
            nodes[right].parent = id;
        }
    }

    // 根を特定（親が -1 のノード）
    int root = 0;
    for (int i = 0; i < n; i++)
    {
        if (nodes[i].parent == -1)
        {
            root = i;
            break;
        }
    }

    // 深さと親を初期化
    set_depths_and_parents(nodes, root, 0);

    // 高さを計算
    for (int i = 0; i < n; i++)
    {
        nodes[i].height = calculate_height(nodes, i);
    }

    // 節点の種類を設定
    for (int i = 0; i < n; i++)
    {
        if (nodes[i].parent == -1)
        {
            nodes[i].type = 2; // root
        }
        else if (nodes[i].left == -1 && nodes[i].right == -1)
        {
            nodes[i].type = 0; // leaf
        }
        else
        {
            nodes[i].type = 1; // internal node
        }
    }

    printf("Preorder\n");
    pre_parse(nodes, root);
    printf("\n");

    printf("Inorder\n");
    in_parse(nodes, root);
    printf("\n");

    printf("Postorder\n");
    post_parse(nodes, root);
    printf("\n");

    // ノード配列を解放
    free(nodes);

    return 0;
}
