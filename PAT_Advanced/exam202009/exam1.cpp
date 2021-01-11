#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, last_i = 0, total_amount = 0;
	scanf("%d", &n);
	vector<int> weight(n, 0);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &weight[i]);
	}
	for (int i = 0; i < n; i++)
	{
		if (i == n - 1)
		{
			if (weight[i] <= weight[i - 1])
			{
				int last_amount = 200;
				if (i - last_i > 0)
				{
					for (int j = i; j >= last_i; j--)
					{
						if (j != i&&weight[j] > weight[j - 1])
						{
							last_amount += 100;
						}
						total_amount += last_amount;
					}
					last_i = i + 1;
				}
				else
				{
					total_amount += last_amount;
				}
			}
			else
			{
				total_amount += 300;
			}
		}
		else
		{
			if (weight[i] <= weight[i + 1])
			{
				int last_amount = 200;
				if (i - last_i > 0)
				{
					for (int j = i; j >= last_i; j--)
					{
						if (j != i&&weight[j] > weight[j + 1])
						{
							last_amount += 100;
						}
						total_amount += last_amount;
					}
					last_i = i + 1;
				}
				else
				{
					total_amount += last_amount;
					last_i = i;
				}
			}
		}
	}
	printf("%d", total_amount);
	system("pause");
	return 0;
}