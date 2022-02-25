#include "round_2_resolve1160.h"
using namespace round_2_resolve1160;
#include <bits/stdc++.h>
using namespace std;
int round_2_resolve1160::sum(int num)
{
	int k = 0;
	while (num != 0)
	{
		k += num % 10;
		num /= 10;
	}
	return k;
}
void round_2_resolve1160::get_primes(bool * is_prime)
{
	is_prime[0] = false;
	is_prime[1] = false;
	is_prime[2] = false;
	for (size_t i = 3; i < 90; i++)
	{
		for (size_t j = 2; j <= i / 2; ++j)
		{
			if (i % j == 0)
			{
				is_prime[i] = false;
				break;
			}
		}
	}
}
int round_2_resolve1160::gcd(int a, int b)
{
	if (a == b)
	{
		return a;
	}
	else if (a < b)
	{
		//保证大的为a
		return gcd(b, a);
	}
	else
	{
		//判断奇偶
		if (a & 1 && b & 1)
		{
			//更相减损术
			return gcd(a - b, b);
		}
		else if (!(a & 1) && (b & 1))
		{
			return gcd(a >> 1, b);
		}
		else if ((a & 1) && !(b & 1))
		{
			return gcd(a, b >> 1);
		}
		else
		{
			return gcd(a >> 1, b >> 1) << 1;
		}
	}
	return 0;
}
int round_2_resolve1160::resolve()
{
	bool is_prime[90];
	fill(is_prime, is_prime + 90, true);
	get_primes(is_prime);
	int n = 0, k = 0, a = 0;
	scanf("%d\n", &n);
	for (size_t i = 0; i < n; i++)
	{
		printf("Case %d\n", i + 1);
		scanf("%d %d", &k, &a);
		if (a > k * 9)
		{
			printf("No Solution\n");
			continue;
		}
		map<int, vector<int>> solution;
		for (int t = pow(10, k - 3); t < pow(10, k - 2) - 1; t++)
		{
			//用于降低时间复杂度
			int A = t * 100 + 99;
			if (sum(A) == a)
			{
				int b = sum(A + 1);
				if (is_prime[gcd(a, b)])
				{
					solution[b].push_back(A);
				}
			}
		}
		if (solution.size() == 0)
		{
			printf("No Solution\n");
		}
		else
		{
			for (auto it = solution.begin(); it != solution.end(); it++)
			{
				for (size_t j = 0; j < it->second.size(); j++)
				{
					printf("%d %d\n", it->first, it->second[j]);
				}
			}
		}
	}
	return 0;
}