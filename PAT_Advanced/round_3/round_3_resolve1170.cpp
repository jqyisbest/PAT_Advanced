#include "round_3_resolve1170.h"
using namespace round_3_resolve1170;
#include <bits/stdc++.h>
using namespace std;
int round_3_resolve1170::resolve()
{
	int n = 0, r = 0, k = 0, m = 0;
	cin >> n >> r >> k;
	vector<pair<int, int>*> relations;
	for (int i = 0; i < r; i++)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		pair<int, int>* p = new pair<int, int>();
		p->first = a;
		p->second = b;
		relations.push_back(p);
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		set<int> species;
		vector<int> animals;
		for (int j = 0; j < n; j++)
		{
			int animal = 0;
			cin >> animal;
			species.insert(animal);
			animals.push_back(animal);
		}
		if (species.size() == k)
		{
			bool yes_no = true;
			for (int j = 0; j < r&&yes_no; j++)
			{
				if (animals[relations[j]->first - 1] == animals[relations[j]->second - 1])
				{
					yes_no = false;
				}
			}
			cout << (yes_no ? "Yes\n" : "No\n");
		}
		else
		{
			cout << "Error: Too " << (species.size() < k ? "few" : "many") << " species.\n";
		}
	}
	return 0;
}