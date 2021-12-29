#include "resolve1099.h"
/*
	����������������������Ǵ�С���������
	�ݴ˵ó�ÿ��ֵ�ͽڵ��ŵĹ�ϵ
	Ȼ���ڰ������������Ĳ�������ı�����ֵ����
*/
int resolve1099::resolve()
{
	int n = 0, index = 0;
	scanf("%d", &n);
	vector<int> *childs = new vector<int>[n];
	vector<int> index_value(n);
	vector<int> real_value(n);
	for (size_t i = 0; i < n; ++i)
	{
		int l = -1, r = -1;
		scanf("%d %d", &l, &r);
		childs[i].push_back(l);
		childs[i].push_back(r);
	}
	for (size_t i = 0; i < n; ++i)
	{
		scanf("%d", &index_value[i]);
	}
	sort(index_value.begin(), index_value.end());
	//��������������ÿ������Ӧ����ʵֵ
	in_order(childs, 0, index, real_value, index_value);
	//��������������
	index = 0;
	queue<int> wait_visited;
	wait_visited.push(0);
	while (wait_visited.size() > 0)
	{
		if (index != 0)
		{
			printf(" ");
		}
		printf("%d", real_value[wait_visited.front()]);
		index++;
		for (size_t i = 0; i < 2; ++i)
		{
			if (childs[wait_visited.front()][i] != -1)
			{
				wait_visited.push(childs[wait_visited.front()][i]);
			}
		}
		wait_visited.pop();
	}
	return 0;
}

void resolve1099::in_order(vector<int>* childs, int root, int & index, vector<int>& real_value, vector<int>& index_value)
{
	if (root == -1)
	{
		return;
	}
	in_order(childs, childs[root][0], index, real_value, index_value);
	real_value[root] = index_value[index++];
	in_order(childs, childs[root][1], index, real_value, index_value);
}
