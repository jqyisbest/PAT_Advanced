#include "resolve1141.h"

int resolve1141::resolve()
{
	vector<school*> school_sort;
	map<string, school*>all_school;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		string id, code;
		id.resize(6);
		code.resize(6);
		int score;
		scanf("%s %d %s", &id[0], &score, &code[0]);
		transform(code.begin(), code.end(), code.begin(), ::tolower);
		code = code.substr(0, strlen(code.c_str()));
		map<string, school*>::iterator it = all_school.find(code);
		school* s = nullptr;
		if (it == all_school.end())
		{
			s = new school();
			s->code = code;
			all_school[code] = s;
			school_sort.push_back(s);
		}
		else
		{
			s = it->second;
		}
		s->total_num++;
		if (id[0] == 'T')
		{
			s->total_weight_score += (double)score*1.5;
		}
		else if (id[0] == 'B')
		{
			s->total_weight_score += (double)score / 1.5;
		}
		else
		{
			s->total_weight_score += score;
		}
		s->tws = s->total_weight_score / 1;
	}
	sort(school_sort.begin(), school_sort.end(), cmp_school);
	printf("%d\n", school_sort.size());
	int rank = 1, rank_num = 0;
	for (int i = 0; i < school_sort.size(); i++)
	{
		if (i != 0 && school_sort[i]->tws != school_sort[i - 1]->tws)
		{
			rank += rank_num;
			rank_num = 0;
		}
		printf("%d %s %d %d\n", rank, school_sort[i]->code.c_str(), school_sort[i]->tws, school_sort[i]->total_num);
		rank_num++;
	}
	return 0;
}

bool resolve1141::cmp_school(school * s_1, school * s_2)
{
	return s_1->tws == s_2->tws ? s_1->total_num == s_2->total_num ? s_1->code < s_2->code : s_1->total_num<s_2->total_num : s_1->tws > s_2->tws;
}
