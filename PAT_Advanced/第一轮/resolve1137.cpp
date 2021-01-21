#include "resolve1137.h"
/*
	经典map+vector

	注意string sub赋值之后大小会变。
*/
int resolve1137::resolve()
{
	vector<student*> stu_sort;
	map<string, student*>all_stu;
	int p, m, f;
	scanf("%d %d %d", &p, &m, &f);
	int grade;
	for (int i = 0; i < p; i++)
	{
		string id;
		id.resize(21);
		scanf("%s %d", &id[0], &grade);
		id = id.substr(0, strlen(id.c_str()));
		student *s = new student();
		s->id = id;
		s->g_p = grade;
		all_stu[id] = s;
	}
	for (int i = 0; i < m; i++)
	{
		string id;
		id.resize(21);
		scanf("%s %d", &id[0], &grade);
		id = id.substr(0, strlen(id.c_str()));
		map<string, student*>::iterator s = all_stu.find(id);
		if (s != all_stu.end())
		{
			s->second->g_m = grade;
		}
	}
	for (int i = 0; i < f; i++)
	{
		string id;
		id.resize(21);
		scanf("%s %d", &id[0], &grade);
		id = id.substr(0, strlen(id.c_str()));
		map<string, student*>::iterator it = all_stu.find(id);
		if (it != all_stu.end())
		{
			student* s = it->second;
			s->g_f = grade;
			if (s->g_p >= 200)
			{
				if (s->g_m > s->g_f)
				{
					double g_double = (double)s->g_m*0.4 + (double)s->g_f*0.6;
					s->g = g_double*10.0;
					if (s->g % 10 > 4)
					{
						//四舍五入进位
						s->g /= 10;
						s->g++;
					}
					else
					{
						s->g /= 10;
					}
				}
				else
				{
					s->g = s->g_f;
				}
				if (s->g >= 60)
				{
					stu_sort.push_back(s);
				}
			}
		}
	}
	sort(stu_sort.begin(), stu_sort.end(), cmp_stu);
	for (size_t i = 0; i < stu_sort.size(); i++)
	{
		printf("%s %d %d %d %d\n", stu_sort[i]->id.c_str(), stu_sort[i]->g_p, stu_sort[i]->g_m, stu_sort[i]->g_f, stu_sort[i]->g);
	}
	return 0;
}

bool resolve1137::cmp_stu(student * s1, student * s2)
{
	return s1->g == s2->g ? s1->id < s2->id : s1->g > s2->g;
}
