#include "resolve1131.h"
/*
	�����ж�β�ѯ�����Բ����õ�Դ���·���㷨ȥ�����϶���ʱ��
	Ӧ����dfs����׶���٣������sort��Ҫ������
	ÿ��վ����һ���㣬���ʱֻ�����ֹ��ͻ��˵�
	������ָ���Ӧ�Ǿ�����վ������֮��

	ȫ���ڴ泬���ơ���10000*10000������

	�����ĸ�������1345
	4������Ϊ��·�ű����������
	135��������Ϊÿ������վ��һ���ỻ�ߵ��µ�����
	��Ȼ��ˣ��Ǳ��ÿ��վ�Ƿ�Ϊ����վ��û�������ˣ�ֻ�ܸ�����վǰ����·�Ƿ�һ�����ж��Ƿ񻻳�
*/
int resolve1131::resolve()
{
	int n, k;
	scanf("%d", &n);
	map<int, station *> all_station;
	for (size_t i = 1; i <= n; i++)
	{
		int m, last_station = 0, current_station;
		scanf("%d", &m);
		for (size_t j = 0; j < m; j++)
		{
			scanf("%d", &current_station);
			map<int, station*>::iterator it = all_station.find(current_station);
			if (it == all_station.end())
			{
				station* s = new station();
				s->index = current_station;
				all_station[current_station] = s;
			}
			if (j != 0)
			{
				all_station[current_station]->adjacent_station.push_back(all_station[last_station]);
				all_station[last_station]->adjacent_station.push_back(all_station[current_station]);
				all_station[current_station]->station_lines[last_station] = i;
				all_station[last_station]->station_lines[current_station] = i;
			}
			last_station = current_station;
		}
	}
	scanf("%d", &k);
	bool visited[10000];
	for (int i = 0; i < k; i++)
	{
		fill(visited, visited + 10000, false);
		int start_index, end_index;
		solution temp_solution;
		vector<solution*> solutions;
		scanf("%d %d", &start_index, &end_index);

		dfs(visited, -1, all_station[start_index], all_station[end_index], temp_solution, solutions);

		sort(solutions.begin(), solutions.end(), cmp_solution);
		vector<station*> path;
		vector<int> line_num;
		for (int j = 0; j < solutions[0]->all_station.size(); j++)
		{
			if (j == 0 || j == solutions[0]->all_station.size() - 1)
			{
				//���or�յ�
				path.push_back(solutions[0]->all_station[j]);
			}
			else
			{
				//�ж��Ƿ�ת����
				int pre_line = solutions[0]->all_station[j - 1]->station_lines[solutions[0]->all_station[j]->index];
				int next_line = solutions[0]->all_station[j]->station_lines[solutions[0]->all_station[j + 1]->index];
				if (pre_line != next_line)
				{
					path.push_back(solutions[0]->all_station[j]);
					line_num.push_back(pre_line);
				}
			}
		}
		line_num.push_back(solutions[0]->all_station[solutions[0]->all_station.size() - 2]->station_lines[end_index]);
		printf("%d\n", solutions[0]->all_station.size() - 1);
		for (int j = 1; j < path.size(); j++)
		{
			printf("Take Line#%d from %04d to %04d.\n", line_num[j - 1], path[j - 1]->index, path[j]->index);
		}
	}
	return 0;
}

bool resolve1131::cmp_solution(solution * s1, solution * s2)
{
	return s1->all_station.size() == s2->all_station.size() ? s1->transfer_num < s2->transfer_num : s1->all_station.size() < s2->all_station.size();
}

void resolve1131::dfs(bool * visited, int current_line, station * start, station * end, solution & current_solution, vector<solution*>& all_solutions)
{
	visited[start->index] = true;
	current_solution.all_station.push_back(start);
	if (start == end)
	{
		all_solutions.push_back(new solution(current_solution));
	}
	else
	{
		for (int i = 0; i < start->adjacent_station.size(); i++)
		{
			if (!visited[start->adjacent_station[i]->index])
			{
				int next_line = start->station_lines[start->adjacent_station[i]->index];
				if (current_line != -1 && current_line != next_line)
				{
					current_solution.transfer_num++;
				}
				dfs(visited, next_line, start->adjacent_station[i], end, current_solution, all_solutions);
				if (current_line != -1 && current_line != next_line)
				{
					current_solution.transfer_num--;
				}
			}
		}
	}
	//���������̽��ɵ�Ӱ��
	visited[start->index] = false;
	current_solution.all_station.pop_back();
}