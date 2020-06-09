#include "resolve1068.h"
/*
	��һ�γ��Զ�̬�滮����
	��������⣺n��Ӳ��������ѡ�����ܼ�m
	�˴��ܼ�m��ΪĿ��ֵ��Ϊ�����������൱��01�����е�������

*/
int resolve1068::resolve()
{
	int total_num_of_coin = 0, target_amount = 0;
	scanf("%d %d", &total_num_of_coin, &target_amount);
	bool **choose = new bool*[total_num_of_coin+1];
	int **dp = new int*[total_num_of_coin+1];
	for (size_t i = 0; i <= total_num_of_coin; i++)
	{
		dp[i] = new int[target_amount+1] {0};
		choose[i] = new bool[target_amount+1] {false};
	}
	vector<int> coins;
	for (size_t i = 0; i < total_num_of_coin; ++i)
	{
		int temp = 0;
		scanf("%d", &temp);
		//���˲������õ���Ӳ��
		if (temp <= target_amount)
		{
			coins.push_back(temp);
		}
	}
	total_num_of_coin = coins.size();
	sort(coins.begin(), coins.end(), cmp_coin);
	for (size_t i = 1; i <= total_num_of_coin; ++i)
	{
		int coin = coins[i-1];
		for (size_t j = 1; j <= target_amount; ++j)
		{
			if (coin > j)
			{
				//��ֵ���ڵ�ǰ��ʣ��������Ӳ�ҿ϶������㵱ǰ��Ҫ
				dp[i][j] = dp[i - 1][j];
			}
			else 
			{
				int val_choosed = dp[i - 1][j - coin] + coin;
				if (dp[i - 1][j] > val_choosed)
				{
					dp[i][j] = dp[i - 1][j];
				}
				else
				{
					dp[i][j] = val_choosed;
					choose[i][j] = true;
				}
			}
		}
	}
	if (dp[total_num_of_coin][target_amount]>=target_amount)
	{
		while (target_amount>0)
		{
			if (choose[total_num_of_coin--][target_amount])
			{
				target_amount -= coins[total_num_of_coin];
				printf("%d", coins[total_num_of_coin]);
				if (target_amount!=0)
				{
					printf(" ");
				}
			}
		}
	}
	else
	{
		printf("No Solution");
	}
	return 0;
}

bool resolve1068::cmp_coin(int c1, int c2)
{
	return c1 > c2;
}
