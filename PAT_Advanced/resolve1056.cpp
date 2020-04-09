#include "resolve1056.h"
/*
	模拟吧，没发现啥快捷的规律
*/
int resolve1056::resolve()
{
	int num_of_player = 0, max_of_group = 0;
	scanf("%d %d", &num_of_player, &max_of_group);
	//全部玩家
	vector<player*> player_all;
	//比赛过程容器
	vector<player*> player_sort;
	for (size_t i = 0; i < num_of_player; ++i)
	{
		player* p = new player();
		p->id = i;
		scanf("%d", &p->weight);
		player_all.push_back(p);
	}
	for (size_t i = 0; i < num_of_player; ++i)
	{
		int id = 0;
		scanf("%d", &id);
		player_sort.push_back(player_all[id]);
	}
	//模拟分组排序
	while (player_sort.size() != 1)
	{
		//得出共有几组
		int num_of_group = player_sort.size() / max_of_group + 1;
		//本轮的loser
		vector<vector<player*>::iterator> loser_all;
		//模拟分组后的排序
		for (size_t i = 0; i < num_of_group; ++i)
		{
			vector<player*>::iterator start = player_sort.begin() + i*max_of_group;
			vector<player*>::iterator end = player_sort.end();
			
			if (i == num_of_group - 1)
			{
				end = start + player_sort.size() % max_of_group;
			}
			else
			{
				end = start + max_of_group;
			}
			sort(start, end, cmp_player_weight);
			//将其它老鼠的排名置为num_of_group + 1
			start = player_sort.begin() + i*max_of_group + 1;
			end = start + max_of_group;
			if (i == num_of_group - 1)
			{
				end = player_sort.end();
			}
			while (start != end)
			{
				vector<player*>::iterator loser = start++;
				(*loser)->rank = num_of_group + 1;
				
				loser_all.push_back(loser);
			}
		}
		for (size_t i = 0; i < loser_all.size(); ++i)
		{
			//并移出比赛过程容器
			player_sort.erase(loser_all[i]);
		}
	}
	--num_of_player;
	for (size_t i = 0; i < num_of_player; ++i)
	{
		printf("%d ", player_all[i]->rank);
	}
	printf("%d", player_all[num_of_player]->rank);
	return 0;
}

bool resolve1056::cmp_player_weight(player * p1, player * p2)
{
	return p1->weight > p2->weight;
}
