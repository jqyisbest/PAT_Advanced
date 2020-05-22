#include "resolve1037.h"

/*
	��������Щ����longlong�����ģ����ǹ��˨r(�s���t)�q
	Ҫ�ǲ������������ͱ�ʾ����������һЩ
*/
int resolve1037::resolve()
{
	//ͳ�Ʋ�Ʒ���Ż�ȯ��������������
	size_t num_of_product = 0, num_of_coupon = 0, positive_product_num = 0, positive_coupon_num = 0, negative_product_num = 0, negative_coupon_num = 0;
	vector<int> coupons;
	vector<int> products;
	int temp;
	cin >> num_of_coupon;
	for (size_t i = 0; i < num_of_coupon; ++i)
	{
		scanf("%d", &temp);
		if (temp > 0)
		{
			++positive_coupon_num;
		}
		else if (temp < 0)
		{
			++negative_coupon_num;
		}
		coupons.push_back(temp);
	}
	cin >> num_of_product;
	for (size_t i = 0; i < num_of_product; ++i)
	{
		scanf("%d", &temp);
		if (temp > 0)
		{
			++positive_product_num;
		}
		else if (temp < 0)
		{
			++negative_product_num;
		}
		products.push_back(temp);
	}
	//���������д�С�������� 
	sort(coupons.begin(), coupons.end());
	sort(products.begin(), products.end());
	//����֮�� ��coupon��product�����˸������+����������˵õ�max ʣ�µĲ����ˣ�û˵ÿ��ȯһ��Ҫ��
	long long max = 0;
	int min_negative_num = negative_product_num < negative_coupon_num ? negative_product_num : negative_coupon_num;
	for (size_t i = 0; i < min_negative_num; ++i)
	{
		max += coupons[i] * products[i];
	}
	int min_positive_num = positive_product_num < positive_coupon_num ? positive_product_num : positive_coupon_num;
	for (size_t i = 0; i < min_positive_num; ++i)
	{
		max += coupons[num_of_coupon - i - 1] * products[num_of_product - i - 1];
	}
	cout << max;
	return 0;
}