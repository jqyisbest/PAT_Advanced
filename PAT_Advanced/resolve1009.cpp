#include "resolve1009.h"
#include "common.h"
int resolve1009::resolve()
{
	//����ϵ�������2001��
	double* coefficients_1 = new double[2001];
	fill(coefficients_1, coefficients_1 + 2001, 0);
	double* coefficients_result = new double[2001];
	fill(coefficients_result, coefficients_result + 2001, 0);
	int k1 = 0,k2=0;
	cin >> k1;
	//�����һ������ʽ��ϵ��
	for (int i = 0; i < k1; ++i)
	{
		//ÿһ���������ָ����ϵ��
		int n = 0;
		double an = 0;
		cin >> n >> an;
		coefficients_1[n] = an;
	}
	cin >> k2;
	//����ڶ�������ʽ��ϵ��
	for (int i = 0; i < k2; ++i)
	{
		//ÿһ���������ָ����ϵ��
		int n = 0;
		double an = 0;
		cin >> n >> an;
		//�ѳ��Եĵ�һ������ʽ������
		int num_has_multiple = 0;
		for (int j = 0; j < 2001&&num_has_multiple<k1; ++j)
		{
			if (coefficients_1[j]!=0)
			{
				/**
				�ҵ���һ������ʽ��һ�������ָ��Ϊj ϵ��Ϊcoefficients[j]
				�����ѭ����������ĵڶ�������ʽ�ķ��������
				*/

				//������ָ��=��һ������ʽ���ַ������ָ��+�ڶ�������ʽ��ǰ����ķ������ָ��
				int new_n = n + j;
				//������ϵ��=����ͬ�����ϵ��+��һ������ʽ���ַ������ϵ��*�ڶ�������ʽ��ǰ����ķ������ϵ��
				coefficients_result[new_n] = coefficients_result[new_n] + coefficients_1[j]*an;
				++num_has_multiple;
			}
		}
	}
	/*��ʱcoefficients_result�м�Ϊ�������ʽ�ĸ���ϵ��,ͳ�Ʒ�����������Ҫ�����*/
	int k_of_result = 0;
	for (int i = 0; i < 2001; ++i)
	{
		//ͳ�Ʒ�������
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
