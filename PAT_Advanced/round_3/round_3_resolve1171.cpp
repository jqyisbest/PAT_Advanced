#include "round_3_resolve1171.h"
using namespace round_3_resolve1171;
#include <bits/stdc++.h>
using namespace std;
void round_3_resolve1171::print_run(queue<int>& run)
{
	if (run.empty())
	{
		return;
	}
	bool need_space = false;
	while (run.size() != 0)
	{
		cout << (need_space ? " " : "") << run.front();
		run.pop();
		if (!need_space)
		{
			need_space = true;
		}
	}
	cout << endl;
}
int round_3_resolve1171::resolve()
{
	int total_num = 0, size_limit = 0;
	cin >> total_num >> size_limit;
	queue<int> current_run;
	priority_queue<int, vector<int>, greater<int>> memory;
	vector<int> next_run;//缓存一下下一轮次的数据
	for (int i = 0; i < total_num; i++)
	{
		int num = 0;
		cin >> num;
		if (i < size_limit)
		{
			memory.push(num);
		}
		else
		{
			int current_min = memory.top();
			current_run.push(current_min);
			memory.pop();
			if (num > current_min)
			{
				memory.push(num);
			}
			else
			{
				next_run.push_back(num);
			}
			if (memory.empty())
			{
				//当前轮次结束 输出结果并清空缓存区
				print_run(current_run);
				for (int a : next_run)
				{
					memory.push(a);
				}
				next_run.clear();
			}
		}
	}
	while (!memory.empty())
	{
		current_run.push(memory.top());
		memory.pop();
	}
	print_run(current_run);
	for (int a : next_run)
	{
		memory.push(a);
	}
	while (!memory.empty())
	{
		current_run.push(memory.top());
		memory.pop();
	}
	print_run(current_run);
	return 0;
}