#include "common.h"
namespace resolve1025 {
	int resolve();
	typedef struct tester {
		string id;
		double score;
		int location_number;
		int rank_all;
		int rank_local;
	}tester;
	bool cmp_tester(tester* t1, tester* t2);
	void fill_rank(vector<tester*> testers,bool local);
}