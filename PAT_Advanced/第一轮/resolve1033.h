#include "common.h"
namespace resolve1033 {
	int resolve();
	typedef struct station_node {
		double price;
		double distance;
		//���ﱾվʱ������
		double oil;
	}gas_station;
	bool cmp_station(gas_station& s1, gas_station& s2);
	/**
		����Զ�ɴ�ļ���վ
		asc:true-����������� false-���������
		-1 �Ҳ����κοɴ����վ
		-2 ���
		-3 �յ�
	*/
	int find_max_distance_tank(vector<gas_station>& stations_distance_asc,bool asc,int current_station_index,double tank_distance, double total_distance);
	double find_max_distance(vector<gas_station>& stations_distance_asc, int current_station_index, double tank_distance, double total_distance);
}