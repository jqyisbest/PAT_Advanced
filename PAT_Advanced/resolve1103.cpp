#include "resolve1103.h"
/*
	���..

	�ðɣ���dfs��Ӧ�á���
	dfs����ȫ���б�������
	��ô����ͱ�ɣ���k�����������֣�Ҫ����һЩҪ�������


*/
int resolve1103::resolve()
{
	int n = 0, k = 0, p = 0;
	scanf("%d %d %d", &n, &k, &p);
	//��׼��ȫ�����õĺ�ѡ
	vector<int> nums;
	nums.push_back(0);
	for (size_t i = 1; ; ++i)
	{
		int res = pow(i, p);
		if (res <= n)
		{
			nums.push_back(res);
		}
		else
		{
			break;
		}
	}
	//dfs
	int  max_sum = -1;
	vector<int> temp_results, results;
	temp_results.resize(k);
	dfs(nums.size() - 1, 0, 0, 0, max_sum, results, temp_results, nums, k, n);
	if (max_sum == -1) {
		printf("Impossible");
		return 0;
	}
	printf("%d = ", n);
	for (int i = 0; i < results.size(); i++) {
		if (i != 0) printf(" + ");
		printf("%d^%d", results[i], p);
	}
	return 0;
}

void resolve1103::dfs(int index, int temp_k, int temp_n, int temp_sum, int & max_sum, vector<int>& results, vector<int>& temp_results, vector<int>& nums, const int k, const int n)
{
	if (temp_k == k)
	{
		//k�����ֶ�������,���Ƿ������������µ����Ž�
		if (temp_n == n && temp_sum > max_sum)
		{
			results = temp_results;
			max_sum = temp_sum;
		}
	}
	else
	{
		//��δѡ��k����������
		while (index >= 1)
		{
			//ѡһ���ۺͲ��ᳬ��n�ľ����ܴ���������뵱ǰ�����λ
			//1���ۺͲ�����n��Ӳ��Ҫ��
			//2�����������㾡���ܴ�������������е����Ž�
			if (temp_n + nums[index] <= n)
			{
				temp_results[temp_k] = index;
				//��ѡ��һ������
				dfs(index, temp_k + 1, temp_n + nums[index], temp_sum + index, max_sum, results, temp_results, nums, k, n);
			}
			index--;
		}
	}
}