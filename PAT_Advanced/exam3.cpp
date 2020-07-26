//#include <bits/stdc++.h>
//using namespace std;
//typedef struct edge {
//	int n1, n2;
//	edge() {
//		n1 = 0;
//		n2 = 0;
//	}
//};
//int main() {
//	int n = 0, r = 0, k = 0, m = 0;
//	scanf("%d %d %d", &n, &r, &k);
//	vector<edge> edges(r);
//	for (int i = 0; i < r; ++i)
//	{
//		scanf("%d %d", &edges[i].n1, &edges[i].n2);
//	}
//	scanf("%d", &m);
//	//m个方案
//	for (int i = 0; i < m; ++i)
//	{
//		vector<int> regions(n);
//		bool exist[501];
//		int diff_num = 0;
//		fill(exist, exist + 501, false);
//		//统计不一样数字的个数
//		for (int j = 0; j < n; ++j)
//		{
//			scanf("%d", &regions[j]);
//			if (!exist[regions[j]])
//			{
//				diff_num++;
//				exist[regions[j]] = true;
//			}
//		}
//		if (diff_num > k)
//		{
//			printf("Error: Too many species.\n");
//		}
//		else if (diff_num < k)
//		{
//			printf("Error: Too few species.\n");
//		}
//		else
//		{
//			bool ok = true;
//			for (int j = 0; j < r&&ok; j++)
//			{
//				if (regions[edges[j].n1 - 1] == regions[edges[j].n2 - 1])
//				{
//					ok = false;
//				}
//			}
//			printf(ok ? "Yes\n" : "No\n");
//		}
//	}
//	//system("pause");
//	return 0;
//}