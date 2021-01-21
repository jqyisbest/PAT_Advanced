#include "resolve1145.h"
/*
	这里的二次方探测法有点特殊，增量k从0取到size-1，不是书上写的size/2
	注意在查找时，当hash地址上的为空时亦可判定该元素不存在

	效率居然比答案老老实实的模拟查找要低？
	好吧，当查找成功时，hash肯定优于红黑树。。
	当查找失败时，我和答案都需要一个个试验。
	总体效率答案优于我。。
*/
int resolve1145::resolve()
{
	int size, n, m;
	scanf("%d %d %d", &size, &n, &m);
	while (!is_prime(size))
	{
		size++;
	}
	map<int, int> shift_times;
	vector<bool> index_used(size, false);
	for (size_t i = 0; i < n; i++)
	{
		int val;
		scanf("%d", &val);
		insert(val, size, index_used, shift_times);
	}
	double total_times = 0.0;
	for (size_t i = 0; i < m; i++)
	{
		int val;
		scanf("%d", &val);
		map<int, int>::iterator it = shift_times.find(val);
		if (it == shift_times.end())
		{
			int index = 0, k = 0;
			while (k < size && index_used[index = (val + k*k) % size])
			{
				k++;
			}
			total_times += k + 1;
		}
		else
		{
			total_times += it->second;
		}
	}
	printf("%.1f", total_times / (double)m);
	return 0;
}

bool resolve1145::is_prime(int num)
{
	if (num == 1)
	{
		return false;
	}
	for (int i = 2; i * i <= num; i++)
	{
		if (num%i == 0)
		{
			return false;
		}
	}
	return true;
}

void resolve1145::insert(int val, const int size, vector<bool>& index_used, map<int, int>& shift_times)
{
	int index = 0;
	int k = 0;
	while (k <= size - 1 && index_used[index = (val + k*k) % size])
	{
		k++;
	}
	if (k == size)
	{
		//没地方插了
		printf("%d cannot be inserted.\n", val);
	}
	else
	{
		index_used[index] = true;
		shift_times[val] = k + 1;
	}
}
