//#include<bits/stdc++.h>
//using namespace std;
///*
//	����ÿһrun����Сֵ
//	����½����������κ�һrun����Сֵ��С����ô��һ����run
//	��һ�ֱȽ����⣬���ڴ������Сֵ������Сֵ
//*/
//int main() {
//	int n = 0, m = 0, temp = 0;
//	scanf("%d %d", &n, &m);
//	vector<vector<int>> runs;
//	vector<int> run, mins;
//	runs.push_back(run);
//	vector<vector<int>>run_mins;
//	run_mins.push_back(mins);
//	for (int i = 0; i < n; ++i)
//	{
//		scanf("%d", &temp);
//		int run_index = -1;
//		for (int j = 0; j < run_mins.size(); ++j)
//		{
//			//����СֵС�������п���
//			if ((run_mins[j].size() > 0 && temp > run_mins[j].back()) || run_mins[j].size() == 0)
//			{
//				run_index = j;
//				break;
//			}
//		}
//		if (run_index == -1)
//		{
//			//��һ����run
//			vector<int> r, m;
//			r.push_back(temp);
//			runs.push_back(r);
//			run_mins.push_back(m);
//		}
//		else
//		{
//			//����ȷ����run�в�������Сֵ
//			runs[run_index].push_back(temp);
//			if (run_mins[run_index].size() > 0 || runs[run_index].size() >= m)
//			{
//				sort(runs[run_index].begin(), runs[run_index].end());
//				run_mins[run_index].push_back(runs[run_index][0]);
//				runs[run_index].erase(runs[run_index].begin());
//			}
//		}
//	}
//	for (int i = 0; i < run_mins.size(); ++i)
//	{
//		bool is_first = true;
//		for (int j = 0; j < run_mins[i].size(); ++j)
//		{
//			if (!is_first)
//			{
//				printf(" ");
//			}
//			printf("%d", run_mins[i][j]);
//			is_first = false;
//		}
//		sort(runs[i].begin(), runs[i].end());
//		for (int j = 0; j < runs[i].size(); ++j)
//		{
//			if (!is_first)
//			{
//				printf(" ");
//			}
//			printf("%d", runs[i][j]);
//			is_first = false;
//		}
//		printf("\n");
//	}
//	//system("pause");
//	return 0;
//}