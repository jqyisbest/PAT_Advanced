#include <bits/stdc++.h>
using namespace std;
void find_in_half(vector<int> &total, int value) {
	int i = 0, j = total.size() - 1, k = 0;
	k = (i + j) / 2;
	while (i <= j)
	{
		printf("%d %d\n", total[i], total[j]);
		if (total[k] < value)
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
	printf("最终i为：%d\n最终j为：%d\n", i, j);
}
int main() {
	vector<int> total(10);
	for (int i = 1; i <= 10; i++)
	{
		total[i - 1] = 2 * i;
		if (i != 1)
		{
			printf(" ");
		}
		printf("%d", i << 1);
	}
	printf("\n");
	find_in_half(total, 19);
	system("pause");
	return 0;
}