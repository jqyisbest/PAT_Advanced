#include "common.h"
namespace resolve1086
{
    int resolve();
    typedef struct node
    {
        int data;
        node *left;
        node *right;
        node()
        {
            this->left = nullptr;
            this->right = nullptr;
        }
    } node;
    void postOrder(node *root, vector<int> &result);
} // namespace resolve1086