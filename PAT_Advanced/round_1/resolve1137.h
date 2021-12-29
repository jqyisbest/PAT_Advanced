#include "common.h"
namespace resolve1137 {
	int resolve();
	typedef struct student {
		string id;
		int g_p, g_m, g_f, g;
		student() {
			g_p = g_m = g_f = g = -1;
		}
	}student;
	bool cmp_stu(student *s1, student *s2);
}