#include "resolve1057.h"
/*
	��vectorģ��ջ�洢����set������
	�൱��һ���������ݣ��ڴ�Ӧ���ǹ���==
	�п��ܳ�ʱ����

	/(��o��)/~~
	0
	����ȷ
	4 ms	384 KB
	1
	���г�ʱ
	--	0 KB
	2
	���г�ʱ
	--	0 KB
	3
	���г�ʱ
	--	0 KB
	4
	�𰸴���
	4 ms	512 KB

	����keyֵΪ���ֺ͵����������Կ��ٶ�λ��ֵ
	����������£�
	����ֵ�ȵ�ǰ��ֵ���Ҳ����sizeΪ��������ֵ������Ӧ++
	����ֵ�ȵ�ǰ��ֵС���Ҳ����sizeΪż������ֵ������Ӧ--
	��� ������1��Сż��1
	ɾ���������£�
	ɾ��ֵ�պ�Ϊ��ֵ��ɾ��ǰsizeΪ��������ֵ������Ӧ--��ɾ��ǰsizeΪż������ֵ������Ӧ++
	ɾ��ֵ��������ֵʱ�Ĺ���ǡ�úͲ�������෴��С����1����ż��1

	��ȻЧ�ʸߺܶ࣬����������������
	�δ�������һ���𰸴���Ӧ�����ظ��������⣬set���޷�����ظ���
	�����������������ͳ��ÿ�����ֳ��ֵĴ���
	0
	����ȷ
	3 ms	640 KB
	1
	����ȷ
	33 ms	2300 KB
	2
	����ȷ
	33 ms	2428 KB
	3
	�δ���
	43 ms	2268 KB
	4
	�𰸴���
	3 ms	296 KB
	����set������λ�Ƶİ취��������ظ����ֵ����⣬��ʹ�ܽ��Ҳ�ܷ��������׳���,������ͦ����˼���뷨������
	int resolve1057::resolve()
	{
	vector<int> keys;
	set<int> sorts;
	set<int>::iterator median;
	int num_of_ops = 0, key = 0, size = 0, num_count[100000]{ 0 };
	char ops[11];
	scanf("%d", &num_of_ops);
	for (int i = 0; i < num_of_ops; ++i)
	{
	scanf("%s", ops);
	if (strcmp(ops, "Push") == 0)
	{
	scanf("%d", &key);
	keys.push_back(key);
	sorts.insert(key);
	++num_count[key];
	++size;
	if (size == 1)
	{
	median = sorts.begin();
	}
	//������ֵ������
	if (*median < key&&size % 2 != 0)
	{
	++median;
	}
	else if (*median > key&&size % 2 == 0)
	{
	--median;
	}
	}
	else if (strcmp(ops, "Pop") == 0)
	{
	if (size > 0)
	{
	key = keys[keys.size() - 1];
	bool need_adjust_before_erase = key == *median;
	keys.pop_back();
	printf("%d\n", key);
	if (need_adjust_before_erase)
	{
	if (size % 2 == 0)
	{
	++median;
	}
	else
	{
	--median;
	}
	}
	sorts.erase(key);
	--size;
	if (!need_adjust_before_erase)
	{
	if (*median > key&&size % 2 != 0)
	{
	++median;
	}
	else if (*median < key&&size % 2 == 0)
	{
	--median;
	}
	}
	}
	else
	{
	printf("Invalid\n");
	}
	}
	else if (strcmp(ops, "PeekMedian") == 0)
	{
	if (size > 0)
	{
	printf("%d\n", *median);
	}
	else
	{
	printf("Invalid\n");
	}
	}
	}
	return 0;
	}
	תΪ�ö��ֲ���İ취ʵ��һ������vector��

	���ڡ������ַ�����̫������/(��o��)/~~
	0
	����ȷ
	4 ms	256 KB
	1
	����ȷ
	42 ms	1148 KB
	2
	����ȷ
	199 ms	1212 KB
	3
	����ȷ
	122 ms	1428 KB
	4
	����ȷ
	4 ms	296 KB

	ע�����ַ���ȷ�������£��ɹ��ο�
	k = (i + j) / 2;
	while (i <= j)
	{
	if (keys[k] < value)
	{
	i = k + 1;
	}
	else
	{
	j = k - 1;
	}
	k = (i + j) / 2;
	}
	k = i;
*/
int resolve1057::resolve()
{
	vector<int> keys;
	vector<int> keys_sort;
	int num_of_ops = 0, key = 0, size = 0;
	char ops[11];
	scanf("%d", &num_of_ops);
	for (int i = 0; i < num_of_ops; ++i)
	{
		scanf("%s", ops);
		if (strcmp(ops, "Push") == 0)
		{
			scanf("%d", &key);
			keys.push_back(key);
			insert_with_order(keys_sort, key);
			++size;
		}
		else if (strcmp(ops, "Pop") == 0)
		{
			if (size > 0)
			{
				key = keys[size - 1];
				keys.pop_back();
				printf("%d\n", key);
				erase_with_order(keys_sort, key);
				--size;
			}
			else
			{
				printf("Invalid\n");
			}
		}
		else if (strcmp(ops, "PeekMedian") == 0)
		{
			if (size > 0)
			{
				if (size % 2 == 0)
				{
					printf("%d\n", keys_sort[size / 2 - 1]);
				}
				else
				{
					printf("%d\n", keys_sort[(size + 1) / 2 - 1]);
				}
			}
			else
			{
				printf("Invalid\n");
			}
		}
	}
	return 0;
}

vector<int>::iterator resolve1057::get_it_with_order(vector<int>& keys, int value)
{
	vector<int>::iterator it = keys.begin();
	if (it != keys.end())
	{
		int i = 0, j = keys.size() - 1, k = 0;
		if (keys[j] < value)
		{
			k = j + 1;
		}
		else if (keys[0] > value)
		{
			k = 0;
		}
		else
		{
			k = (i + j) / 2;
			while (i <= j)
			{
				if (keys[k] < value)
				{
					i = k + 1;
				}
				else
				{
					j = k - 1;
				}
				k = (i + j) / 2;
			}
			k = i;
		}
		it += k;
	}
	return it;
}

void resolve1057::insert_with_order(vector<int>& keys, int value)
{
	vector<int>::iterator it = get_it_with_order(keys, value);
	keys.insert(it, value);
}

void resolve1057::erase_with_order(vector<int>& keys, int value)
{
	vector<int>::iterator it = get_it_with_order(keys, value);
	keys.erase(it);
}
