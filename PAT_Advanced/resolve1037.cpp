#include "resolve1037.h"

/*
	本来还有些担心longlong不够的，还是过了╮(╯▽╰)╭
	要是不能用数字类型表示，这题会更难一些
*/
int resolve1037::resolve()
{
	//统计产品和优惠券的正数负数个数
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
	//对两个数列从小到大排序 
	sort(coupons.begin(), coupons.end());
	sort(products.begin(), products.end());
	//排序之后 将coupon和product的两端负数相乘+两端正数相乘得到max 剩下的不管了，没说每张券一定要用
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