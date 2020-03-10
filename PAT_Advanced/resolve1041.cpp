#include "resolve1041.h"
/*
	��˫ѭ�����Ի᲻�ᳬʱ�ɡ�

	��ͦ��==
*/
int resolve1041::resolve()
{
	int nums = 0, unique_num = 0;
	scanf("%d", &nums);
	if (nums > 0)
	{
		int* occur_nums = new int[nums];
		int* occur_times = new int[10001];
		for (size_t i = 0; i < nums; ++i)
		{
			scanf("%d", &occur_nums[i]);
			occur_times[occur_nums[i]]++;
		}
		for (size_t i = 0; i < nums; ++i)
		{
			if (occur_times[occur_nums[i]] == 1)
			{
				unique_num = occur_nums[i];
				break;
			}
		}
	}
	if (unique_num == 0)
	{
		printf("None");
	}
	else
	{
		printf("%d", unique_num);
	}
	return 0;
}