#include "resolve1109.h"

int resolve1109::resolve()
{
	int n = 0, k = 0;
	scanf("%d %d", &n, &k);
	int m = n / k;
	vector<vector<person*>> rows;
	vector<person*> all_people;
	for (int i = 0; i < n; i++)
	{
		person *p = new person();
		scanf("%s %d", &p->name[0], &p->height);
		all_people.push_back(p);
	}
	sort(all_people.begin(), all_people.end(), cmp_person);
	for (int i = 0; i < k - 1; ++i)
	{
		rows.push_back(get_row(all_people, m*i, m*i + m - 1));
	}
	rows.push_back(get_row(all_people, m*(k - 1), n - 1));
	for (int i = k - 1; i >= 0; i--)
	{
		for (int j = 0; j < rows[i].size(); j++)
		{
			if (j != 0)
			{
				printf(" ");
			}
			printf("%s", rows[i][j]->name.c_str());
		}
		printf("\n");
	}
	return 0;
}

bool resolve1109::cmp_person(person * p1, person * p2)
{
	return p1->height == p2->height ? p1->name > p2->name : p1->height < p2->height;
}

vector<resolve1109::person*> resolve1109::get_row(vector<person*>& all_people, int start, int end)
{
	int m = end - start + 1, additional = -1;
	int center_index = m / 2;
	vector<person*> row(m);
	row[center_index] = all_people[end];
	for (int i = end - 1; i >= start; i--)
	{
		//先右后左，对应数组就是先-1再加1；
		row[center_index + additional] = all_people[i];
		if (additional > 0)
		{
			additional++;
		}
		additional = -additional;
	}
	return row;
}
