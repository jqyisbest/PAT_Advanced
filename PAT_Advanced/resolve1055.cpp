#include "resolve1055.h"
/*
	按年龄段分开存储按人员
	按查询条件搜索结果库是否有合适的结果并所需的结果集合并所需年龄段人员并保存至结果库
	根据查询年龄条件
*/
int resolve1055::resolve()
{
	int num_of_people = 0, num_of_queries = 0;
	vector<person*> person_all[201];
	scanf("%d %d", &num_of_people, &num_of_queries);
	for (size_t i = 0; i < num_of_people; ++i)
	{
		person* person_node = new person();
		person_node->name.resize(9);
		scanf("%s %d %d", &person_node->name[0], &person_node->age, &person_node->money);
		person_all[person_node->age].push_back(person_node);
	}
	vector<person*>* result[201][201]{nullptr};
	for (size_t i = 0; i < num_of_queries; i++)
	{
		int num_of_result = 0, min_age = 0, max_age = 0;
		scanf("%d %d %d",&num_of_result, &min_age, &max_age);
		vector<person*> result_temp;
		for (size_t i = 0; i < length; i++)
		{

		}
	}
	return 0;
}

bool resolve1055::cmp_person(person * p1, person * p2)
{
	if (p1->money != p2->money)
	{
		return p1->money >= p2->money;
	}
	if (p1->age != p2->age)
	{
		return p1->age <= p2->age;
	}
	if (p1->name != p2->name)
	{
		return p1->name <= p2->name;
	}
	return true;
}
