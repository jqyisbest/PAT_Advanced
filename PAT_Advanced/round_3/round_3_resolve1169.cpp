#include "round_3_resolve1169.h"
using namespace round_3_resolve1169;
#include <bits/stdc++.h>
using namespace std;
int round_3_resolve1169::resolve()
{
	bool *is_exist = new bool[100001], *is_legal = new bool[100001];
	fill(is_exist, is_exist + 100001, false);
	fill(is_legal, is_legal + 100001, false);
	int a1 = 0, a2 = 0, n = 0, m = 0;
	cin >> a1 >> a2 >> n >> m;
	bool *is_winner = new bool[n];
	fill(is_winner, is_winner + n, true);
	int remain_player_num = n;
	vector<int> exist_numbers;
	exist_numbers.push_back(a1);
	exist_numbers.push_back(a2);
	is_exist[a1] = true;
	is_exist[a2] = true;
	is_legal[abs(a1 - a2)] = true;
	int **numbers = new int*[n];
	for (int i = 0; i < n; i++)
	{
		numbers[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			cin >> numbers[i][j];
		}
	}
	for (int i = 0; i < m&&remain_player_num>0; i++)
	{
		vector<int> loser_in_turn;
		for (int j = 0; j < n; j++)
		{
			if (is_winner[j])
			{
				//只看未被淘汰的
				int choose = numbers[j][i];
				if (is_exist[choose] || !is_legal[choose])
				{
					//本轮出局
					is_winner[j] = false;
					loser_in_turn.push_back(j);
					remain_player_num--;
				}
				else
				{
					//本轮未出局
					for (int k = 0; k < exist_numbers.size(); k++)
					{
						is_legal[abs(exist_numbers[k] - choose)] = true;

					}
					exist_numbers.push_back(choose);
					is_exist[choose] = true;
				}
			}
		}
		for (int j = 0; j < loser_in_turn.size(); j++)
		{
			printf("Round #%d: %d is out.\n", i + 1, loser_in_turn[j] + 1);
		}
	}
	if (remain_player_num > 0)
	{
		printf("Winner(s):");
		for (int i = 0; i < n; i++)
		{
			if (is_winner[i])
			{
				printf(" %d", i + 1);
			}
		}
	}
	else
	{
		printf("No winner.\n");
	}
	return 0;
}