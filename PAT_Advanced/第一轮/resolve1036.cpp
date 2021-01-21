#include "resolve1036.h"

/*
	测试点1、0中存在名字为空的数据 
	故不能用name或ID来判断该分数有无学生，需专门标志位
*/
int resolve1036::resolve()
{
	int record_num = 0;
	cin >> record_num;
	record* records = new record[101];
	for (size_t i = 0; i < 101;++i)
	{
		records[i].has_student = false;
	}
	for (size_t i = 0; i < record_num; ++i)
	{
		string name, gender, id;
		cin >> name >> gender >> id;
		int grade = 0;
		cin >> grade;
		records[grade].id = id;
		records[grade].name = name;
		records[grade].male = gender == "M";
		records[grade].has_student = true;
	}
	int grade_f=-1, grade_m = -1;
	for (int i = 100; i >=0; --i)
	{
		if (records[i].has_student) {
			if (records[i].male)
			{
				grade_m = i;
			}
			else if (grade_f == -1)
			{
				grade_f = i;
			}
		}
	}
	cout << (grade_f == -1 ? "Absent" : records[grade_f].name + " " + records[grade_f].id) << endl;
	cout << (grade_m == -1 ? "Absent" : records[grade_m].name + " " + records[grade_m].id) << endl;
	cout << ((grade_f == -1|| grade_m == -1)? "NA" :to_string(grade_f- grade_m));
	return 0;
}
