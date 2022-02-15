#include "round_2_resolve1009.h"
using namespace round_2_resolve1009;
#include <bits/stdc++.h>
using namespace std;
int round_2_resolve1009::resolve()
{
	int k1 = 0, k2 = 0, result_num = 0;
	double *result = new double[2001];
	fill(result, result + 2001, 0.0);
	map<int, double> polynominal;
	scanf("%d", &k1);
	for (size_t i = 0; i < k1; i++)
	{
		int n = 0;
		double a = 0.0;
		scanf(" %d %lf", &n, &a);
		polynominal[n] = a;
	}
	scanf("%d", &k2);
	for (size_t i = 0; i < k2; i++)
	{
		int n = 0;
		double a = 0.0;
		scanf(" %d %lf", &n, &a);
		for (map<int, double>::iterator it = polynominal.begin(); it != polynominal.end(); it++)
		{
			result[n + it->first] += a*it->second;
		}
	}
	for (size_t i = 0; i < 2001; i++)
	{
		if (result[i] != 0.0)
		{
			result_num++;
		}
	}
	printf("%d", result_num);
	for (int i = 2000; i >= 0; i--)
	{
		if (result[i] != 0.0)
		{
			printf(" %d %.1lf", i, result[i]);
		}
	}
	return 0;
}