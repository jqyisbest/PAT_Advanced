#include "common.h"
namespace resolve1033 {
	int resolve();
	typedef struct station_node {
		double price;
		double distance;
		//到达本站时的油量
		double oil;
	}gas_station;
	bool cmp_station(gas_station& s1, gas_station& s2);
	/**
		找最远可达的加油站
		asc:true-正向升序查找 false-逆向降序查找
		-1 找不到任何可达加油站
		-2 起点
		-3 终点
	*/
	int find_max_distance_tank(vector<gas_station>& stations_distance_asc,bool asc,int current_station_index,double tank_distance, double total_distance);
	double find_max_distance(vector<gas_station>& stations_distance_asc, int current_station_index, double tank_distance, double total_distance);
}