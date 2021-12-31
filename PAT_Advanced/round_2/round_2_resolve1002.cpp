#include "round_2_resolve1002.h"
using namespace round_2_resolve1002;
#include <bits/stdc++.h>
using namespace std;
int round_2_resolve1002::resolve()
{
	int total_item = 0;
	double *a = new double[1001]{ 0.0 };
	for (size_t i = 0; i < 2; i++)
	{
		int k = 0, ej = 0;
		double aj = 0.0;
		scanf("%d", &k);
		for (size_t j = 0; j < k; j++)
		{
			scanf(" %d %lf", &ej, &aj);
			double aj_before = a[ej];
			a[ej] += aj;
			if (aj_before != 0 && a[ej] == 0)
			{
				total_item--;
			}
			else if (aj_before == 0 && a[ej] != 0)
			{
				total_item++;
			}
		}
	}
	printf("%d", total_item);
	for (int i = 1000; i >= 0; i--)
	{
		if (a[i] != 0)
		{
			printf(" %d %.1lf", i, a[i]);
		}
	}
	return 0;
}