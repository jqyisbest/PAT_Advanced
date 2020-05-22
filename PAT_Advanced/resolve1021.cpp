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

	�������ҵ��죬��Ȼ�������Ϊstl����̫��ε��³�ʱ����vector<vector<int>> nodes��Ϊȫ�ֱ����͹��ˡ�ү���ˡ�
	0
	����ȷ
	3 ms	404 KB
	1
	����ȷ
	4 ms	300 KB
	2
	����ȷ
	5 ms	384 KB
	3
	����ȷ
	35 ms	1536 KB
	4
	����ȷ
	3 ms	424 KB
	5
	����ȷ
	3 ms	364 KB

	�ܽ�һ��AC�Ĺؼ��㣺
	1��dfs������������
	2��stl�����������ٵĿ������ݣ�����֮�أ������������Լ����뷨Ҳ���ܹ���/(��o��)/~~��

	���Ե�һ�汩������ÿһ���ڵ���뷨�������ڽ�vector<vector<int>> nodes��Ϊȫ�ֱ�����ʱ�������٣����Ե�3�ӳ�ʱ����ڴ泬��

	��ÿһ���ڵ���Ϊ���ڵ��ѭ�����visited�������ѭ�����AC�ˣ�ԭ���������ͷ��ڴ棬javaдϰ������Ϊ��GC��/(��o��)/~~ 
	0
	����ȷ
	4 ms	424 KB
	1
	����ȷ
	4 ms	356 KB
	2
	����ȷ
	5 ms	424 KB
	3
	����ȷ
	1183 ms	1092 KB
	4
	����ȷ
	4 ms	424 KB
	5
	����ȷ
	4 ms	424 KB
	
	�����ǵ�һ��Ĵ��룬û�н���κ��˴����Լ����뷨

	#include <iostream>
	#include <math.h>
	#include <string>
	#include <algorithm>
	#include <list>
	#include <vector>
	#include <set>
	#include <map>
	#include <iomanip>
	using namespace std;
	vector<vector<int>> nodes;
	void dfs(int root, int * visited)
	{
	visited[root] = 1;
	for (int i = 0; i < nodes[root].size(); ++i)
	{
	if (visited[nodes[root][i]] == 0)
	{
	dfs(nodes[root][i], visited);
	}
	}
	}

	void dfs(int root,int* visited, int height,int* max_height)
	{
	visited[root] = 1;
	if (height>(*max_height))
	{
	*(max_height) = height;
	}
	for (int i = 0; i < nodes[root].size(); ++i)
	{
	if (visited[nodes[root][i]] == 0)
	{
	dfs(nodes[root][i], visited, height+1,max_height);
	}
	}
	}

	int main()
	{
	int num_of_nodes = 0;
	cin >> num_of_nodes;
	if (1==num_of_nodes)
	{
	cout << "1";
	}
	else {
	nodes.resize(num_of_nodes+1);
	for (size_t i = 0; i < num_of_nodes-1; ++i)
	{
	int vertex_1 = 0, vertex_2 = 0;
	cin >> vertex_1 >> vertex_2;
	nodes[vertex_1].push_back(vertex_2);
	nodes[vertex_2].push_back(vertex_1);
	}
	//��������
	int max_height = 0;
	//��������ĸ�
	vector<int> deepest_roots;
	int* visited = new int[num_of_nodes + 1];
	for (size_t root = 1; root < num_of_nodes+1; ++root)
	{
	int current_height = 0;
	fill(visited, visited + num_of_nodes + 1, 0);
	//��k�־���k����ͨ��ͼ
	size_t k = 0;
	for (; k < num_of_nodes; ++k)
	{
	int current_node = -1;
	for (size_t j = 1; -1 == current_node&&j < num_of_nodes+1; ++j)
	{
	if (visited[j] == 0) {
	current_node = j;
	}
	}
	if (-1 == current_node)
	{
	break;
	}
	if (k == 0)
	{
	//��һ�֣������
	dfs(root, visited, 1, &current_height);
	}
	else {
	//dfs
	dfs(current_node, visited);
	}
	}
	if (k == 1)
	{
	if (max_height<current_height)
	{
	max_height = current_height;
	deepest_roots.clear();
	deepest_roots.push_back(root);
	}
	else if (max_height==current_height)
	{
	deepest_roots.push_back(root);
	}
	}
	else
	{
	cout << "Error: " << k << " components";
	return 0;
	}
	}
	sort(deepest_roots.begin(), deepest_roots.end());
	for (size_t i = 0; i < deepest_roots.size() - 1; ++i)
	{
	cout << deepest_roots[i] << endl;
	}
	cout << deepest_roots[deepest_roots.size() - 1];
	}
	return 0;
	}
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
		nodes.resize(num_of_nodes + 1);
		for (size_t i = 0; i < num_of_nodes - 1; ++i)
		{
			int vertex_1 = 0, vertex_2 = 0;
			cin >> vertex_1 >> vertex_2;
			nodes[vertex_1].push_back(vertex_2);
			nodes[vertex_2].push_back(vertex_1);
		}
		//�������ȡ���ͨ������
		int max_height = 0, k = 0;
		int* visited = new int[num_of_nodes + 1];
		fill(visited, visited + num_of_nodes + 1, 0);
		//�����߶�����Ľڵ�
		set<int> deepest_nodes;
		vector<int> current_deepest_nodes;
		for (int i = 1; i < num_of_nodes + 1; i++)
		{
			if (visited[i] == 0)
			{
				if (0 == k)
				{
					dfs(i, visited, 1, &max_height, &current_deepest_nodes);
				}
				else
				{
					dfs(i, visited);
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
			dfs(current_deepest_nodes[0], visited, 1, &max_height, &current_deepest_nodes);
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

void resolve1021::dfs(int root, int * visited)
{
	visited[root] = 1;
	for (int i = 0; i < nodes[root].size(); ++i)
	{
		if (visited[nodes[root][i]] == 0)
		{
			dfs(nodes[root][i], visited);
		}
	}
}

void resolve1021::dfs(int root, int* visited, int height, int* max_height, vector<int>* deepest_nodes)
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
			dfs(nodes[root][i], visited, height + 1, max_height, deepest_nodes);
		}
	}
}