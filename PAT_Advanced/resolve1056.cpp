#include "resolve1056.h"
/*
	ģ��ɣ�û����ɶ��ݵĹ���
	vector��ɾ���е���˼��������������λ������Թ̶��ģ�������ݶ��ˣ�������������ָ������ݶ�����Ŷ�
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

	Ϊɶ��==��
	cao��ÿһ�����������պÿ��Է��������²�Ӧ������Ӧ��1�Ҷ�Ӧ����������һ����������߽�
	�������Լ��߼�©���ĸо���ʹ�࣬����һ������ֵ�õ�
	��ǿ��ĵ��ˣ������Լ�
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
	//ȫ�����
	vector<player *> player_all;
	//������������
	vector<player *> player_sort;
	//loser�������
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
	//ģ���������
	while (player_sort.size() > 1)
	{
		//�ó����м���
		int num_of_group = player_sort.size() / max_of_group;
		if (player_sort.size() % max_of_group != 0)
		{
			++num_of_group;
		}
		//ģ�����������
		for (size_t i = 0; i < num_of_group; ++i)
		{
			vector<player *>::iterator start = player_sort.begin() + i * max_of_group;
			//�˴���VisualStudio�ϴ���Խ����,end = start + max_of_group ���һ��Խ��
			vector<player *>::iterator end = player_sort.end();
			if (i == num_of_group - 1 && player_sort.size() % max_of_group != 0)
			{
				//ֻ�е���ʣ�µ�����ʱ�����һ�ֲŵ����߽�
				end = start + player_sort.size() % max_of_group;
			}
			else
			{
				end = start + max_of_group;
			}
			sort(start, end, cmp_player_weight);
			//��loser��������Ϊnum_of_group + 1�����
			start = player_sort.begin() + i * max_of_group;
			//�˴���VisualStudio�ϴ���Խ����,end = start + max_of_group ���һ��Խ��
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
		//һ�ֹ���loser�Ƴ�������������
		for (vector<player *>::iterator start = player_sort.begin(); start != player_sort.end();)
		{
			if (loser[(*start)->id])
			{
				//�˴���VisualStudio�ϻ���Ұָ�룬start��erase��ΪҰָ��ʲ���ֱ��дplayer_sort.erase(start);
				start = player_sort.erase(start);
			}
			else
			{
				++start;
			}
		}
	}
	//��һ��������
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
