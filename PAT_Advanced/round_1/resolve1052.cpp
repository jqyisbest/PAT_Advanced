#include "resolve1052.h"
/*
	取巧，把节点当成一种对象 然后自定义sort方法

	!!!居然不是AC？？？
	0
	答案正确
	4 ms	384 KB
	1
	答案错误
	4 ms	384 KB
	2
	答案正确
	4 ms	356 KB
	3
	答案正确
	93 ms	7668 KB
	4
	答案错误
	4 ms	384 KB

	可能存在多条链表，只排序指定链表
	那么我只要把从指定头节点开始的节点地址记录下来即可

	?????还不是ac？
	0
	答案正确
	4 ms	808 KB
	1
	答案正确
	4 ms	796 KB
	2
	答案正确
	4 ms	868 KB
	3
	答案正确
	108 ms	6516 KB
	4
	答案错误
	4 ms	872 KB

	嗷，链表可能为空 此时应输出0 -1
	0
	答案正确
	5 ms	808 KB
	1
	答案正确
	5 ms	864 KB
	2
	答案正确
	4 ms	808 KB
	3
	答案正确
	59 ms	6724 KB
	4
	答案正确
	3 ms	896 KB
*/
int resolve1052::resolve()
{
	int n = 0, temp = 0;
	list_node * node;
	scanf("%d %d", &n, &temp);
	//节点地址-数组索引的映射
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
	//用于总数累计
	n = 0;
	do
	{
		//最后一个测试点头节点给的-1，待排序链表为空
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
		//用于输出计数，当前输出的是第几个
		temp = 1;
		for (size_t i = 0; i < list.size() && temp <= n; ++i)
		{
			if (linked_add[list[i]->add])
			{
				//输出上一行的next
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
		//一个都没有，对应最后一个测试点
		printf("0 -1");
	}
	return 0;
}

bool resolve1052::cmp_node(list_node * node_1, list_node * node_2)
{
	return node_1->key < node_2->key;
}
