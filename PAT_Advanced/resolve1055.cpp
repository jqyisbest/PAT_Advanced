#include "resolve1055.h"
/*
	按年龄段分开存储按人员
	按查询条件搜索结果库是否有合适的结果并所需的结果集合并所需年龄段人员并保存至结果库
	想用递归但又怕200层递归会爆栈。。
	测试用例是过了，但感觉要超时==

	。。居然是爆内存，128MB都不够我用233333
	0
	Accepted
	3 ms	640 KB
	1
	Accepted
	84 ms	7040 KB
	2
	Memory Limit Exceeded
	0 ms	0 KB
	3
	Accepted
	4 ms	856 KB
	4
	Accepted
	4 ms	804 KB
	5
	Accepted
	3 ms	744 KB
	自我感觉这套爆内存的代码在大批量查询时效率极高==毕竟很大程度上利用了前面查询时的结果，保存一下
int resolve1055::resolve()
{
	int num_of_people = 0, num_of_queries = 0;
	vector<person *> person_all[201];
	scanf("%d %d", &num_of_people, &num_of_queries);
	for (size_t i = 0; i < num_of_people; ++i)
	{
		person *person_node = new person();
		person_node->name.resize(9);
		scanf("%s %d %d", &person_node->name[0], &person_node->age, &person_node->money);
		person_all[person_node->age].push_back(person_node);
	}
	vector<person *> ***result = new vector<person *> **[201];
	for (int i = 0; i < 201; ++i)
	{
		result[i] = new vector<person *> *[201];
		fill(result[i], result[i] + 201, nullptr);
		sort(person_all[i].begin(), person_all[i].end(), cmp_person);
	}
	//至此每个年龄段中的人有序
	for (int i = 1; i <= num_of_queries; ++i)
	{
		int num_of_result = 0, min_age = 0, max_age = 0;
		vector<person *> *current_result = nullptr;
		scanf("%d %d %d", &num_of_result, &min_age, &max_age);
		merge_sequence(person_all, result, min_age, max_age);
		printf("Case #%d:\n", i);
		current_result = result[min_age][max_age];
		if (current_result->size() > 0)
		{
			for (size_t j = 0; j < num_of_result && j < current_result->size(); ++j)
			{
				person *p = (*current_result)[j];
				printf("%s %d %d\n", p->name.c_str(), p->age, p->money);
			}
		}
		else
		{
			printf("None\n");
		}
	}
	return 0;
}

bool resolve1055::cmp_person(person *p1, person *p2)
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

void resolve1055::merge_sequence(vector<person *> *person_all, vector<person *> ***result, int index_1, int index_2)
{
	if (result[index_1][index_2] == nullptr)
	{
		int has_merged_age = index_1;
		for (int i = index_2; i >= index_1; --i)
		{
			if (result[index_1][index_2] != nullptr)
			{
				has_merged_age = i;
				break;
			}
		}

		if (has_merged_age == index_1)
		{
			result[has_merged_age][has_merged_age] = &person_all[index_1];
		}

		for (; has_merged_age < index_2;)
		{
			vector<person *> *source_1 = result[index_1][has_merged_age], *source_2 = nullptr, *target = new vector<person *>();
			result[index_1][has_merged_age + 1] = new vector<person *>();
			if (result[has_merged_age + 1][index_2] == nullptr)
			{
				source_2 = &person_all[++has_merged_age];
			}
			else
			{
				source_2 = result[has_merged_age + 1][index_2];
			}
			target->resize(source_1->size() + source_2->size());
			merge(source_1->begin(), source_1->end(), source_2->begin(), source_2->end(), target->begin(), cmp_person);
			result[index_1][has_merged_age] = target;
		}
	}
}
	既然保存前面每次的计算结果爆内存了，那就，只保存前面查询的最终结果，以防止来一个 0 199超时。

	还是超时==没什么区别==
	那就不保存了。输出一次free一次

	233333不保存内存反而大了哈哈哈哈哈哈什么魔鬼题目
	真就逼我重写merge函数呗？

	利用set排序

	吐了，超时
	0
	Accepted
	4 ms	384 KB
	1
	Accepted
	83 ms	6656 KB
	2
	Time Limit Exceeded
	--	0 KB
	3
	Accepted
	4 ms	428 KB
	4
	Accepted
	4 ms	424 KB
	5
	Accepted
	4 ms	352 KB

	参照答案，只能排一次序列，可以多次用minmaxage进行过滤，并通过限制每个年龄组只有100人参加排序来减少过滤时的比较次数
	哎，为啥我想不到用输出数量去优化过滤/(ㄒoㄒ)/~~
	0
	答案正确
	4 ms	508 KB
	1
	答案正确
	140 ms	6812 KB
	2
	答案正确
	120 ms	7540 KB
	3
	答案正确
	4 ms	368 KB
	4
	答案正确
	4 ms	508 KB
	5
	答案正确
	3 ms	372 KB
*/
int resolve1055::resolve()
{
	int num_of_people = 0, num_of_queries = 0, age_person[201]{ 0 };
	vector<person *> person_all;
	scanf("%d %d", &num_of_people, &num_of_queries);
	for (size_t i = 0; i < num_of_people; ++i)
	{
		person *person_node = new person();
		person_node->name.resize(9);
		scanf("%s %d %d", &person_node->name[0], &person_node->age, &person_node->money);
		person_all.push_back(person_node);
	}
	sort(person_all.begin(), person_all.end(), cmp_person);
	//每个年龄段只允许前100人参与过滤，这样最多20000人，相比总数十万人还是少了五倍
	vector<person *>result;
	for (size_t i = 0; i < num_of_people; ++i)
	{
		person * p = person_all[i];
		if (age_person[p->age] <= 100)
		{
			result.push_back(p);
			++age_person[p->age];
		}
		else
		{
			//本年龄段已满，不需要这个人了，控制内存
			free(p);
		}
	}
	person_all.clear();
	for (int i = 1; i <= num_of_queries; ++i)
	{
		int num_of_result = 0, min_age = 0, max_age = 0;
		vector<person *> current_result;
		scanf("%d %d %d", &num_of_result, &min_age, &max_age);
		printf("Case #%d:\n", i);
		for (size_t j = 0; j < result.size() && num_of_result>0; ++j)
		{
			person * p = result[j];
			if (p->age <= max_age&&p->age >= min_age)
			{
				current_result.push_back(p);
				--num_of_result;
			}
		}
		if (current_result.size() > 0)
		{
			person *p = nullptr;
			for (size_t j = 0; j < current_result.size(); ++j)
			{
				p = current_result[j];
				printf("%s %d %d\n", p->name.c_str(), p->age, p->money);
			}
		}
		else
		{
			printf("None\n");
		}
		current_result.clear();
	}
	return 0;
}

bool resolve1055::cmp_person(person *p1, person *p2)
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