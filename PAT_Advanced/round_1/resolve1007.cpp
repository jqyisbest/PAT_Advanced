#include "resolve1007.h"
#include "common.h"
int resolve1007::resolve()
{
	int total_num = 0;
	cin >> total_num;
	//全部数字序列
	int* num_array = new int[total_num];
	//每一个非负数的索引，结果中的i是其中之一
	int* every_positive_start_array_index = new int[total_num];
	fill(every_positive_start_array_index, every_positive_start_array_index + total_num, -1);
	//判断是否有非负数
	bool has_non_negative = false;
	//最小的数
	int min_num = 0;
	for (int i = 0; i < total_num; ++i)
	{
		int current_num = 0;
		cin >> current_num;
		if (current_num<min_num)
		{
			min_num = current_num;
		}
		if (current_num >= 0)
		{
			every_positive_start_array_index[i] = i;
			has_non_negative = true;

		}
		num_array[i] = current_num;
	}
	int result_i = num_array[0], result_j = num_array[total_num - 1], result = 0;
	if (has_non_negative)
	{
		result = min_num;
		for (int i = 0; i < total_num; ++i)
		{
			if (every_positive_start_array_index[i] >= 0)
			{
				int current_start_result = 0;
				for (int j = every_positive_start_array_index[i]; j < total_num; ++j)
				{
					current_start_result += num_array[j];
					if (current_start_result>result)
					{
						result_i = num_array[every_positive_start_array_index[i]];
						result_j = num_array[j];
						result = current_start_result;
					}
				}
			}
		}
	}
	cout << result << " " << result_i << " " << result_j;
	return 0;
}

bool resolve1007::is_all_negative(int* target,int size)
{
	if (target!=nullptr&&size>0)
	{
		for (int i = 0; i < size; ++i)
		{
			if (target[i]>=0)
			{
				return false;
			}
		}
	}
	return true;
}
