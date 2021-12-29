#include "resolve1025.h"
/**
	艹，id开始用的 longlong 导致最后一个测试点需要补0。
*/
int resolve1025::resolve()
{
	int number_of_test_locations = 0;
	cin >> number_of_test_locations;
	vector<tester*> all_tester;
	vector<tester*> local_tester;
	for (int i = 0; i < number_of_test_locations; ++i)
	{
		//输入数据
		int number_of_testees = 0;
		cin >> number_of_testees;

		for (int j = 0; j < number_of_testees; ++j)
		{
			tester* t = new tester();
			cin >> t->id >> t->score;
			t->location_number = i + 1;
			local_tester.push_back(t);
			all_tester.push_back(t);
		}
		sort(local_tester.begin(), local_tester.end(), cmp_tester);
		fill_rank(local_tester, true);
		local_tester.clear();
	}
	sort(all_tester.begin(), all_tester.end(), cmp_tester);
	fill_rank(all_tester, false);
	int total_num = all_tester.size();
	cout << total_num-- << endl;
	for (size_t i = 0; i < total_num; ++i)
	{
		cout << all_tester[i]->id << " " << all_tester[i]->rank_all << " " << all_tester[i]->location_number << " " << all_tester[i]->rank_local << endl;
	}
	cout << all_tester[total_num]->id << " " << all_tester[total_num]->rank_all << " " << all_tester[total_num]->location_number << " " << all_tester[total_num]->rank_local;
	return 0;
}

bool resolve1025::cmp_tester(tester* t1, tester* t2)
{
	return t1->score == t2->score ? t1->id < t2->id : t1->score > t2->score;
}

void resolve1025::fill_rank(vector<tester*> testers, bool local)
{
	int rank = -1;
	for (size_t i = 0; i < testers.size(); ++i)
	{
		if (i == 0)
		{
			rank = 1;
		}
		else if (testers[i]->score != testers[i - 1]->score)
		{
			rank = i + 1;
		}
		local ? testers[i]->rank_local = rank : testers[i]->rank_all = rank;
	}
}
