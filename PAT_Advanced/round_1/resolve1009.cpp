#include "resolve1009.h"
#include "common.h"
int resolve1009::resolve()
{
	//各阶系数，最高2001次
	double* coefficients_1 = new double[2001];
	fill(coefficients_1, coefficients_1 + 2001, 0);
	double* coefficients_result = new double[2001];
	fill(coefficients_result, coefficients_result + 2001, 0);
	int k1 = 0,k2=0;
	cin >> k1;
	//输入第一个多项式的系数
	for (int i = 0; i < k1; ++i)
	{
		//每一个非零项的指数、系数
		int n = 0;
		double an = 0;
		cin >> n >> an;
		coefficients_1[n] = an;
	}
	cin >> k2;
	//输入第二个多项式的系数
	for (int i = 0; i < k2; ++i)
	{
		//每一个非零项的指数、系数
		int n = 0;
		double an = 0;
		cin >> n >> an;
		//已乘以的第一个多项式的项数
		int num_has_multiple = 0;
		for (int j = 0; j < 2001&&num_has_multiple<k1; ++j)
		{
			if (coefficients_1[j]!=0)
			{
				/**
				找到第一个多项式的一个非零项，指数为j 系数为coefficients[j]
				和外层循环正在输入的第二个多项式的非零项相乘
				*/

				//结果项的指数=第一个多项式本轮非零项的指数+第二个多项式当前输入的非零项的指数
				int new_n = n + j;
				//结果项的系数=其余同类项的系数+第一个多项式本轮非零项的系数*第二个多项式当前输入的非零项的系数
				coefficients_result[new_n] = coefficients_result[new_n] + coefficients_1[j]*an;
				++num_has_multiple;
			}
		}
	}
	/*此时coefficients_result中即为结果多项式的各项系数,统计非零项数并按要求输出*/
	int k_of_result = 0;
	for (int i = 0; i < 2001; ++i)
	{
		//统计非零项数
		if (coefficients_result[i] != 0) {
			++k_of_result;
		}
	}
	cout << k_of_result;
	for (int i = 2000; k_of_result>0&&i >=0 ; --i)
	{
		if (coefficients_result[i]!=0) {
			cout << " " << i << " " << fixed << setprecision(1) << coefficients_result[i];
			--k_of_result;
		}
	}
	return 0;
}
