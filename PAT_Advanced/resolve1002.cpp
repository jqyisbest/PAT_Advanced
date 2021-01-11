#include "resolve1002.h"
/*
	ע���ۼӺ�0���ȥ��
*/
int resolve1002::resolve()
{
	int total_item = 0;
	vector<bool> exponents(1001, false);
	vector<double> coefficients(1001, 0.0);
	for (size_t i = 0; i < 2; i++)
	{
		int k = 0;
		cin >> k;
		for (size_t j = 0; j < k; j++)
		{
			int e = 0;
			double c = 0.0;
			cin >> e >> c;
			if (!exponents[e])
			{
				total_item++;
				exponents[e] = true;
			}
			coefficients[e] += c;
			if (coefficients[e] == 0)
			{
				total_item--;
			}
		}
	}
	printf("%d", total_item);
	for (int i = 1000; i >= 0; --i)
	{
		if (exponents[i] && coefficients[i] != 0)
		{
			printf(" %d %.1f", i, coefficients[i]);
		}
	}
	return 0;
}