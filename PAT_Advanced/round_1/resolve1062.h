#include "common.h"
namespace resolve1062 {
	int resolve();
	typedef struct person_node {
		//8λ
		int id;
		int v;
		int t;
		int total;
	}person;
	bool cmp_person(person* p1, person* p2);
}