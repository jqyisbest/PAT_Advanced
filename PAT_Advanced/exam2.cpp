//#include <bits/stdc++.h>
//using namespace std;
//int main() {
//	//��¼�Ƿ�����������
//	bool *have_given = new bool[100001], *differ_exist = new bool[100001], *is_out = new bool[11];
//	fill(have_given, have_given + 100001, false);
//	fill(differ_exist, differ_exist + 100001, false);
//	fill(is_out, is_out + 11, false);
//	int num_given_1 = 0, num_given_2 = 0, n = 0, m = 0, out_num = 0;
//	scanf("%d %d", &num_given_1, &num_given_2);
//	//��¼ȫ���Ѹ�����
//	set<int> given;
//	given.insert(num_given_1);
//	given.insert(num_given_2);
//	have_given[num_given_1] = true;
//	have_given[num_given_2] = true;
//	differ_exist[abs(num_given_1 - num_given_2)] = true;
//	scanf("%d %d", &n, &m);
//	//��¼����������
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
//	//ģ��ÿһ�ֵ����
//	for (int i = 0; i < m&&out_num < n; ++i)
//	{
//		//��¼ÿһ�ֳ��ֵ���
//		vector<int> out_player;
//		for (int j = 0; j < n; ++j)
//		{
//			if (!is_out[j])
//			{
//				if (have_given[nums[j][i]])
//				{
//					//�Ѿ���������� ����
//					out_player.push_back(j + 1);
//					is_out[j] = true;
//				}
//				else
//				{
//					//�ж��Ƿ�Ϊ��ȷ������
//					if (!differ_exist[nums[j][i]])
//					{
//						out_player.push_back(j + 1);
//						is_out[j] = true;
//					}
//					//û��������������Ƿ���ȷ������
//					//���²�ֵ��
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