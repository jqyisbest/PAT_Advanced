#include "resolve1121.h"

int resolve1121::resolve()
{
	int n = 0, m = 0;
	scanf("%d", &n);
	map<int, int>couple;
	for (size_t i = 0; i < n; i++)
	{
		int a = 0, b = 0;
		scanf("%d %d", &a, &b);
		couple[a] = b;
		couple[b] = a;
	}
	scanf("%d", &m);
	bool attend_party[100000];
	set<int> attend_people;
	vector<int> single;
	fill(attend_party, attend_party + 100000, false);
	for (size_t i = 0; i < m; i++)
	{
		int id = 0;
		scanf("%d", &id);
		attend_party[id] = true;
		attend_people.insert(id);
	}
	for (set<int>::iterator i = attend_people.begin(); i != attend_people.end(); i++)
	{
		if (couple.count(*i) == 0 || (!attend_party[couple[*i]]))
		{
			single.push_back(*i);
		}
	}
	printf("%d\n", single.size());
	for (size_t i = 0; i < single.size(); i++)
	{
		if (i != 0)
		{
			printf(" ");
		}
		printf("%05d", single[i]);
	}
	return 0;
}
