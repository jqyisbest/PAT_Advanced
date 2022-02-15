#include "round_2_resolve1012.h"
using namespace round_2_resolve1012;
#include <bits/stdc++.h>
using namespace std;
int round_2_resolve1012::resolve()
{
	int n = 0, query_nums = 0;
	scanf("%d %d", &n, &query_nums);
	int a_statistics[101]{ 0 }, c_statistics[101]{ 0 }, m_statistics[101]{ 0 }, e_statistics[101]{ 0 };
	string *ids = new string[n];
	map<string, int> best_rank, a_score, c_score, m_score, e_score;
	map<string, char> best_item;
	for (size_t i = 0; i < n; i++)
	{
		int a = 0, c = 0, m = 0, e = 0;
		string id;
		id.resize(6);
		scanf("%s %d %d %d", &id[0], &c, &m, &e);
		a = (c + m + e) / 3;
		a_statistics[a]++;
		c_statistics[c]++;
		m_statistics[m]++;
		e_statistics[e]++;
		a_score[id] = a;
		c_score[id] = c;
		m_score[id] = m;
		e_score[id] = e;
		ids[i] = id;
	}
	for (size_t i = 0; i < n; i++)
	{
		string id = ids[i];
		int a = a_score[id], c = c_score[id], m = m_score[id], e = e_score[id], best = 0, rank = 0;
		char item = 'A';
		for (int j = 100; j > a; j--)
		{
			best += a_statistics[j];
		}
		for (int j = 100; j > c; j--)
		{
			rank += c_statistics[j];
		}
		if (best > rank)
		{
			best = rank;
			item = 'C';
		}
		rank = 0;
		for (int j = 100; j > m; j--)
		{
			rank += m_statistics[j];
		}
		if (best > rank)
		{
			best = rank;
			item = 'M';
		}
		rank = 0;
		for (int j = 100; j > e; j--)
		{
			rank += e_statistics[j];
		}
		if (best > rank)
		{
			best = rank;
			item = 'E';
		}
		best_rank[id] = best + 1;
		best_item[id] = item;
	}
	for (size_t i = 0; i < query_nums; i++)
	{
		bool has_found = false;
		string id;
		id.resize(6);
		scanf("%s", &id[0]);
		for (size_t j = 0; j < n && !has_found; j++)
		{
			if (ids[j] == id)
			{
				printf("%d %c\n", best_rank[id], best_item[id]);
				has_found = true;
			}
		}
		if (!has_found)
		{
			printf("N/A\n");
		}
	}
	return 0;
}