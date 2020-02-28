#include "resolve1026.h"
/**
	����3���߼�
	1������������9��ǰ�������� ��ֻ�����������޶��������Ƕ�������޶��ˣ���Ӧ���Ե�3
	2�������ΪVIPʱ����Ҫ�鿴�Ƿ���VIP�������������ṩVIP���Ӹ�VIP����Ӧ���Ե�5��7
	3���ȴ�ʱ���������루�����Ϊ����ȡ����= =������round�������ɣ���Ӧ����8
*/
int resolve1026::resolve()
{
	int  number_of_players = 0;
	scanf("%d\n", &number_of_players);
	vector<ball_player> players;
	players.resize(number_of_players);
	for (size_t i = 0; i < number_of_players; i++)
	{
		int h = 0, m = 0, s = 0, arrive_time = 0, playing_minutes = 0, is_vip = 0;
		scanf("%d:%d:%d %d %d\n", &h, &m, &s, &playing_minutes, &is_vip);
		arrive_time = h * 3600 + m * 60 + s;
		players[i].arrive_time = arrive_time;
		players[i].playing_time = 60 * (playing_minutes > 120 ? 120 : playing_minutes);
		players[i].is_vip = is_vip == 1;
		players[i].served_time = -1;
	}
	sort(players.begin(), players.end(), cmp_player_arrive_asc);
	int num_of_table = 0, num_of_vip_table = 0;
	cin >> num_of_table >> num_of_vip_table;
	bool* table_is_vip = new bool[num_of_table];
	fill(table_is_vip, table_is_vip + num_of_table + 1, false);
	ball_table* tables = new ball_table[num_of_table + 1];
	for (size_t i = 0; i < num_of_table + 1; i++)
	{
		tables[i].available_time = 8 * 3600;
		tables[i].served_num = 0;
	}
	for (size_t i = 0; i < num_of_vip_table; i++)
	{
		int index = 0;
		cin >> index;
		table_is_vip[index] = true;
	}
	int table_index_available = -1;
	int player_index = -1;
	int total_served_num = 0;
	//���������п��˾ͼ���
	while (-1 != (table_index_available = find_available_table(tables, num_of_table)) && -1 != (player_index = find_next_player(players, tables[table_index_available].available_time, table_is_vip[table_index_available])))
	{
		//���������VIP����ô�ټ��һ���Ƿ���VIP������
		if (players[player_index].is_vip)
		{
			int table_index_vip = find_available_vip_table(tables, num_of_table, players[player_index].arrive_time, table_is_vip);
			if (table_index_vip != -1)
			{
				//�����ṩVIP���Ӹ�VIP����
				//���ϸ��߼���ͨ��5��7���Ե�
				table_index_available = table_index_vip;
			}
		}
		if (players[player_index].arrive_time >= tables[table_index_available].available_time)
		{
			//����ʱ�������Ѿ����ã�������ȴ�
			players[player_index].served_time = players[player_index].arrive_time;
		}
		else
		{
			//����ʱ�����ӻ������ã���Ҫ�ȴ�
			players[player_index].served_time = tables[table_index_available].available_time;
		}
		tables[table_index_available].available_time = players[player_index].served_time + players[player_index].playing_time;
		++tables[table_index_available].served_num;
		++total_served_num;
	}
	//������
	sort(players.begin(), players.end(), cmp_player_served_asc);
	for (size_t i = number_of_players - total_served_num; i < number_of_players; ++i)
	{
		cout << convert_to_str(players[i].arrive_time) << " " << convert_to_str(players[i].served_time) << " " << round((players[i].served_time - players[i].arrive_time) / 60.0) << endl;
	}
	for (size_t i = 1; i < num_of_table; i++)
	{
		cout << tables[i].served_num << " ";
	}
	cout << tables[num_of_table].served_num;
	return 0;
}

string resolve1026::convert_to_str(int seconds)
{
	string time;
	int hour = 0, minute = 0;
	hour = seconds / 3600;
	seconds %= 3600;
	minute = seconds / 60;
	seconds %= 60;
	if (hour < 10)
	{
		time.append("0");
	}
	time.append(to_string(hour));
	time.append(":");
	if (minute < 10)
	{
		time.append("0");
	}
	time.append(to_string(minute));
	time.append(":");
	if (seconds < 10)
	{
		time.append("0");
	}
	time.append(to_string(seconds));
	return time;
}

int resolve1026::find_available_table(ball_table * tables, int num_of_table)
{
	int table_index = -1;
	int min = -1;
	for (size_t i = 1; i <= num_of_table; ++i)
	{
		if (tables[i].available_time < 75600 && (min == -1 || tables[i].available_time < min))
		{
			table_index = i;
			min = tables[i].available_time;
		}
	}
	return table_index;
}

int resolve1026::find_available_vip_table(ball_table * tables, int num_of_table, int before_time, bool* table_is_vip)
{
	int table_index = -1;
	int min = -1;
	for (size_t i = 1; i <= num_of_table; ++i)
	{
		if (table_is_vip[i] && tables[i].available_time < 75600 && tables[i].available_time <= before_time && (min == -1 || tables[i].available_time < min))
		{
			table_index = i;
			min = tables[i].available_time;
		}
	}
	return table_index;
}

int resolve1026::find_next_player(vector<ball_player>& players, int before_time, bool find_vip)
{
	int player_index = -1;
	if (find_vip)
	{
		//��Ҫһλ�������ֳ���VIP����
		for (size_t i = 0; -1 == player_index&&i < players.size(); ++i)
		{
			//������9��ǰ����Ŀͻ������Ե�3
			if (players[i].arrive_time <= before_time&&players[i].arrive_time < 75600 && players[i].is_vip&&players[i].served_time == -1) {
				player_index = i;
			}
		}

	}
	for (size_t i = 0; player_index == -1 && i < players.size(); ++i)
	{
		if (players[i].served_time == -1 && players[i].arrive_time < 75600) {
			player_index = i;
		}
	}
	return player_index;
}

bool resolve1026::cmp_player_arrive_asc(ball_player & p1, ball_player & p2)
{
	return p1.arrive_time < p2.arrive_time;
}

bool resolve1026::cmp_player_served_asc(ball_player & p1, ball_player & p2)
{
	return p1.served_time < p2.served_time;
}
