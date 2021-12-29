#include "common.h"
namespace resolve1095
{
	int resolve();
	typedef struct record {
		string plate, in_or_out;
		int time;
	}record;
	int get_seconds(int hh, int mm, int ss);
	bool cmp_record(record *r1, record *r2);
}