#include "resolve1086.h"
/*
    根据中序操作序列得到树
    先根据操作序列得到树
        popA后跟着pushB：B是A的右孩子
        pushA后跟着pushB：B是A的左孩子
    再写出后续序列
*/
int resolve1086::resolve()
{
    int n = 0;
    scanf("%d\n", &n);
    vector<int> stack;
    node *root = nullptr;
    char last_op = ' ';
    int last_data = 0;
    map<int, node *> nodes;
    //根据操作序列生成这棵树
    for (size_t i = 0; i < 2 * n; ++i)
    {
        char ops[5];
        int data = 0;
        scanf("%s", ops);
        if (ops[1] == 'u')
        {
            scanf("%d", &data);
            stack.push_back(data);
            node *tree_node = new node();
            tree_node->data = data;
            nodes[data] = tree_node;
            if (last_op == 'u')
            {
                //是上个节点的左孩子
                nodes[last_data]->left = tree_node;
            }
            else if (last_op == 'o')
            {
                //是上个节点的右孩子
                nodes[last_data]->right = tree_node;
            }
            else if (root == nullptr)
            {
                //根节点
                root = tree_node;
            }
            last_data = data;
        }
        else
        {
            last_data = stack.back();
            stack.pop_back();
        }
        last_op = ops[1];
    }
    //后根遍历 本来想写非递归的，急着吃饭还是递归吧嘻嘻嘻
    postOrder(root, stack);
    //输出结果n
    for (size_t i = 0; i < n; ++i)
    {
        if (0 != i)
        {
            printf(" ");
        }
        printf("%d", stack[i]);
    }
    return 0;
}
void resolve1086::postOrder(node *root, vector<int> &result)
{
    if (nullptr != root)
    {
        postOrder(root->left, result);
        postOrder(root->right, result);
        result.push_back(root->data);
    }
}