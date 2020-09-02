//#include <bits/stdc++.h>
//using namespace std;
//int main() {
//	//记录是否存在这个距离
//	bool *have_given = new bool[100001], *differ_exist = new bool[100001], *is_out = new bool[11];
//	fill(have_given, have_given + 100001, false);
//	fill(differ_exist, differ_exist + 100001, false);
//	fill(is_out, is_out + 11, false);
//	int num_given_1 = 0, num_given_2 = 0, n = 0, m = 0, out_num = 0;
//	scanf("%d %d", &num_given_1, &num_given_2);
//	//记录全部已给的数
//	set<int> given;
//	given.insert(num_given_1);
//	given.insert(num_given_2);
//	have_given[num_given_1] = true;
//	have_given[num_given_2] = true;
//	differ_exist[abs(num_given_1 - num_given_2)] = true;
//	scanf("%d %d", &n, &m);
//	//记录给出来的数
//	vector<int> *nums = new vector<int>[n];
//	for (int i = 0; i < n; ++i)
//	{
//		nums[i].resize(m);
//		for (int j = 0; j < m; ++j)
//		{
//			scanf("%d", &nums[i][j]);
//		}
//	}
//
//	//模拟每一轮的情况
//	for (int i = 0; i < m&&out_num < n; ++i)
//	{
//		//记录每一轮出局的人
//		vector<int> out_player;
//		for (int j = 0; j < n; ++j)
//		{
//			if (!is_out[j])
//			{
//				if (have_given[nums[j][i]])
//				{
//					//已经有了这个数 出局
//					out_player.push_back(j + 1);
//					is_out[j] = true;
//				}
//				else
//				{
//					//判断是否为正确的数字
//					if (!differ_exist[nums[j][i]])
//					{
//						out_player.push_back(j + 1);
//						is_out[j] = true;
//					}
//					//没有这个数，不管是否正确都插入
//					//更新差值表
//					for (set<int>::iterator it = given.begin(); it != given.end(); ++it)
//					{
//						differ_exist[abs((*it) - nums[j][i])] = true;
//					}
//					differ_exist[abs(num_given_1 - nums[j][i])] = true;
//					differ_exist[abs(num_given_2 - nums[j][i])] = true;
//					given.insert(nums[j][i]);
//					have_given[nums[j][i]] = true;
//				}
//			}
//		}
//		out_num += out_player.size();
//		if (out_player.size() > 0)
//		{
//			printf("Round #%d: ", i + 1);
//			for (int j = 0; j < out_player.size(); ++j)
//			{
//				printf("%d ", out_player[j]);
//			}
//			printf("is out.\n");
//		}
//	}
//	if (out_num < n)
//	{
//		printf("Winner(s):");
//		for (int i = 0; i < n; ++i)
//		{
//			if (!is_out[i])
//			{
//				printf(" %d", i + 1);
//			}
//		}
//	}
//	else
//	{
//		printf("No winner.");
//	}
//	//system("pause");
//	return 0;
//}