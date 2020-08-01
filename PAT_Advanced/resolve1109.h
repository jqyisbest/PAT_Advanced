#include "common.h"
namespace resolve1109 {
	int resolve();
	typedef struct person {
		string name;
		int height;
		person() {
			this->name.resize(8);
			this->height = 0;
		}
	}person;
	bool cmp_person(person *p1, person *p2);
	vector<person*> get_row(vector<person*> &all_people, int start, int end);
}