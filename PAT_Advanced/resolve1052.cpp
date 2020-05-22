#include "resolve1052.h"
/*
	ȡ�ɣ��ѽڵ㵱��һ�ֶ��� Ȼ���Զ���sort����

	!!!��Ȼ����AC������
	0
	����ȷ
	4 ms	384 KB
	1
	�𰸴���
	4 ms	384 KB
	2
	����ȷ
	4 ms	356 KB
	3
	����ȷ
	93 ms	7668 KB
	4
	�𰸴���
	4 ms	384 KB

	���ܴ��ڶ�������ֻ����ָ������
	��ô��ֻҪ�Ѵ�ָ��ͷ�ڵ㿪ʼ�Ľڵ��ַ��¼��������

	?????������ac��
	0
	����ȷ
	4 ms	808 KB
	1
	����ȷ
	4 ms	796 KB
	2
	����ȷ
	4 ms	868 KB
	3
	����ȷ
	108 ms	6516 KB
	4
	�𰸴���
	4 ms	872 KB

	໣��������Ϊ�� ��ʱӦ���0 -1
	0
	����ȷ
	5 ms	808 KB
	1
	����ȷ
	5 ms	864 KB
	2
	����ȷ
	4 ms	808 KB
	3
	����ȷ
	59 ms	6724 KB
	4
	����ȷ
	3 ms	896 KB
*/
int resolve1052::resolve()
{
	int n = 0, temp = 0;
	list_node * node;
	scanf("%d %d", &n, &temp);
	//�ڵ��ַ-����������ӳ��
	int index_add[100000];
	bool linked_add[100000];
	fill(index_add, index_add + 100000, -1);
	fill(linked_add, linked_add + 100000, false);
	vector<list_node*> list;
	for (size_t i = 0; i < n; ++i)
	{
		node = new list_node();
		scanf("%d %d %d", &node->add, &node->key, &node->next);
		list.push_back(node);
		index_add[node->add] = i;
	}
	//���������ۼ�
	n = 0;
	do
	{
		//���һ�����Ե�ͷ�ڵ����-1������������Ϊ��
		if (temp != -1 && index_add[temp] != -1)
		{
			linked_add[temp] = true;
			temp = list[index_add[temp]]->next;
			n++;
		}
	} while (temp != -1);
	if (n != 0)
	{
		sort(list.begin(), list.end(), cmp_node);
		printf("%d ", n);
		//���������������ǰ������ǵڼ���
		temp = 1;
		for (size_t i = 0; i < list.size() && temp <= n; ++i)
		{
			if (linked_add[list[i]->add])
			{
				//�����һ�е�next
				printf("%05d\n%05d %d ", list[i]->add, list[i]->add, list[i]->key);
				if (temp == n)
				{
					printf("-1");
				}
				++temp;
			}
		}
	}
	else
	{
		//һ����û�У���Ӧ���һ�����Ե�
		printf("0 -1");
	}
	return 0;
}

bool resolve1052::cmp_node(list_node * node_1, list_node * node_2)
{
	return node_1->key < node_2->key;
}
