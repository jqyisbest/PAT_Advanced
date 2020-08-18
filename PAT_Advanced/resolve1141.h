#include "common.h"
namespace resolve1141 {
	int resolve();
	typedef struct school {
		string code;
		int total_num, tws;
		double total_weight_score;
		school() {
			this->total_num = 0;
			this->tws = 0;
			this->total_weight_score = 0.0;
		}
	}school;
	bool cmp_school(school *s_1, school *s_2);
}