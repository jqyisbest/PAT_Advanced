#include "common.h"
namespace resolve1114 {
	int resolve();
	typedef struct person {
		int id, f_id, m_id, k, m;
		double area;
		vector<int>childs;
		person() {
			id = f_id = m_id = k = m = 0;
			area = 0.0;
		}
	}person;
	typedef struct family {
		set<int>members;
		int id;
		double total_m, total_area, avg_m, avg_area;
		family() {
			id = 0;
			avg_m = avg_area = total_m = total_area = 0.0;
		}
	}family;
	void set_family(person *p, family *f, map<int, int> &person_family);
	bool cmp_family(family *f1, family *f2);
}