#include "resolve1090.h"
int resolve1090::resolve()
{
    int n = 0, highest_num = 0, root = 0;
    double p = 0.0, r = 0.0, highest_p = 0.0;
    scanf("%d %lf %lf", &n, &p, &r);
    vector<int> *childs = new vector<int>[n];
    vector<double> price(n);
    for (size_t i = 0; i < n; ++i)
    {
        //输入供应商信息
        int supplier_index = 0;
        scanf("%d", &supplier_index);
        if (-1 == supplier_index)
        {
            root = i;
        }
        else
        {
            childs[supplier_index].push_back(i);
        }
    }
    price[root] = p;
    update_child_price(root, childs, price, r);
    for (size_t i = 0; i < n; ++i)
    {
        if (price[i] > highest_p)
        {
            highest_p = price[i];
            highest_num = 1;
        }
        else if (price[i] == highest_p)
        {
            highest_num++;
        }
    }
    printf("%.2f %d", highest_p, highest_num);
    return 0;
}
void resolve1090::update_child_price(int current, vector<int> *childs, vector<double> &price, const double r)
{
    for (size_t i = 0; i < childs[current].size(); ++i)
    {
        price[childs[current][i]] = price[current] + price[current] * r / 100.0;
        update_child_price(childs[current][i], childs, price, r);
    }
}