#include "round_2_resolve1156.h"
using namespace round_2_resolve1156;
#include <bits/stdc++.h>
using namespace std;
bool round_2_resolve1156::is_prime(int a)
{
	if (a < 2)
	{
		return false;
	}
	for (int i = 2; i*i <= a; i++)
	{
		if (a%i == 0)
		{
			return false;
		}
	}
	return true;
}
int round_2_resolve1156::resolve()
{
	int a = 0;
	scanf("%d", &a);
	if (is_prime(a))
	{
		if (is_prime(a - 6))
		{
			printf("Yes\n%d", a - 6);
			return 0;
		}
		if (is_prime(a + 6))
		{
			printf("Yes\n%d", a + 6);
			return 0;
		}
	}
	printf("No\n");
	do
	{
		a++;
	} while (!is_prime(a) || (!is_prime(a - 6) && !is_prime(a + 6)));
	printf("%d", a);
	return 0;
}