#include "resolve1012.h"

int resolve1012::resolve()
{
	//公布成绩数、查成绩人数
	int num_of_grade, num_of_check;
	cin >> num_of_grade >> num_of_check;
	//ACME四种分数 0-100共计101档
	vector<string>* grades_of_a = new vector<string>[101];
	vector<string>* grades_of_c = new vector<string>[101];
	vector<string>* grades_of_m = new vector<string>[101];
	vector<string>* grades_of_e = new vector<string>[101];
	//录入成绩
	for (int i = 0; i < num_of_grade; ++i)
	{
		string student_id;
		int a = 0, c = 0, m = 0, e = 0;
		cin >> student_id >> c >> m >> e;
		double a_rest = (c + m + e) % 3;
		//平均分四舍五入
		if ((a_rest/3.0) < 0.5)
		{
			a = (c + m + e) / 3;
		}
		else
		{
			a = ((c + m + e) / 3) + 1;
		}
		grades_of_a[a].push_back(student_id);
		grades_of_c[c].push_back(student_id);
		grades_of_m[m].push_back(student_id);
		grades_of_e[e].push_back(student_id);
	}
	//待查询成绩学生
	string* students_check = new string[num_of_check];
	for (int i = 0; i < num_of_check; ++i)
	{
		string student_id_check;
		cin >> student_id_check;
		students_check[i] = student_id_check;
	}
	//查询成绩
	for (int i = 0; i < num_of_check; ++i)
	{
		string student_id_check = students_check[i];
		string rank_best_course = "A";
		int rank_best = find_in_grades(grades_of_a,student_id_check);
		if (rank_best==-1)
		{
			cout << "N/A" ;
		}
		else 
		{
			int rank = num_of_grade;
			//因为优先级ACME，故此处不带=
			if (rank_best > (rank = find_in_grades(grades_of_c, student_id_check))) {
				rank_best = rank;
				rank_best_course = "C";
			}
			if (rank_best > (rank = find_in_grades(grades_of_m, student_id_check))) {
				rank_best = rank;
				rank_best_course = "M";
			}
			if (rank_best > (rank = find_in_grades(grades_of_e, student_id_check))) {
				rank_best = rank;
				rank_best_course = "E";
			}
			cout << rank_best << " " << rank_best_course;
		}
		if (i<(num_of_check - 1))
		{
			cout << endl;
		}
	}
	return 0;
}

int resolve1012::find_in_grades(vector<string>* grade, string student_id)
{
	bool has_found = false;
	int rank = 0;
	for (int i = 100; i >=0; --i)
	{
		for (int j = 0; j < grade[i].size(); ++j)
		{
			if (grade[i][j]== student_id)
			{
				has_found = true;
				break;
			}
		}
		if (has_found)
		{
			return rank + 1;
		}
		else 
		{
			rank += grade[i].size();
		}
	}
	return -1;
}
