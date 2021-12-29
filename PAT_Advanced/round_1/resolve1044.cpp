#include "resolve1044.h"
/*
	������� ��������ۼӣ�����ۼ��ܶ���������ܶ����ۼ��ܶ���С�ļ�Ϊ�������
	���Ե�0�޷�ͨ��==��֪��Ϊɶ��
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
	//���Ը�Ǯ��
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
	//�ж��´δ��Ŀ�ʼ�ۼ�
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

	תΪ���ֲ��Ұ�

	���������ҵ������ˡ�
	�������ڣ����ҵ�����һ���Ӵ�������Ӵ������Ž�ʱ��óȻ��������һ��������������������֣������©��
	�ٸ����ӣ�16 15
	3 2 1 5 4 6 8 7 16 10 15 11 9 12 14 13
	687Ϊ�ɸ����һ���Ӵ������䲢�Ǹ��Ӵ������Ž⣬�ڸ��Ӵ��л�������78�����ĸ��Ž�
	��óȻ��Ϊ687�Ӵ��е����ֿ�������������©��78��һ�����Ž�
	ע���еİ汾Ҳע�⵽����һ���󣬵���ʶ�����ȡ�˴��������Դ�������ǰ����һλ��index_left = j - 1;������if (index_left_temp == index_left + 1)�������
	���ִ�����Ƭ��ģ������ַ������Ӵ�6717����������16�أ���ʱӦ������λ�������������ķ������Ӵ��أ�
	��������ͨ���ж��Ӵ��е���Сֵ�Ƿ�����Ӵ���Ŀ���ܶ�Ĳ�ֵ���ж��Ƿ�Ϊ�����Ӵ�
	���Ӵ���Ŀ���ܶ�����ֵ���ڻ������Сֵ��˵�����Ӵ�����ͨ��ȥ����Сֵ�ķ�ʽ��ȡ�ø��Ž⣬�����Ӵ��������Ӵ������������Ծ����©�⣬����ʵʵ++i
	���Ӵ���Ŀ���ܶ�����ֵС����Сֵ��˵�����Ӵ��е���һ����ȱһ���ɣ����Ӵ�Ϊ���Ž⣬��ʱ���������Ծ����©��

	��˵�Ǳ�����٣�ʱ��Ҳ���ǹ��ˣ�����ͨ˫ѭ����پͻᳬʱ�r(�s���t)�q
	0
	����ȷ
	2 ms	448 KB
	1
	����ȷ
	2 ms	356 KB
	2
	����ȷ
	20 ms	1408 KB
	3
	����ȷ
	201 ms	5232 KB
	4
	����ȷ
	4 ms	380 KB
	5
	����ȷ
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
			//���Ը�Ǯ��
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
				//�ж��´δ��Ŀ�ʼ�ۼ�
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