//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	int n, m, count = 0, current_amount = 0;
//	scanf("%d %d", &n, &m);
//	vector<int> prices(n, 0);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &prices[i]);
//		if (prices[i] <= m)
//		{
//			count++;
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		current_amount = prices[i];
//		for (int j = 1; j + i < n; j++)
//		{
//			current_amount += prices[j + i];
//			if (current_amount <= m)
//			{
//				count++;
//			}
//			else
//			{
//				current_amount = 0;
//				break;
//			}
//		}
//	}
//	printf("%d", count);
//	//system("pause");
//	return 0;
//}