#include "resolve1048.h"
/*
	��Ӳ����ֵ���룬˫ָ�����ͷ���м���Ѱ
		1������ָ��Ϊ�����ҵ���һ������Ľ��������
		2������ָ��>��ָ�룬���ж���һ����ֵ
		3������ָ��==��ָ�룬���ж��Ƿ���������ǰ��ֵ��Ӳ������Ҫ��
		4�����ҵ���������������
	��Ѱ��������No Solution

	nice,21ms
	0
	����ȷ
	3 ms	356 KB
	1
	����ȷ
	3 ms	376 KB
	2
	����ȷ
	3 ms	368 KB
	3
	����ȷ
	21 ms	384 KB
	4
	����ȷ
	20 ms	508 KB
	5
	����ȷ
	3 ms	404 KB
	6
	����ȷ
	3 ms	384 KB

	ͻȻ������Ŀ����û˵Ӳ����ֵһ������������������= =
*/
int resolve1048::resolve()
{
	int num_of_coin = 0, amount_to_pay, max_coin = 0, temp = 0;
	scanf("%d %d", &num_of_coin, &amount_to_pay);
	//��������Ӳ�� ����ȡ�����ֻ��С��Ҫ��������Ӳ�Ҳ��п�������Ҫ��
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
