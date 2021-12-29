#include "resolve1047.h"
/*
	stl暴力存取 希望不会爆内存
	假定学生姓名不会重复
	好吧。超时。。1000ms都超时。。。
	0
	答案正确
	4 ms	424 KB
	1
	答案正确
	3 ms	424 KB
	2
	答案正确
	3 ms	500 KB
	3
	运行超时
	--	0 KB
	换scanf依旧超时==；
	考虑转为在输入端利用map排序，这样只要排一趟序
	0
	答案正确
	5 ms	548 KB
	1
	答案正确
	4 ms	424 KB
	2
	答案正确
	4 ms	356 KB
	3
	答案正确
	566 ms	54440 KB

	scanf输入string的方法：
	string name;
	name.resize(5);
	scanf("%s %d\n", &name[0], &course_num);
	printf输出string的方法：
	printf("%s\n", string.c_str());
	注意printf遇\n即停止，不要在输出内容里包含\n，是无效的
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
		////读掉换行
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