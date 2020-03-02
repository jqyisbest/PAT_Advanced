#include "resolve1032.h"
/*
	由每个节点只有一个后继可知，第一个出现同后继的节点，那个后继节点即为所求
	故以数组形式记录每一个节点是否已作为别人的后继
	第一个被两个节点当作是后继的节点就是所求节点
	很奇怪，这个思路过不了全部测试
	思路2：将全部节点存下，遍历第一个单词并标记该内存地址已使用
	遍历第二个单词，若该内存地址已使用，则输出该内存地址
	嗯？？？测试点四还是过不了？？？
	啊啊啊啊啊又是输出格式，又是带位数要求的id！！！用printf！！！
*/
int resolve1032::resolve()
{
	bool*has_been_used = new bool[100000];
	fill(has_been_used, has_been_used + 100000, false);
	//每个节点的后继数组
	int* next= new int[100000];
	fill(next, next + 100000, -1);
	int temp ,word_1_start,word_2_start, number_of_nodes,current_add = 0;
	scanf("%d %d %d", &word_1_start, &word_2_start, &number_of_nodes);
	for (size_t i = 0; i < number_of_nodes; ++i)
	{
		scanf("%d %c %d", &current_add, &temp, &temp);
		next[current_add] = temp;
	}
	//标记第一个单词的每一个节点
	current_add = word_1_start;
	do
	{
		has_been_used[current_add] = true;
		current_add = next[current_add];
	} while (-1!=next[current_add]);
	//遍历第二个单词，看有没有使用了相同内存地址的
	current_add = word_2_start;
	do
	{
		if (has_been_used[current_add])
		{
			printf("%05d",current_add);
			return 0;
		}
		current_add = next[current_add];
	} while (-1 != next[current_add]);
	cout << "-1";
	return 0;
}
