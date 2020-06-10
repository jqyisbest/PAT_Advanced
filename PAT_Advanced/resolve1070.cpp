#include "resolve1070.h"
/*
	贪心即可，注意和01背包区分
*/
int resolve1070::resolve()
{
	int kinds_of_mooncakes = 0, maximum_total_demand = 0, temp = 0;
	double result = 0.0;
	scanf("%d %d", &kinds_of_mooncakes, &maximum_total_demand);
	vector<mooncake*> mooncakes;
	for (size_t i = 0; i < kinds_of_mooncakes; ++i)
	{
		mooncake* cake = new mooncake();
		scanf("%lf", &(cake->amount));
		mooncakes.push_back(cake);
	}
	for (size_t i = 0; i < kinds_of_mooncakes; ++i)
	{
		scanf("%lf", &(mooncakes[i]->value));
		mooncakes[i]->average = mooncakes[i]->value / mooncakes[i]->amount;
	}
	sort(mooncakes.begin(), mooncakes.end(), cmp_cake);
	while (maximum_total_demand > 0 && temp < kinds_of_mooncakes)
	{
		if (maximum_total_demand < mooncakes[temp]->amount)
		{
			//要不了那么多
			result += maximum_total_demand*mooncakes[temp]->average;
			maximum_total_demand = 0;
		}
		else
		{
			result += mooncakes[temp]->value;
			maximum_total_demand -= mooncakes[temp]->amount;
		}
		++temp;
	}
	printf("%.2f", result);
	return 0;
}

bool resolve1070::cmp_cake(mooncake * m1, mooncake * m2)
{
	return m1->average > m2->average;
}
