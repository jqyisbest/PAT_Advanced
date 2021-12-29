#include "resolve1105.h"
/*
	先计算出合适的m*n
	再根据旋转规则选定下一个访问的节点
*/
int resolve1105::resolve()
{
	//计算m、n
	int total_num = 0, m = 0, n = 0, **matrix = nullptr;
	scanf("%d", &total_num);
	vector<int> nums(total_num);
	for (n = sqrt(total_num); n >= 1; n--)
	{
		if (total_num%n == 0)
		{
			m = total_num / n;
			break;
		}
	}
	matrix = new int*[m];
	for (int i = 0; i < m; ++i)
	{
		matrix[i] = new int[n];
		fill(matrix[i], matrix[i] + n, -1);
	}
	for (int i = 0; i < total_num; i++)
	{
		scanf("%d", &nums[i]);
	}
	sort(nums.begin(), nums.end());
	fill_data(matrix, 0, m - 1, 0, n - 1, nums, total_num - 1,1);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j != 0)
			{
				printf(" ");
			}
			printf("%d", matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}
void resolve1105::fill_data(int ** matrix, int i, const int max_i, int j, const int max_j, vector<int>& data, int data_index, int direction)
{
	//螺旋式填写数字
	//先填入当前数字
	matrix[i][j] = data[data_index];
	//寻找下一个可填入的位置
	int old_i = i, old_j = j;
	//先按照当前趋势走
	if (direction == 1)
	{
		j++;
	}
	else if (direction == 2)
	{
		i++;
	}
	else if (direction == 3)
	{
		j--;
	}
	else if (direction == 4)
	{
		i--;
	}
	if (i<0 || i>max_i || j<0 || j>max_j || matrix[i][j] != -1)
	{
		i = old_i;
		j = old_j;
		//按右(1)下(2)左(3)上(4)的顺序试探哪边可走
		if (j + 1 <= max_j&&matrix[i][j + 1] == -1)
		{
			j++;
			direction = 1;
		}
		else if (i + 1 <= max_i&&matrix[i + 1][j] == -1)
		{
			i++;
			direction = 2;
		}
		else if (j - 1 >= 0 && matrix[i][j - 1] == -1)
		{
			j--;
			direction = 3;
		}
		else if (i - 1 >= 0 && matrix[i - 1][j] == -1)
		{
			i--;
			direction = 4;
		}
	}
	if (i != old_i || j != old_j)
	{
		fill_data(matrix, i, max_i, j, max_j, data, data_index - 1, direction);
	}
}