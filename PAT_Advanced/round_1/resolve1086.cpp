#include "resolve1086.h"
/*
    ��������������еõ���
    �ȸ��ݲ������еõ���
        popA�����pushB��B��A���Һ���
        pushA�����pushB��B��A������
    ��д����������
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
    //���ݲ����������������
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
                //���ϸ��ڵ������
                nodes[last_data]->left = tree_node;
            }
            else if (last_op == 'o')
            {
                //���ϸ��ڵ���Һ���
                nodes[last_data]->right = tree_node;
            }
            else if (root == nullptr)
            {
                //���ڵ�
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
    //������� ������д�ǵݹ�ģ����ųԷ����ǵݹ��������
    postOrder(root, stack);
    //������n
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