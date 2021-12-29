#include "common.h"
namespace resolve1016 {
	int resolve();
	typedef struct record_raw {
		string name;
		string day_str;
		string hour_str;
		string minute_str;
		int day;
		int hour;
		int minute;
		int action;
	}record_input;
	bool cmp_record(record_input r1, record_input r2);
	string format_money(long cents);
	/**
		计算一天内的通话费
	*/
	long calculate_charge_cents(int* toll_rate,int start_hour,int start_minute, int end_hour, int end_minute);
}