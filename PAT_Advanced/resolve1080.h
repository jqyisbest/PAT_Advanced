#include "common.h"
namespace resolve1080 {
	int resolve();
    typedef struct student
    {
        int id;
        double total,g_e;
        vector<int> choice;
    }student;
    bool cmp_student(student *s1,student *s2);
}