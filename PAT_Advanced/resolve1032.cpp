#include "resolve1032.h"
/*
	��ÿ���ڵ�ֻ��һ����̿�֪����һ������ͬ��̵Ľڵ㣬�Ǹ���̽ڵ㼴Ϊ����
	����������ʽ��¼ÿһ���ڵ��Ƿ�����Ϊ���˵ĺ��
	��һ���������ڵ㵱���Ǻ�̵Ľڵ��������ڵ�
	����֣����˼·������ȫ������
	˼·2����ȫ���ڵ���£�������һ�����ʲ���Ǹ��ڴ��ַ��ʹ��
	�����ڶ������ʣ������ڴ��ַ��ʹ�ã���������ڴ��ַ
	�ţ��������Ե��Ļ��ǹ����ˣ�����
	�������������������ʽ�����Ǵ�λ��Ҫ���id��������printf������
*/
int resolve1032::resolve()
{
	bool*has_been_used = new bool[100000];
	fill(has_been_used, has_been_used + 100000, false);
	//ÿ���ڵ�ĺ������
	int* next= new int[100000];
	fill(next, next + 100000, -1);
	int temp ,word_1_start,word_2_start, number_of_nodes,current_add = 0;
	scanf("%d %d %d", &word_1_start, &word_2_start, &number_of_nodes);
	for (size_t i = 0; i < number_of_nodes; ++i)
	{
		scanf("%d %c %d", &current_add, &temp, &temp);
		next[current_add] = temp;
	}
	//��ǵ�һ�����ʵ�ÿһ���ڵ�
	current_add = word_1_start;
	do
	{
		has_been_used[current_add] = true;
		current_add = next[current_add];
	} while (-1!=next[current_add]);
	//�����ڶ������ʣ�����û��ʹ������ͬ�ڴ��ַ��
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
