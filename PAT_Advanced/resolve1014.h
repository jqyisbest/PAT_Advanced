#include "common.h"
namespace resolve1014 {
	int resolve();
	typedef struct customer{
		//服务耗时（分钟）
		int minutes_cost;
		//所处于的队列号
		int line_num;
		//该名顾客开始办理的时刻，从8:00算起
		int minutes_service_start;
		//该名顾客办结时的时刻，从8:00算起
		int minutes_service_finished;
	}customer;
	typedef struct service_line {
		//队列当前可进人数
		int capacity_available;
		//队列中最后一位客户结束服务的时刻，从8:00算起，若超过541=(17-8)*60+1(分钟)，则该队列将无法继续服务
		int last_finish_minutes;
	}service_line;
	/**
		将8点起的偏移分钟数转为时间（HH:MM）以显示
		大于540直接显示Sorry
	*/
	string convert_to_time(int minutes);
	/**
		找到一个可以进入的队列号 找不到返回-1
		当前总计服务结束分钟<=540有容量且容量最大
	*/
	int find_line(vector<service_line> service_lines);
}