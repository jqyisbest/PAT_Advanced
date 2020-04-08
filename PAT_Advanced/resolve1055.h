#include "common.h"
namespace resolve1055 {
	int resolve();
	typedef struct person_node {
		int age;
		int money;
		string name;
	}person;
	bool cmp_person(person* p1, person* p2);
	void merge_sequence(vector<person*>* person_all,set<person*,decltype(cmp_person)*>& result,int index_1,int index_2,int num_of_result);
}