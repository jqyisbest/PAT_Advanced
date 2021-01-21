#include "common.h"
namespace resolve1153
{
	int resolve();
	typedef struct student
	{
		string card_num;
		int score;
		student(string card_num, int score) {
			this->card_num = card_num;
			this->score = score;
		}
	}student;
	typedef struct site
	{
		int site_num, total_num, total_score;
		site(int site_num) {
			this->site_num = site_num;
			this->total_num = 0;
			this->total_score = 0;
		}
	}site;
	bool cmp_student(student *s_1, student *s_2);
	bool cmp_site(site *s_1, site *s_2);
}