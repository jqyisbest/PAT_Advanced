#include "round_2_resolve1011.h"
using namespace round_2_resolve1011;
#include <bits/stdc++.h>
using namespace std;
int round_2_resolve1011::resolve()
{
	char types[3] = { 'W','T','L' };
	int max_j[3] = { -1 };
	double odds[3] = { 0.0 };
	for (int i = 0; i < 3; i++)
	{
		double max_odd = 0.0;
		for (int j = 0; j < 3; j++)
		{
			double odd = 0.0;
			scanf("%lf", &odd);
			if (odd > max_odd || j == 0)
			{
				max_odd = odd;
				max_j[i] = j;
			}
		}
		odds[i] = max_odd;
	}
	for (size_t i = 0; i < 3; i++)
	{
		printf("%c ", types[max_j[i]]);
	}
	printf("%.2lf", ((odds[0] * odds[1] * odds[2] * 0.65 - 1) * 2));
	return 0;
}