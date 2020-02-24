#include "resolve1021.h"
/**
	����DFS
	��һ������ȡ�����һ�ֽ���������δ���ʽڵ㣬�����DFS������ͨ��ͼ����K

	0
	����ȷ
	5 ms	424 KB
	1
	����ȷ
	5 ms	424 KB
	2
	����ȷ
	64 ms	644 KB
	3
	���г�ʱ
	--	0 KB
	4
	����ȷ
	5 ms	512 KB
	5
	����ȷ
	5 ms	424 KB

	�ֳ�ʱ��== ��һ�γ�ʱҲ����ͼ�����
	��ѭ����num_of_nodes*num_of_nodes*num_of_nodes �ڲ㻹�еݹ�

	��ѭ����Ϊ��num_of_nodes*num_of_nodes + �ڲ�dfs �����ɳ�ʱ
	�������������ͨͼʱ��Ҫnum_of_nodes��dfs��

	Ϊɶ���˵Ĵ���˵���������������������

	!!!�����ˡ�����һ���޻���ͨͼ���ԣ����·��������Ψһȷ���ģ�����˵·��Ψһ��
	��ô���������������·�������� 1->2->***->5 ��1->3->***>6
	�Ҷ������·���ϵ�������ֹ�㣬�ǿ��Ի����ģ�����϶��� 6->***->1
	���ԣ�1��ֻҪ�ҵ�һ���·������㣬��ô���ҵ����������·������㣨����û��Ҫ��ÿһ�������ȥ�ԣ�
	��    2��������һ��������õ��ľֲ��·�����յ㣬һ����ȫ���·������ֹ�㣡�����������÷�֤��֤����
	���������㡢ֻ���ȴ�����һ��A dfsһ�Σ��ٴӵ�һ�ε��յ���������ɵõ�����ȫ���·������ֹ�㣨�Ҹо���Ҫ���ж�A�ǲ�����ֹ�㣩
	���ҶȲ�Ψ1�Ľڵ�һ�������·������ֹ�㣡����
	�������ö��������ܲ��ܹ��ɡ�

	Ŷ���ö��Ƿ�Ϊ1ȥ���˻��ǳ�ʱ�����������Ե�3�����ָ߶Ȳ��ߵ���֧����ģ����Ե�2���ǿ���ʮ��

	���ڰ��������û���ѱ��˵�˼·�r(�s���t)�q
	!!!���ǳ�ʱ ����ѭ��2*num_of_nodes����ʱ�𣿣���
	woc ����dfs����ʱ��˵ʵ���е�����
	0
	����ȷ
	3 ms	400 KB
	1
	����ȷ
	3 ms	424 KB
	2
	����ȷ
	62 ms	512 KB
	3
	���г�ʱ
	--	0 KB
	4
	����ȷ
	4 ms	384 KB
	5
	����ȷ
	4 ms	432 KB
*/
int resolve1021::resolve()
{
	int num_of_nodes = 0;
	cin >> num_of_nodes;
	if (1 == num_of_nodes)
	{
		cout << "1";
	}
	else {
		vector<vector<int>> nodes;
		nodes.resize(num_of_nodes + 1);
		for (size_t i = 0; i < num_of_nodes - 1; ++i)
		{
			int vertex_1 = 0, vertex_2 = 0;
			cin >> vertex_1 >> vertex_2;
			nodes[vertex_1].push_back(vertex_2);
			nodes[vertex_2].push_back(vertex_1);
		}
		//�������ȡ���ͨ������
		int max_height=0,k= 0;
		int* visited = new int[num_of_nodes + 1];
		fill(visited, visited + num_of_nodes + 1, 0);
		//�����߶�����Ľڵ�
		set<int> deepest_nodes;
		vector<int> current_deepest_nodes;
		for (int i = 1; i < num_of_nodes+1; i++)
		{
			if (visited[i] == 0)
			{
				if (0==k)
				{
					dfs(i, visited, nodes, 1, &max_height, &current_deepest_nodes);
				}
				else
				{
					dfs(i, visited, nodes);
				}
				++k;
			}
		}
		if (k == 1)
		{
			for (size_t j = 0; j < current_deepest_nodes.size(); ++j)
			{
				deepest_nodes.insert(current_deepest_nodes[j]);
			}
			fill(visited, visited + num_of_nodes + 1, 0);
			dfs(*(deepest_nodes.begin()), visited, nodes, 1, &max_height, &current_deepest_nodes);
			for (size_t j = 0; j < current_deepest_nodes.size(); ++j)
			{
				deepest_nodes.insert(current_deepest_nodes[j]);
			}
			int i = 0;
			for (set<int>::iterator it = deepest_nodes.begin(); it != deepest_nodes.end(); it++)
			{
				cout << *it;
				if (i != deepest_nodes.size() - 1)
				{
					cout << endl;
					++i;
				}
			}
		}
		else
		{
			cout << "Error: " << k << " components";
		}
	}
	return 0;
}

void resolve1021::dfs(int root, int * visited, vector<vector<int>> nodes)
{
	visited[root] = 1;
	for (int i = 0; i < nodes[root].size(); ++i)
	{
		if (visited[nodes[root][i]] == 0)
		{
			dfs(nodes[root][i], visited, nodes);
		}
	}
}

void resolve1021::dfs(int root, int* visited, vector<vector<int>> nodes, int height, int* max_height, vector<int>* deepest_nodes)
{
	visited[root] = 1;
	if (height > (*max_height))
	{
		*(max_height) = height;
		deepest_nodes->clear();
		deepest_nodes->push_back(root);
	}
	else if (height == (*max_height))
	{
		deepest_nodes->push_back(root);
	}
	for (int i = 0; i < nodes[root].size(); ++i)
	{
		if (visited[nodes[root][i]] == 0)
		{
			dfs(nodes[root][i], visited, nodes, height + 1, max_height, deepest_nodes);
		}
	}
}