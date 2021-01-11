//#include<bits/stdc++.h>
//using namespace std;
//typedef struct path {
//	vector<int> test;
//	int s, v;
//	path() {
//		this->s = 0;
//		this->v = 0;
//	}
//}path;
//bool cmp_path(path* p1, path* p2) {
//	return p1->s == p2->s ? p1->v > p2->v:p1->s < p2->s;
//}
//void get_path(int current, vector<int> &current_path, vector<path*> &all_path, vector<vector<int>> &scores, vector<vector<int>> &v, int end, int current_v, int current_s) {
//	current_path.push_back(current);
//	if (current == end)
//	{
//		path* p = new path();
//		p->s = current_s;
//		p->v = current_v;
//		for (size_t i = 0; i < current_path.size(); i++)
//		{
//			p->test.push_back(current_path[i]);
//		}
//		all_path.push_back(p);
//		current_path.pop_back();
//		return;
//	}
//	else
//	{
//		for (size_t i = 0; i < scores.size(); i++)
//		{
//			if (scores[current][i] != -1)
//			{
//				get_path(i, current_path, all_path, scores, v, end, current_v + v[current][i], current_s + scores[current][i]);
//			}
//		}
//		current_path.pop_back();
//	}
//}
//int main() {
//	int n, m, temp_for_test = 0;
//	scanf("%d %d", &n, &m);
//	temp_for_test = n;
//	//先检查是否有环路
//	bool has_circle = false;
//	vector<vector<int>> scores;
//	vector<vector<int>> vouchers;
//	vector<int> parents_num_test(n, 0), parents_num(n, 0);
//	for (size_t i = 0; i < n; i++)
//	{
//		vector<int> s(n, -1), v(n, 0);
//		scores.push_back(s);
//		vouchers.push_back(v);
//	}
//	for (size_t i = 0; i < m; i++)
//	{
//		int a, b, c, d;
//		scanf("%d %d %d %d", &a, &b, &c, &d);
//		scores[a][b] = c;
//		vouchers[a][b] = d;
//		parents_num[b]++;
//		parents_num_test[b]++;
//	}
//	vector<bool> visited_test(n, false);
//	while (!has_circle)
//	{
//		int u = -1;
//		for (size_t i = 0; i < n; i++)
//		{
//			if (parents_num_test[i] == 0 && !visited_test[i])
//			{
//				u = i;
//				break;
//			}
//		}
//		if (u == -1)
//		{
//			if (temp_for_test > 0)
//			{
//				//还有剩余节点，必有环
//				has_circle = true;
//			}
//			break;
//		}
//		visited_test[u] = true;
//		temp_for_test--;
//		for (size_t i = 0; i < n; i++)
//		{
//			if (scores[u][i] != -1)
//			{
//				parents_num_test[i]--;
//			}
//		}
//	}
//	if (has_circle)
//	{
//		printf("Impossible.\n");
//		int k;
//		scanf("%d", &k);
//		for (size_t i = 0; i < k; i++)
//		{
//			int t;
//			scanf("%d", &t);
//			if (parents_num[t] == 0)
//			{
//				printf("You may take test %d directly.\n", t);
//			}
//			else
//			{
//				printf("Error.\n");
//			}
//		}
//	}
//	else
//	{
//		printf("Okay.\n");
//		int k;
//		scanf("%d", &k);
//		for (size_t i = 0; i < k; i++)
//		{
//			int t;
//			scanf("%d", &t);
//			if (parents_num[t] == 0)
//			{
//				printf("You may take test %d directly.\n", t);
//			}
//			else
//			{
//				vector<path*> all_path;
//				for (size_t j = 0; j < n; j++)
//				{
//					if (parents_num[j] == 0)
//					{
//						//一个起点
//						vector<int> current_path;
//						get_path(j, current_path, all_path, scores, vouchers, t, 0, 0);
//
//					}
//				}
//				sort(all_path.begin(), all_path.end(), cmp_path);
//				for (size_t l = 0; l < all_path[0]->test.size(); l++)
//				{
//					if (l != 0)
//					{
//						printf("->");
//					}
//					printf("%d", all_path[0]->test[l]);
//				}
//				printf("\n");
//			}
//		}
//	}
//	//system("pause");
//	return 0;
//}