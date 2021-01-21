#include "common.h"
namespace resolve1072 {
	int resolve();
	typedef struct gas_station{
		string index;
		double min_dist;
		double average_dist;
		gas_station():index(""),min_dist(0){
		}
	}gas_station;
	bool cmp_station(gas_station *g1,gas_station *g2);
}