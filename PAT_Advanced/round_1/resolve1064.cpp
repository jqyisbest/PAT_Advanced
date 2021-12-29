#include "resolve1064.h"
/*
	��Ϊһ����ȫ���������������乲��n+1���ڵ㣬���h
	��ô���һ�㹲��k���ڵ㣬k=n+2-2^(h-1)
	����keyΪ0-n
	�����һ��ڵ��keyֵΪ0 2 4 6 8...2(k-1)
	�ң��ص㣡������
	����ڵ�keyΪn/2+k/2-(k>2^(h-2)?k-2^(h-2):0)���Ƶ��������£�
	�����ȥ���һ��͸��ڵ㣬������ȫ�������Ķ��壬��������ʣ��ڵ�Ӧ��ͬ����Ϊx
	��2*x+k+1=n+1 ==> 2*x+k=n ==> x=n/2-k/2
	���һ�㱾Ӧ��2^(h-1)���ڵ㣬���������һ��Ӧ��2^(h-2)���ڵ�
	����ʱ�����һ��ʵ����k���ڵ�
	�ʴ�ʱ���������� r ���ڵ㣬r=x+(k>2^(h-2)?k-2^(h-2):0)
	�ָ�����ȫ�������������������Ϊ�������е����ʣ������������ڵ���ȸ��ڵ��
	�ʿ�֪���ڵ�keyֵΪn-r
	�ݴ˹��ɣ����ɵݹ����ÿһ��Ľڵ�keyֵ

	�ص���Ŀ��
	����������keyֵ0-n���������˳�����Ϊ���������������ʱ�������±�
	�ʴ���ⷨ��
	�ȸ����������ݸ���n���ó����յ������������
	�ٽ������������򲢰������������

	�����𰸺���˼·һ���������������Ǵ�end���Ƹ��ڵ㣬���Ǵ�start�����������ĸ������𰸵ĸ�Ϊ�ȶ�
	�����Ҳ�Ӧ��ȥ����ʲô��֦���⣬start==endʱ����һ��Ҳ�޷�
	�������ͣ�
*/
int resolve1064::resolve()
{
	bool print_first = true;
	int n = 0;
	root_node *root = nullptr;
	vector<int> value;
	list<root_node*> root_list;
	scanf("%d", &n);
	value.resize(n);
	for (size_t i = 0; i < n; ++i)
	{
		scanf("%d", &value[i]);
	}
	sort(value.begin(), value.end());
	root = get_BST_root(0, n - 1);
	root_list.push_back(root);
	while (root_list.size() > 0)
	{
		root = root_list.front();
		if (!print_first)
		{
			printf(" ");
		}
		printf("%d", value[root->id]);
		print_first = false;
		if (root->start <= root->id - 1)
		{
			root_list.push_back(get_BST_root(root->start, root->id - 1));
		}
		if (root->id + 1 <= root->end)
		{
			root_list.push_back(get_BST_root(root->id + 1, root->end));
		}
		root_list.pop_front();
	}
	return 0;
}

resolve1064::root_node* resolve1064::get_BST_root(int start, int end)
{
	//heightΪ��ȥ���һ��ĸ߶�
	int n = end - start + 1, height = log(n + 1) / log(2), k = n + 1 - pow(2, height), root = start + (pow(2, height - 1) - 1) + min((int)pow(2, height - 1), k);
	root_node* node = new root_node();
	node->id = root;
	node->start = start;
	node->end = end;
	return node;
}
