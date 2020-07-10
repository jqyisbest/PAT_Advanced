#include "resolve1079.h"
/*
    根据父子关系递归更新每个子节点的价格
    数组分配一定在变量输入之后！！！
*/
int resolve1079::resolve()
{
    int n = 0;
    double p = 0.0, r = 0.0;
    scanf("%d %lf %lf", &n, &p, &r);
    int *parent = new int[n];
    double *price = new double[n], total = 0.0;
    fill(price, price + n, 0.0);
    price[0] = p;
    parent[0] = 0;
    vector<int> retails;
    vector<int> retails_product_num;
    for (size_t i = 0; i < n; ++i)
    {
        int k = 0, u = 0;
        scanf("%d", &k);
        if (0 == k)
        {
            scanf("%d", &u);
            retails.push_back(i);
            retails_product_num.push_back(u);
        }
        else
        {
            for (size_t j = 0; j < k; ++j)
            {
                scanf("%d", &u);
                parent[u] = i;
            }
        }
    }
    //依据父子关系更新价格并计算总额
    for (size_t i = 0; i < retails.size(); ++i)
    {
        if (price[retails[i]] == 0)
        {
            update_price(retails[i], parent, price, r);
        }
        total += price[retails[i]] * retails_product_num[i];
    }
    printf("%.1f", total);
    return 0;
}
void resolve1079::update_price(const int u, const int *parent, double *price, const double r)
{
    if (price[parent[u]] == 0)
    {
        update_price(parent[u], parent, price, r);
    }
    price[u] = price[parent[u]] + price[parent[u]] * (r / 100.0);
}