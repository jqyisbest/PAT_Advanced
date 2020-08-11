#include "common.h"
namespace resolve1131 {
	int resolve();
	typedef struct station {
		int index;
		vector<station *>adjacent_station;
		map<int, int>station_lines;
	}station;
	typedef struct solution {
		vector<station *>all_station;
		int transfer_num;
		solution() {
			this->transfer_num = 0;
		}
		solution(solution &s) {
			this->transfer_num = s.transfer_num;
			for (int i = 0; i < s.all_station.size(); i++)
			{
				this->all_station.push_back(s.all_station[i]);
			}
		}
	}solution;
	bool cmp_solution(solution* s1, solution *s2);
	void dfs(bool *visited, int current_line, station *start, station *end, solution &current_solution, vector<solution *> &all_solutions);
}