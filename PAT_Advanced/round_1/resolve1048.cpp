#include "resolve1048.h"
/*
	按硬币面值输入，双指针从两头向中间搜寻
		1、以左指针为主，找到第一个满足的结果即返回
		2、若左指针>右指针，则判断下一个面值
		3、若左指针==右指针，则判断是否有两个当前面值的硬币满足要求
		4、若找到结果则输出并返回
	搜寻结束返回No Solution

	nice,21ms
	0
	答案正确
	3 ms	356 KB
	1
	答案正确
	3 ms	376 KB
	2
	答案正确
	3 ms	368 KB
	3
	答案正确
	21 ms	384 KB
	4
	答案正确
	20 ms	508 KB
	5
	答案正确
	3 ms	404 KB
	6
	答案正确
	3 ms	384 KB

	突然发现题目好像没说硬币面值一定是整数。。凑巧了= =
*/
int resolve1048::resolve()
{
	int num_of_coin = 0, amount_to_pay, max_coin = 0, temp = 0;
	scanf("%d %d", &num_of_coin, &amount_to_pay);
	//各种面额的硬币 不用取得最大，只有小于要付款面额的硬币才有可能满足要求
	max_coin = 500 > amount_to_pay ? amount_to_pay : 500;
	int *coins = new int[max_coin + 1];
	fill(coins, coins + max_coin + 1, 0);
	for (size_t i = 0; i < num_of_coin; ++i)
	{
		scanf("%d", &temp);
		if (temp <= max_coin)
		{
			coins[temp]++;
		}
	}
	for (size_t coin = 1; coin <= max_coin; ++coin)
	{
		if (coins[coin] > 0)
		{
			if (2 * coin == amount_to_pay&&coins[coin] > 1)
			{
				printf("%d %d", coin, coin);
				return 0;
			}
			size_t another_coin = max_coin;
			while (another_coin > coin&& another_coin + coin >= amount_to_pay)
			{
				if (coins[another_coin] > 0 && another_coin + coin == amount_to_pay)
				{
					printf("%d %d", coin, another_coin);
					return 0;
				}
				--another_coin;
			}
		}
	}
	printf("No Solution");
	return 0;
}
