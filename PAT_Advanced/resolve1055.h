#include "common.h"
namespace resolve1055 {
	int resolve();
	typedef struct person_node {
		int age;
		int money;
		string name;
	}person;
	bool cmp_person(person* p1, person* p2);
}