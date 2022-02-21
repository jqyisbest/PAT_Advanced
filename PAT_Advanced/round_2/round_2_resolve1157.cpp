#include "round_2_resolve1157.h"
using namespace round_2_resolve1157;
#include <bits/stdc++.h>
using namespace std;
int round_2_resolve1157::resolve()
{
	set<string> alumnus, guests;
	set<string, cmp_age>alumnus_and_guests;
	int n = 0, m = 0;
	scanf("%d", &n);
	for (size_t i = 0; i < n; i++)
	{
		string id;
		id.resize(18);
		scanf("%s", &id[0]);
		alumnus.insert(id);
	}
	scanf("%d", &m);
	for (size_t i = 0; i < m; i++)
	{
		string id;
		id.resize(18);
		scanf("%s", &id[0]);
		guests.insert(id);
	}
	set_intersection(alumnus.begin(), alumnus.end(), guests.begin(), guests.end(), inserter(alumnus_and_guests, alumnus_and_guests.begin()));
	printf("%d\n", alumnus_and_guests.size());
	if (alumnus_and_guests.size() == 0)
	{
		alumnus_and_guests.insert(guests.begin(), guests.end());
	}
	printf("%s", alumnus_and_guests.begin()->c_str());
	return 0;
}