#include "common.h"
namespace resolve1026 {
	int resolve();
	typedef struct ball_player {
		//in seconds
		int arrive_time;
		//in seconds
		int served_time;
		//in seconds
		int playing_time;
		bool is_vip;
	}ball_player;
	typedef struct ball_table {
		//in seconds
		int available_time;
		//in minutes
		int served_num;
	}ball_table;
	string convert_to_str(int seconds);
	int find_available_table(ball_table* tables,int num_of_table);
	int find_available_vip_table(ball_table* tables, int num_of_table , int before_time, bool* table_is_vip);
	int find_next_player(vector<ball_player>& players,int before_time, bool find_vip);
	bool cmp_player_arrive_asc(ball_player& p1, ball_player& p2);
	bool cmp_player_served_asc(ball_player& p1, ball_player& p2);

}