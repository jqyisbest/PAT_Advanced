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
*/
int resolve1064::resolve()
{
	int n = 0, h = 0, start=0, end=0;
	vector<int> value, result;
	scanf("%d", &n);
	h = ceil(log(n) / log(2));
	start = 0, end = n;
	while (h>0)
	{
		if (h == 1)
		{
			result.push_back(start);
			result.push_back(end);
		}
		else
		{
			int root = 0;
			//��
			root = get_BST_root(start, end, h);
			result.push_back(root);
			//��
			root = get_BST_root(start, root-1, h-1);
			result.push_back(root);
			//��
			root = get_BST_root(root+1, end, h-1);
			result.push_back(root);
			start+
		}
		h--;
	}
	for (size_t i = 0; i < n; i++)
	{
		printf("%d", result[i]);
	}
	return 0;
}

int resolve1064::get_BST_root(int start, int end, int height)
{
	if (start < end)
	{
		//���һ��Ҷ�ӽڵ�����һ��
		int param = 2 << ((height - 3)>0 ? (height - 3) : 0);
		int n = end - start, k = n + 2 - param * 2, root = n - (n / 2 - k / 2 + (k > param ? k - param : 0));
		return root;
	}
}
