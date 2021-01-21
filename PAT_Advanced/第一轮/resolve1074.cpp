#include "resolve1074.h"
/*
	单链表转置
    利用栈进行转置
*/
int resolve1074::resolve()
{
    string start_add;
    start_add.resize(6);
    int node_num = 0, k = 0;
    scanf("%s %d %d", &start_add[0], &node_num, &k);
    map<string, node *> original_node;
    for (size_t i = 0; i < node_num; ++i)
    {
        string add_temp1, add_temp2;
        add_temp1.resize(6);
        add_temp2.resize(6);
        node *n = new node();
        scanf("%s %d %s", &add_temp1[0], &n->data, &add_temp2[0]);
        n->add = add_temp1;
        n->next_add = add_temp2;
        original_node[add_temp1] = n;
    }
    //转置开始
    //栈
    vector<node *> cache;
    int node_i = 1;
    node *current_node = original_node[start_add];
    while (true)
    {
        cache.insert(cache.begin(), current_node);
        if (node_i++ % k == 0)
        {
            //逆序输出
            for (size_t j = 0; j < cache.size(); ++j)
            {
                if (node_i == (k + 1) && j == 0)
                {
                    printf("%s %d ", current_node->add.c_str(), current_node->data);
                }
                else
                {
                    print_node(cache[j]);
                }
            }
            cache.clear();
        }
        if (strlen(current_node->next_add.c_str()) != 2)
        {
            current_node = original_node[current_node->next_add];
        }
        else
        {
            break;
        }
    }
    //原样打印剩余的
    if (cache.size() != 0)
    {
        for (int i = cache.size() - 1; i >= 0; --i)
        {
            print_node(cache[i]);
        }
    }
    printf("-1");
    return 0;
}

void resolve1074::print_node(node *n)
{
    printf("%s\n%s %d ", n->add.c_str(), n->add.c_str(), n->data);
}