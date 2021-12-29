#include "resolve1098.h"
/*
	���ж��Ƿ�Ϊ��������

*/
int resolve1098::resolve()
{
	bool is_insert = true;
	int n = 0;
	scanf("%d", &n);
	vector<int> original_nums(n);
	vector<int> ordered_nums(n);
	for (size_t i = 0; i < n; i++)
	{
		scanf("%d", &original_nums[i]);
	}
	for (size_t i = 0; i < n; i++)
	{
		scanf("%d", &ordered_nums[i]);
	}
	int ordered_index = get_ordered_length(ordered_nums);
	for (size_t i = ordered_index; i < n && is_insert; i++)
	{
		if (ordered_nums[i] != original_nums[i])
		{
			is_insert = false;
		}
	}
	if (is_insert)
	{
		//����
		printf("Insertion Sort\n");
		sort(original_nums.begin(), original_nums.begin() + ordered_index + 1);
	}
	else
	{
		//����
		printf("Heap Sort\n");
		generate_heap(original_nums, 0, n - 1);
		bool should_continue = true;
		int heap_range = n - 1;
		while (should_continue&&heap_range >= 0)
		{
			should_continue = false;
			for (size_t i = 0; i < n; i++)
			{
				if (original_nums[i] != ordered_nums[i])
				{
					should_continue = true;
					break;
				}
			}
			heap_sort(original_nums, heap_range--);
		}
	}
	for (size_t i = 0; i < n; i++)
	{
		if (i != 0)
		{
			printf(" ");
		}
		printf("%d", original_nums[i]);
	}
	return 0;
}

int resolve1098::get_ordered_length(vector<int> &original_nums)
{
	int length = 1;
	for (size_t i = 1; i < original_nums.size() && original_nums[i - 1] <= original_nums[i]; i++)
	{
		length++;
	}
	return length;
}

void resolve1098::adjust_node(vector<int>& original_nums, int node_index, int end_index)
{
	//�Ƚ��ӽڵ�2i+1/2i+2��ֵ�Ƿ���ڸ��ڵ�
	//ע��!ֻ���ӽڵ������Ǹ�����
	bool less_left = false;
	if (2 * node_index + 1 <= end_index)
	{
		if (original_nums[node_index] < original_nums[2 * node_index + 1])
		{
			less_left = true;
		}
	}
	if (2 * node_index + 2 <= end_index)
	{
		if (original_nums[node_index] < original_nums[2 * node_index + 2])
		{
			if (less_left&&original_nums[2 * node_index + 2] < original_nums[2 * node_index + 1])
			{
				swap(original_nums[node_index], original_nums[2 * node_index + 1]);
			}
			else
			{
				swap(original_nums[node_index], original_nums[2 * node_index + 2]);
			}
			less_left = false;
		}
	}
	if (less_left)
	{
		swap(original_nums[node_index], original_nums[2 * node_index + 1]);
	}
	//�����Լ�����������
	if (2 * node_index + 1 <= end_index)
	{
		adjust_node(original_nums, 2 * node_index + 1, end_index);
	}
	if (2 * node_index + 2 <= end_index)
	{
		adjust_node(original_nums, 2 * node_index + 2, end_index);
	}
}

void resolve1098::generate_heap(vector<int>& original_nums, int start_index, int end_index)
{
	int node_num = end_index - start_index + 1;
	//��һ����Ҷ�ӽڵ�
	int first_index = node_num / 2 - 1;
	for (int i = first_index; i >= 0; --i)
	{
		adjust_node(original_nums, i, end_index);
	}
}

void resolve1098::heap_sort(vector<int>& original_nums, int insert_index)
{
	//����һ�ֶ���
	/*
	ÿһ�ֶ������ǽ��Ѷ������������򲢵������ѵĹ���
	*/
	swap(original_nums[0], original_nums[insert_index]);
	generate_heap(original_nums, 0, insert_index - 1);
}