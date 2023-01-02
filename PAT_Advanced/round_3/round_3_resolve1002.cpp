#include "round_3_resolve1002.h"

int round_3_resolve1002::resolve()
{
	double coefficients[1001];
	fill(coefficients, coefficients + 1001, 0.0);
	int k = 0;
	for (size_t i = 0; i < 2; i++)
	{
		scanf("%d", &k);
		for (size_t j = 0; j < k; j++)
		{
			int n = 0;
			double an = 0.0;
			scanf("%d %lf", &n, &an);
			coefficients[n] += an;
		}
	}
	k = 0;
	vector<int>ns;
	vector<double>ans;
	for (int i = 1000; i >=0; --i)
	{
		if (coefficients[i] != 0.0)
		{
			ns.push_back(i);
			ans.push_back(coefficients[i]);
			k++;
		}
	}
	printf("%d", k);
	for (size_t i = 0; i < k; i++)
	{
		printf(" %d %.1lf", ns[i], ans[i]);
	}
	return 0;
}
