#include "resolve1056.h"
/*
	模拟吧，没发现啥快捷的规律
	vector的删除有点意思，两个迭代器的位置是相对固定的，如果内容动了，那两个迭代器指向的内容都会跟着动
	0
	Accepted
	4 ms	384 KB
	1
	Segmentation Fault
	3 ms	512 KB
	2
	Accepted
	4 ms	396 KB
	3
	Accepted
	5 ms	376 KB
	4
	Accepted
	5 ms	384 KB
	5
	Segmentation Fault
	4 ms	384 KB

	为啥啊==；
	cao，每一轮中如果老鼠刚好可以分组的情况下不应组数不应加1且对应的排序的最后一组无需调整边界
	这种找自己逻辑漏洞的感觉真痛苦，但它一定会是值得的
	最强大的敌人，就是自己
	0
	Accepted
	3 ms	424 KB
	1
	Accepted
	3 ms	384 KB
	2
	Accepted
	3 ms	384 KB
	3
	Accepted
	3 ms	364 KB
	4
	Accepted
	4 ms	384 KB
	5
	Accepted
	4 ms	384 KB
*/
int resolve1056::resolve()
{
	int num_of_player = 0, max_of_group = 0;
	scanf("%d %d", &num_of_player, &max_of_group);
	//全部玩家
	vector<player *> player_all;
	//比赛过程容器
	vector<player *> player_sort;
	//loser标记数组
	bool *loser = new bool[num_of_player] {false};
	for (size_t i = 0; i < num_of_player; ++i)
	{
		player *p = new player();
		p->id = i;
		scanf("%d", &p->weight);
		p->rank = 0;
		player_all.push_back(p);
	}
	for (size_t i = 0; i < num_of_player; ++i)
	{
		int id = 0;
		scanf("%d", &id);
		player_sort.push_back(player_all[id]);
	}
	//模拟分组排序
	while (player_sort.size() > 1)
	{
		//得出共有几组
		int num_of_group = player_sort.size() / max_of_group;
		if (player_sort.size() % max_of_group != 0)
		{
			++num_of_group;
		}
		//模拟分组后的排序
		for (size_t i = 0; i < num_of_group; ++i)
		{
			vector<player *>::iterator start = player_sort.begin() + i * max_of_group;
			//此处在VisualStudio上存在越界检查,end = start + max_of_group 最后一组越界
			vector<player *>::iterator end = player_sort.end();
			if (i == num_of_group - 1 && player_sort.size() % max_of_group != 0)
			{
				//只有当有剩下的老鼠时的最后一轮才调整边界
				end = start + player_sort.size() % max_of_group;
			}
			else
			{
				end = start + max_of_group;
			}
			sort(start, end, cmp_player_weight);
			//将loser的排名置为num_of_group + 1并标记
			start = player_sort.begin() + i * max_of_group;
			//此处在VisualStudio上存在越界检查,end = start + max_of_group 最后一组越界
			end = player_sort.end();
			if (i != num_of_group - 1)
			{
				end = start + max_of_group;
			}
			while (++start != end)
			{
				(*start)->rank = num_of_group + 1;
				loser[(*start)->id] = true;
			}
		}
		//一轮过后将loser移出比赛过程容器
		for (vector<player *>::iterator start = player_sort.begin(); start != player_sort.end();)
		{
			if (loser[(*start)->id])
			{
				//此处在VisualStudio上会检查野指针，start在erase后为野指针故不能直接写player_sort.erase(start);
				start = player_sort.erase(start);
			}
			else
			{
				++start;
			}
		}
	}
	//第一名！！！
	player_sort[0]->rank = 1;
	--num_of_player;
	for (size_t i = 0; i < num_of_player; ++i)
	{
		if (player_all[i]->rank > 0)
		{
			printf("%d ", player_all[i]->rank);
		}
	}
	if (player_all[num_of_player]->rank > 0)
	{
		printf("%d", player_all[num_of_player]->rank);
	}
	return 0;
}

bool resolve1056::cmp_player_weight(player *p1, player *p2)
{
	return p1->weight > p2->weight;
}
