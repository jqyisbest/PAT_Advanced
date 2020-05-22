#include "common.h"
namespace resolve1012 {
	int resolve();
	/**
		在某种成绩中查找某位学生的排名
		返回该学生的排名，若不存在，则返回-1
	*/
	int find_in_grades(vector<string>* grade,string student_id);
}