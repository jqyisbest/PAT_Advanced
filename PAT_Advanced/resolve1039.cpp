#include "resolve1039.h"
/*
	stl�����ܻ��ڴ泬��
	
	Ŷ�����г�ʱ
	0
	����ȷ
	3 ms	428 KB
	1
	����ȷ
	3 ms	424 KB
	2
	����ȷ
	4 ms	352 KB
	3
	����ȷ
	4 ms	384 KB
	4
	����ȷ
	3 ms	540 KB
	5
	���г�ʱ
	--	0 KB

	cin��ʱ������scanf�����벻���ַ���
	������תΪint 4λ��Ȩ�� 26~3 2 1 + digit

	0
	����ȷ
	5 ms	356 KB
	1
	����ȷ
	5 ms	360 KB
	2
	����ȷ
	5 ms	384 KB
	3
	����ȷ
	4 ms	256 KB
	4
	����ȷ
	5 ms	256 KB
	5
	����ȷ
	408 ms	40360 KB
*/
int resolve1039::resolve()
{
	int num_of_query = 0, num_of_course = 0;
	scanf("%d %d", &num_of_query, &num_of_course);
	map<long, set<int>> student_course;
	int course_index = 0, num_of_student = 0,weight_2=26, weight_1 = 26* weight_2, weight_0 = 26* weight_1;
	char* student_name=new char[4];
	long student_long = 0;
	for (size_t i = 0; i < num_of_course; ++i)
	{
		scanf("%d %d", &course_index, &num_of_student);
		for (size_t j = 0; j < num_of_student; ++j)
		{
			scanf("%s", student_name);
			student_long = (student_name[0] - 'A')*weight_0 + (student_name[1] - 'A') * weight_1 + (student_name[2] - 'A') *weight_2 + (student_name[3] - '0');
			student_course[student_long].insert(course_index);
		}
	}
	//��ѯ
	for (size_t i = 0; i < num_of_query; ++i)
	{
		scanf("%s", student_name);
		student_long = (student_name[0] - 'A')*weight_0 + (student_name[1] - 'A') * weight_1 + (student_name[2] - 'A') *weight_2 + (student_name[3] - '0');
		cout << student_name << " " << student_course[student_long].size();
		for (set<int>::iterator course_index = student_course[student_long].begin(); course_index!= student_course[student_long].end(); ++course_index)
		{
			cout << " " << *course_index;
		}
		if (i!=num_of_query-1)
		{
			cout << endl;
		}
	}
	return 0;
}
