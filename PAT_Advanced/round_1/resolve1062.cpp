#include "resolve1062.h"
/*
	没啥好说的
	先根据等级分组，再组内排序
*/
int resolve1062::resolve()
{
	int n = 0, l = 0, h = 0, total = 0;
	scanf("%d %d %d", &n, &l, &h);
	vector<person*> persons[4];
	vector<person*> *persons_sage = &persons[0];
	vector<person*> *persons_noble = &persons[1];
	vector<person*> *persons_fool = &persons[2];
	vector<person*> *persons_other = &persons[3];
	for (size_t i = 0; i < n; i++)
	{
		person* p = new person();
		scanf("%d %d %d", &p->id, &p->v, &p->t);
		if (p->v >= l&&p->t >= l)
		{
			p->total = p->v + p->t;
			++total;
			if (p->v >= h)
			{
				//圣人or君子
				if (p->t >= h)
				{
					persons_sage->push_back(p);
				}
				else
				{
					persons_noble->push_back(p);
				}
			}
			else if (p->t < h&&p->v >= p->t)
			{
				//愚人
				persons_fool->push_back(p);
			}
			else
			{
				persons_other->push_back(p);
			}
		}
	}
	sort(persons_sage->begin(), persons_sage->end(), cmp_person);
	sort(persons_noble->begin(), persons_noble->end(), cmp_person);
	sort(persons_fool->begin(), persons_fool->end(), cmp_person);
	sort(persons_other->begin(), persons_other->end(), cmp_person);
	printf("%d\n", total);
	for (size_t i = 0; i < 4; ++i)
	{
		vector<person*> person_list = persons[i];
		for (size_t j = 0; j < person_list.size(); ++j)
		{
			printf("%08d %d %d\n", person_list[j]->id, person_list[j]->v, person_list[j]->t);
		}
	}
	return 0;
}

bool resolve1062::cmp_person(person* p1, person* p2)
{
	return p1->total == p2->total ? p1->v == p2->v ? p1->id < p2->id : p1->v >= p2->v : p1->total >= p2->total;
}
