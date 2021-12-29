#include "resolve1114.h"
/*
	先统计出每个家庭有哪些人，再统计每个家庭的信息
*/
int resolve1114::resolve()
{
	vector<family*> all_family;
	map<int, int> person_family;
	map<int, person*> all_person;
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		person *p = new person();
		scanf("%d %d %d %d", &p->id, &p->f_id, &p->m_id, &p->k);
		p->childs.resize(p->k);
		for (int j = 0; j < p->k; j++)
		{
			scanf("%d", &p->childs[j]);
		}
		scanf(" %d %lf", &p->m, &p->area);
		all_person[p->id] = p;
	}
	//整理关系网
	for (map<int, person*>::iterator it = all_person.begin(); it != all_person.end(); it++)
	{
		person *p = it->second;
		//自立门户。。
		family *new_f = new family();
		new_f->id = all_family.size();
		set_family(p, new_f, person_family);
		all_family.push_back(new_f);
	}
	//合并有重复成员的家庭
	int repeat_num = 0;
	for (int i = 0; i < all_family.size(); i++)
	{
		if (all_family[i]->id != -1)
		{
			vector<int> repeat_family;
			for (set<int>::iterator it = all_family[i]->members.begin(); it != all_family[i]->members.end(); it++)
			{
				int another_family = person_family[*it];
				if (another_family != i&&all_family[another_family]->id != -1)
				{
					//合并
					repeat_family.push_back(another_family);
					all_family[another_family]->id = -1;
				}
			}
			repeat_num += repeat_family.size();
			for (int j = 0; j < repeat_family.size(); j++)
			{
				int another_family = repeat_family[j];
				for (set<int>::iterator another_it = all_family[another_family]->members.begin(); another_it != all_family[another_family]->members.end(); another_it++)
				{
					all_family[i]->members.insert(*another_it);
					person_family[*another_it] = i;
				}
			}
		}
	}
	printf("%d\n", all_family.size() - repeat_num);
	//统计家庭信息
	for (int i = 0; i < all_family.size(); i++)
	{
		if (all_family[i]->id != -1) {
			for (set<int>::iterator j = all_family[i]->members.begin(); j != all_family[i]->members.end(); j++)
			{
				int person_id = *j;
				if (all_person.count(person_id) != 0)
				{
					all_family[i]->total_m += all_person[person_id]->m;
					all_family[i]->total_area += all_person[person_id]->area;
				}
			}
			all_family[i]->avg_m = all_family[i]->total_m / (double)(all_family[i]->members.size());
			all_family[i]->avg_area = all_family[i]->total_area / (double)(all_family[i]->members.size());
		}
	}
	//按要求排序
	sort(all_family.begin(), all_family.end(), cmp_family);
	for (int i = 0; i < all_family.size(); i++)
	{
		if (all_family[i]->id != -1)
		{
			printf("%04d %d %.03f %.03f\n", (*(all_family[i]->members.begin())), all_family[i]->members.size(), all_family[i]->avg_m, all_family[i]->avg_area);
		}
	}
	return 0;
}

void resolve1114::set_family(person * p, family * f, map<int, int>& person_family)
{
	person_family[p->id] = f->id;
	f->members.insert(p->id);
	if (p->f_id != -1)
	{
		person_family[p->f_id] = f->id;
		f->members.insert(p->f_id);
	}
	if (p->m_id != -1)
	{
		person_family[p->m_id] = f->id;
		f->members.insert(p->m_id);
	}
	for (size_t i = 0; i < p->k; i++)
	{
		person_family[p->childs[i]] = f->id;
		f->members.insert(p->childs[i]);
	}
}

bool resolve1114::cmp_family(family * f1, family * f2)
{
	if (f1->id == -1)
	{
		return false;
	}
	if (f2->id == -1)
	{
		return true;
	}
	return f1->avg_area == f2->avg_area ? (*(f1->members.begin())) < (*(f2->members.begin())) : f1->avg_area > f2->avg_area;
}