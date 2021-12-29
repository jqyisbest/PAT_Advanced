#include "resolve1044.h"
/*
	从左边起 挨个向后累加，求得累计总额大于所需总额且累计总额最小的即为解决方案
	测试点0无法通过==不知道为啥。
	int num_of_diamonds = 0, amount_to_pay = 0, index_left = 1, current_amount = 0, min_cost = -1;
	scanf("%d %d", &num_of_diamonds, &amount_to_pay);
	vector<string> result;
	int *diamonds = new int[num_of_diamonds + 1];
	diamonds[0] = 0;
	int *amount_hitherto = new int[num_of_diamonds + 1];
	fill(amount_hitherto, amount_hitherto + num_of_diamonds + 1, 0);
	for (int i = 1; i <= num_of_diamonds; ++i)
	{
	scanf("%d", &diamonds[i]);
	}
	for (int i = 1; i <= num_of_diamonds; ++i)
	{
	current_amount += diamonds[i];
	amount_hitherto[i] = amount_hitherto[i - 1] + diamonds[i];
	if (current_amount >= amount_to_pay)
	{
	//可以付钱了
	if (current_amount < min_cost)
	{
	min_cost = current_amount;
	result.clear();
	result.push_back(to_string(index_left) + "-" + to_string(i));
	}
	else if (current_amount == min_cost)
	{
	result.push_back(to_string(index_left) + "-" + to_string(i));
	}
	else if (min_cost == -1)
	{
	min_cost = current_amount;
	result.push_back(to_string(index_left) + "-" + to_string(i));
	}
	//判断下次从哪开始累加
	int index_left_temp = index_left, index_right_temp = i;
	for (int j = index_left; j <= i; ++j)
	{
	if (amount_hitherto[j] > diamonds[i + 1])
	{
	index_left = j - 1;
	i = index_left - 1;
	break;
	}
	}
	if (index_left_temp == index_left)
	{
	++index_left;
	++i;
	}
	else if (index_left_temp == index_left + 1)
	{
	index_left += 2;
	i += 2;
	}
	current_amount = 0;
	fill(amount_hitherto + index_left_temp, amount_hitherto + index_right_temp, 0);
	}
	}
	for (size_t i = 0; i < result.size() - 1; i++)
	{
	cout << result[i] << endl;
	}
	cout << result[result.size() - 1];
	return 0;

	转为二分查找吧

	嘻嘻嘻，找到问题了。
	问题在于，当找到的这一个子串非最该子串的最优解时，贸然跳过被下一个输入数字替代掉的数字，会造成漏解
	举个例子，16 15
	3 2 1 5 4 6 8 7 16 10 15 11 9 12 14 13
	687为可付款的一组子串，但其并非该子串的最优解，在该子串中还包含着78这样的更优解
	若贸然认为687子串中的数字可随意跳过，会漏掉78这一组最优解
	注释中的版本也注意到了这一现象，但认识不深，采取了错误的针对性处理（即往前回退一位：index_left = j - 1;并增添if (index_left_temp == index_left + 1)的情况）
	这种处理是片面的，若出现非最优子串6717、后续数字16呢（此时应回退两位）等其它更长的非最优子串呢？
	现在我们通过判断子串中的最小值是否大于子串和目标总额的差值来判断是否为最优子串
	若子串和目标总额相差的值大于或等于最小值，说明该子串可以通过去除最小值的方式来取得更优解，即该子串非最优子串，进行替代跳跃可能漏解，老老实实++i
	若子串和目标总额相差的值小于最小值，说明该子串中的任一数字缺一不可，该子串为最优解，此时进行替代跳跃不会漏解

	虽说是暴力穷举，时间也还是过了，但普通双循环穷举就会超时╮(╯▽╰)╭
	0
	答案正确
	2 ms	448 KB
	1
	答案正确
	2 ms	356 KB
	2
	答案正确
	20 ms	1408 KB
	3
	答案正确
	201 ms	5232 KB
	4
	答案正确
	4 ms	380 KB
	5
	答案正确
	26 ms	1408 KB
*/
int resolve1044::resolve()
{
	int num_of_diamonds = 0, amount_to_pay = 0, index_left = 1, current_amount = 0, min_value = 0, min_cost = -1;
	scanf("%d %d", &num_of_diamonds, &amount_to_pay);
	vector<string> result;
	int *diamonds = new int[num_of_diamonds + 1];
	diamonds[0] = 0;
	vector<int> amount_hitherto;
	for (int i = 1; i <= num_of_diamonds; ++i)
	{
		scanf("%d", &diamonds[i]);
	}
	for (int i = 1; i <= num_of_diamonds; )
	{
		current_amount += diamonds[i];
		if (diamonds[i] < min_value || 0 == min_value)
		{
			min_value = diamonds[i];
		}
		amount_hitherto.push_back(current_amount);
		if (current_amount >= amount_to_pay)
		{
			//可以付钱了
			if (current_amount < min_cost)
			{
				min_cost = current_amount;
				result.clear();
				result.push_back(to_string(index_left) + "-" + to_string(i));
			}
			else if (current_amount == min_cost)
			{
				result.push_back(to_string(index_left) + "-" + to_string(i));
			}
			else if (min_cost == -1)
			{
				min_cost = current_amount;
				result.push_back(to_string(index_left) + "-" + to_string(i));
			}
			int index_jump = 1;
			if ((current_amount - amount_to_pay) < min_value)
			{
				//判断下次从哪开始累加
				for (int j = 1; j < amount_hitherto.size(); ++j)
				{
					if (amount_hitherto[j] > diamonds[i + 1])
					{
						index_jump = j;
						break;
					}
				}
			}
			i = index_left += index_jump;
			min_value = 0;
			current_amount = 0;
			amount_hitherto.clear();
		}
		else
		{
			++i;
		}
	}
	for (size_t i = 0; i < result.size() - 1; i++)
	{
		cout << result[i] << endl;
	}
	cout << result[result.size() - 1];
	return 0;
}