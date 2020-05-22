#include "resolve1029.h"

/**
	��С�����ÿһ������Ԫ�أ����ö��ֲ����ڴ������в��ұ���С�ģ����ߵ��������м������ټ��ϵ�ǰ��i+1���͵õ����Ǻϲ������еĵڼ�����
	��������һ��Ҫ��scanf������cin���׳�ʱ��Ϊʲô˵�����׶�����һ���ء���Ϊ���OJ��״̬�йأ����������Ҳ���չ���Զ����scanf�ȶ���
	0
	����ȷ
	4 ms	424 KB
	1
	����ȷ
	2 ms	356 KB
	2
	����ȷ
	2 ms	424 KB
	3
	����ȷ
	2 ms	436 KB
	4
	����ȷ
	3 ms	412 KB

	 cin����ͬ���������ύ��                     scanf�����������滻Ϊscanf��                scanf��ȫ������scanf���룩
	5
	����ȷ           ���г�ʱ              ����ȷ              ����ȷ                  ����ȷ
	104 ms	2472 KB    --	0 KB             61 ms	2432 KB        61 ms	2432 KB          31 ms	2404 KB
	6
	����ȷ           ����ȷ              ����ȷ              ����ȷ                  ����ȷ
	103 ms	1792 KB    134 ms  1900 KB       44 ms	1792 KB        44 ms	1960 KB          43 ms	1792 KB
	7
	����ȷ           ����ȷ              ����ȷ              ����ȷ                  ����ȷ
	129 ms	1960 KB	   139 ms  1920 KB       44 ms	1960 KB        44 ms	1892 KB          40 ms	1892 KB
	8
	����ȷ           ���г�ʱ              ����ȷ              ����ȷ                  ����ȷ
	158 ms	3604 KB    --	0 KB             84 ms	3428 KB        85 ms	3428 KB          70 ms	3456 KB
*/
int resolve1029::resolve()
{
	int n1 = 0, n2 = 0;
	long *nums_1, *nums_2;
	// cin >> n1;
	scanf("%d", &n1);
	nums_1 = new long[n1];
	for (size_t i = 0; i < n1; ++i)
	{
		// cin >> nums_1[i];
		scanf("%ld", &nums_1[i]);
	}
	// cin >> n2;
	scanf("%d", &n2);
	nums_2 = new long[n2];
	for (size_t i = 0; i < n2; ++i)
	{
		// cin >> nums_2[i];
		scanf("%ld", &nums_2[i]);
	}

	int less_n = n1, bigger_n = n2;
	long *less_nums = nums_1, *more_nums = nums_2;
	if (n1 > n2)
	{
		less_n = n2;
		bigger_n = n1;
		less_nums = nums_2;
		more_nums = nums_1;
	}
	//�ڶ��ٸ�����������λ��
	int mid_count = (n1 + n2) / 2 + (n1 + n2) % 2;
	int l = 0, r = n1 - 1, val_index_in_base = 0, current_count = 0;
	long current_val = 0;
	for (size_t i = 0; i < less_n; ++i)
	{
		//��ǰ�����ֵ���ڻ�׼�����е�λ�á�������ϲ������еĸ������ڼ��������ں�mid_count�Ƚϣ�
		current_val = less_nums[i];
		val_index_in_base = current_count = 0;
		if (current_val < more_nums[0])
		{
			val_index_in_base = 0;
		}
		else if (current_val > more_nums[bigger_n - 1])
		{
			val_index_in_base = bigger_n;
		}
		else
		{
			val_index_in_base = locate_by_binary_search(more_nums, l, r, current_val);
		}
		current_count = val_index_in_base + i + 1;
		if (current_count >= mid_count)
		{
			//current_count==mid_count���ҵ�������current_count>mid_count�պù�������λ���ڻ�׼�����[val_index_in_base-current_count+mid_count]��
			cout << (current_count == mid_count ? current_val : more_nums[val_index_in_base - current_count + mid_count]);
			break;
		}
		l = val_index_in_base;
	}
	if (current_count < mid_count)
	{
		//�ڶ������鶼�������˻�û�ҵ���λ��������
		//������������ӻ�׼�����ﲹ
		cout << more_nums[val_index_in_base + mid_count - current_count - 1];
	}
	return 0;
}

int resolve1029::locate_by_binary_search(long * nums, int l, int r, long val)
{
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (val >= nums[mid]) {
			l = mid + 1;
		}
		else if (val < nums[mid])
		{
			r = mid - 1;
		}
	}
	return (l + r) / 2 + 1;
}
