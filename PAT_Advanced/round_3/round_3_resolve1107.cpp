#include "round_3_resolve1107.h"

int round_3_resolve1107::find_father(int a, map<int, int>& fathers)
{
	return fathers[a] == a ? a : fathers[a] = find_father(fathers[a], fathers);
}

void round_3_resolve1107::union_father(int a, int b, int *childs_num, map<int, int>& fathers)
{
	int a_f = find_father(a, fathers);
	int b_f = find_father(b, fathers);
	if (a_f != b_f)
	{
		if (childs_num[a_f] <= childs_num[b_f])
		{
			fathers[a_f] = b_f;
			childs_num[b_f] += childs_num[a_f];
			childs_num[a_f] = 1;
		}
		else
		{
			fathers[b_f] = a_f;
			childs_num[a_f] += childs_num[b_f];
			childs_num[b_f] = 1;
		}
	}
}

int round_3_resolve1107::resolve()
{
	int n = 0;
	scanf("%d", &n);
	int *childs_num = new int[n];
	map<int, int> fathers;
	map<int, vector<int>> same_hobbies_people;
	for (int i = 0; i < n; i++)
	{
		fathers[i] = i;
		childs_num[i] = 1;
		int num_of_hobbies = 0;
		scanf("%d:", &num_of_hobbies);
		for (int j = 0; j < num_of_hobbies; j++)
		{
			int index_of_hobby = 0;//index start from 1
			scanf("%d", &index_of_hobby);
			same_hobbies_people[index_of_hobby].push_back(i);
		}
	}
	for (map<int, vector<int>>::iterator it = same_hobbies_people.begin(); it != same_hobbies_people.end(); it++)
	{
		vector<int> people_in_same_hobby = it->second;
		for (int i = 0; i < people_in_same_hobby.size() - 1; i++)
		{
			union_father(people_in_same_hobby[i], people_in_same_hobby[i + 1], childs_num, fathers);
		}
	}
	vector<int>result;
	for (int i = 0; i < n; i++)
	{
		if (childs_num[i] > 1 || i == find_father(i, fathers))
		{
			result.push_back(childs_num[i]);
		}
	}
	sort(result.begin(), result.end());
	printf("%d\n", result.size());
	for (int i = result.size() - 1; i >= 0; i--)
	{
		printf("%d", result[i]);
		if (i != 0)
		{
			printf(" ");
		}
	}
	return 0;
}
