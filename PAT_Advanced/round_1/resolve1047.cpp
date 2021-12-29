#include "resolve1047.h"
/*
	stl������ȡ ϣ�����ᱬ�ڴ�
	�ٶ�ѧ�����������ظ�
	�ðɡ���ʱ����1000ms����ʱ������
	0
	����ȷ
	4 ms	424 KB
	1
	����ȷ
	3 ms	424 KB
	2
	����ȷ
	3 ms	500 KB
	3
	���г�ʱ
	--	0 KB
	��scanf���ɳ�ʱ==��
	����תΪ�����������map��������ֻҪ��һ����
	0
	����ȷ
	5 ms	548 KB
	1
	����ȷ
	4 ms	424 KB
	2
	����ȷ
	4 ms	356 KB
	3
	����ȷ
	566 ms	54440 KB

	scanf����string�ķ�����
	string name;
	name.resize(5);
	scanf("%s %d\n", &name[0], &course_num);
	printf���string�ķ�����
	printf("%s\n", string.c_str());
	ע��printf��\n��ֹͣ����Ҫ��������������\n������Ч��
*/
int resolve1047::resolve()
{
	int number_of_student = 0, number_of_course = 0, temp = 0;
	scanf("%d %d", &number_of_student, &number_of_course);
	vector<string>* course_stu_lists = new vector<string>[number_of_course + 1];
	map<string, vector<int>> students;
	for (size_t i = 0; i < number_of_student; ++i)
	{
		string name;
		name.resize(5);
		int course_num = 0;
		scanf("%s %d\n", &name[0], &course_num);
		//cin >> name >> course_num;
		////��������
		//getchar();
		for (size_t j = 0; j < course_num; ++j)
		{
			scanf("%d", &temp);
			students[name].push_back(temp);
		}
	}
	for (map<string, vector<int>>::iterator stu = students.begin(); stu != students.end(); ++stu)
	{
		vector<int> course = stu->second;
		for (size_t i = 0; i < course.size(); ++i)
		{
			course_stu_lists[course[i]].push_back(stu->first);
		}
	}
	for (size_t i = 1; i <= number_of_course; ++i)
	{
		printf("%d %d\n", i, course_stu_lists[i].size());
		/*for (set<string>::iterator name = course_stu_lists[i].begin(); name != course_stu_lists[i].end(); ++name)
		{
			printf("%s\n", name->c_str());
		}*/
		for (size_t j = 0; j < course_stu_lists[i].size(); ++j)
		{
			printf("%s\n", course_stu_lists[i][j].c_str());
		}
	}
	return 0;
}