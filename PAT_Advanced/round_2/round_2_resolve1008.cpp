#include "round_2_resolve1008.h"
using namespace round_2_resolve1008;
#include <bits/stdc++.h>
using namespace std;
int round_2_resolve1008::resolve()
{
	int n = 0, current = 0, next = 0, total_time = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &next);
		int move_time = 0;
		if (current > next)
		{
			move_time += (current - next) * 4;
		}
		else if (current < next)
		{
			move_time += (next - current) * 6;
		}
		total_time += move_time + 5;
		current = next;
	}
	printf("%d", total_time);
	return 0;
}