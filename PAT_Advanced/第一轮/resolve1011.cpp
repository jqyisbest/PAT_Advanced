#include "resolve1011.h"
int resolve1011::resolve()
{
	const char* bet_strs = new char[3]{ 'W','T','L' };
	char* bet_strs_choose = new char[3];
	double* maxs =new double[3];
	fill(maxs, maxs + 3, -1);
	double bet_coef = 1.0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			double bet_rate = 0.0;
			cin >> bet_rate;
			if (maxs[i]<bet_rate)
			{
				bet_strs_choose[i] = bet_strs[j];
				maxs[i] = bet_rate;
			}
		}
		
		bet_coef *= maxs[i];
	}
	for (int i = 0; i < 3; i++)
	{
		cout << bet_strs_choose[i] << " ";
	}
	cout << fixed << setprecision(2) << (bet_coef*0.65 - 1.0) * 2;
	return 0;
}
