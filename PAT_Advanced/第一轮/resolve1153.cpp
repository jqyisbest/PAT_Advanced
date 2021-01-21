#include "resolve1153.h"
/*
	注意第二种查询和第三种查询里的site是独立的
*/
int resolve1153::resolve()
{
	vector<vector<student *>*> all_student;
	vector<vector<site *>*> all_date_site;
	map<char, vector<student *>> query_1;
	map<int, site *> query_2;
	map<string, vector<site *>> query_3;
	int n, m;
	scanf("%d %d", &n, &m);
	for (size_t i = 0; i < n; i++)
	{
		string card_no;
		int score;
		card_no.resize(13);
		scanf("%s %d", &card_no[0], &score);
		char level = card_no[0];
		int site_num = stoi(card_no.substr(1, 3));
		string today = card_no.substr(4, 6);
		//生成各种查询条件所需要的数据
		//按考试等级查询
		map<char, vector<student *>>::iterator it_1 = query_1.find(level);
		vector<student *> *query_1_stu = nullptr;
		if (it_1 == query_1.end())
		{
			vector<student *> v;
			query_1[level] = v;
			query_1_stu = &query_1[level];
			all_student.push_back(query_1_stu);
		}
		else
		{
			query_1_stu = &query_1[level];
		}
		query_1_stu->push_back(new student(card_no, score));
		//按考场查询
		map<int, site *>::iterator it_2 = query_2.find(site_num);
		site *query_2_site = nullptr;
		if (it_2 == query_2.end())
		{
			query_2_site = new site(site_num);
			query_2[site_num] = query_2_site;
		}
		else
		{
			query_2_site = query_2[site_num];
		}
		query_2_site->total_num++;
		query_2_site->total_score += score;
		//按日期查询考场信息
		map<string, vector<site *>>::iterator it_3 = query_3.find(today);
		vector<site *> *query_3_site = nullptr;
		if (it_3 == query_3.end())
		{
			vector<site *> v;
			query_3[today] = v;
			query_3_site = &query_3[today];
			site *s = new site(site_num);
			s->total_num++;
			s->total_score += score;
			query_3_site->push_back(s);
			all_date_site.push_back(query_3_site);
		}
		else
		{
			query_3_site = &query_3[today];
			//这个考试时间的site数组有了，但是是否有这个site呢？
			if (it_2 == query_2.end())
			{
				//没有这个site
				site *s = new site(site_num);
				s->total_num++;
				s->total_score += score;
				query_3_site->push_back(s);
			}
			else
			{
				site *s = nullptr;
				for (size_t j = 0; j < query_3_site->size(); j++)
				{
					if ((*query_3_site)[j]->site_num == site_num)
					{
						s = (*query_3_site)[j];
						break;
					}
				}
				if (s == nullptr)
				{
					s = new site(site_num);
					query_3_site->push_back(s);
				}
				s->total_num++;
				s->total_score += score;
			}
		}
	}
	for (size_t i = 0; i < all_student.size(); i++)
	{
		sort(all_student[i]->begin(), all_student[i]->end(), cmp_student);
	}
	for (size_t i = 0; i < all_date_site.size(); i++)
	{
		sort(all_date_site[i]->begin(), all_date_site[i]->end(), cmp_site);
	}
	//处理查询
	for (size_t i = 1; i <= m; i++)
	{
		int type;
		scanf("%d", &type);
		printf("Case %d: %d ", i, type);
		if (1 == type)
		{
			string level;
			level.resize(1);
			scanf("%s", &level[0]);
			printf("%s\n", level.c_str());
			map<char, vector<student *>>::iterator it_1 = query_1.find(level[0]);
			if (it_1 == query_1.end())
			{
				printf("NA\n");
			}
			else
			{
				vector<student *> all_s = it_1->second;
				for (size_t j = 0; j < all_s.size(); j++)
				{
					printf("%s %d\n", all_s[j]->card_num.c_str(), all_s[j]->score);
				}
			}
		}
		else if (2 == type)
		{
			int site_num;
			scanf("%d", &site_num);
			printf("%d\n", site_num);
			map<int, site *>::iterator it_2 = query_2.find(site_num);
			if (it_2 == query_2.end())
			{
				printf("NA\n");
			}
			else
			{
				printf("%d %d\n", it_2->second->total_num, it_2->second->total_score);
			}
		}
		else if (3 == type)
		{
			string date;
			date.resize(6);
			scanf("%s", &date[0]);
			printf("%s\n", date.c_str());
			map<string, vector<site *>>::iterator it_3 = query_3.find(date);
			if (it_3 == query_3.end())
			{
				printf("NA\n");
			}
			else
			{
				vector<site *> all_s = it_3->second;
				for (size_t j = 0; j < all_s.size(); j++)
				{
					printf("%d %d\n", all_s[j]->site_num, all_s[j]->total_num);
				}
			}
		}
	}
	return 0;
}

bool resolve1153::cmp_student(student * s_1, student * s_2)
{
	return s_1->score == s_2->score ? s_1->card_num < s_2->card_num : s_1->score>s_2->score;
}

bool resolve1153::cmp_site(site * s_1, site * s_2)
{
	return s_1->total_num == s_2->total_num ? s_1->site_num<s_2->site_num : s_1->total_num > s_2->total_num;
}