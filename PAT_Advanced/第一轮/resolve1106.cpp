#include "resolve1106.h"

int resolve1106::resolve()
{
	int n = 0, min_nums = 0;
	double p = 0.0, r = 0.0, min_price = 0.0;
	scanf("%d %lf %lf", &n, &p, &r);
	int *parents = new int[n];
	double *price = new double[n];
	fill(parents, parents + n, -1);
	fill(price, price + n, 0.0);
	price[0] = p;
	vector<int>retails;
	for (int i = 0; i < n; ++i)
	{
		int k = 0;
		scanf("%d", &k);
		if (k == 0)
		{
			retails.push_back(i);
		}
		else
		{
			for (int j = 0; j < k; ++j)
			{
				int index = 0;
				scanf("%d", &index);
				parents[index] = i;
			}
		}
	}
	for (int i = 0; i < retails.size(); i++)
	{
		double price_i = get_price(retails[i], price, parents, r);
		if (price_i < min_price || min_price == 0.0)
		{
			min_price = price_i;
			min_nums = 1;
		}
		else if (price_i == min_price)
		{
			min_nums++;
		}
	}
	printf("%.4f %d", min_price, min_nums);
	return 0;
}

double resolve1106::get_price(int node, double * price, int * parents, const double r)
{
	if (price[node] == 0.0)
	{
		get_price(parents[node], price, parents, r);
		price[node] = price[parents[node]] + price[parents[node]] * r / 100.0;
	}
	return price[node];
}
