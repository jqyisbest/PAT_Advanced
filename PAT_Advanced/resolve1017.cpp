#include "resolve1017.h"

/**
	统一用秒数计时
	一天是86400s
	从凌晨0点0秒到08:00:00共计28800s
	从凌晨0点0秒到17:00:00共计61200s

	注意三个坑，
	第一个是没有顾客可以被服务时输出0.0，
	第二个是顾客来的时候可能比可用窗口早或者晚，要分两种情况，
	第三个是只要顾客在17:00:00及之前抵达银行，就一定要被服务！！！不管是什么时候服务，哪怕第二天也行！ 最后一个测试点就是测这个。
*/
int resolve1017::resolve()
{
	//输入可以被服务（17:00:00及之前到）的客户,保存其所需处理时间（转换为秒）
	int*processing_times = new int[86401];
	fill(processing_times, processing_times + 86401, -1);
	int total_number_of_customers = 0, number_of_windows = 0;
	cin >> total_number_of_customers >> number_of_windows;
	for (int i = 0; i < total_number_of_customers; ++i)
	{
		int hour = 0, minute = 0, second = 0, processing_time = 0;
		scanf("%d:%d:%d %d", &hour, &minute, &second,&processing_time);
		int seconds = hour * 3600 + minute * 60 + second;
		if (seconds <= 61200)
		{
			//每个顾客最多被服务一小时即3600秒
			processing_time = (processing_time>60 ? 60 : processing_time);
			processing_times[seconds] = processing_time * 60;
		}
	}
	//服务窗口
	//服务窗口可用时间，即每个窗口于多少点可用
	int*times_window_available = new int[number_of_windows];
	fill(times_window_available, times_window_available + number_of_windows, 28800);
	//只要还有客人在等待服务且还有窗口可用，那么就认为没有停止营业
	int customer_index = -1, window_index_available = -1;
	//总等待时间，总服务人数
	double total_waiting_time = 0.0, total_service_num = 0.0;
	while (-1 != (customer_index = find_customer_waiting(processing_times,customer_index)) && -1 != (window_index_available = find_window_available(times_window_available, number_of_windows)))
	{
		//找到可用窗口之后分两种情况，窗口可用时间比客户来的时间要早/晚
		if (times_window_available[window_index_available]<=customer_index)
		{
			times_window_available[window_index_available] = customer_index + processing_times[customer_index];
		}
		else
		{
			//顾客需要等待
			total_waiting_time += times_window_available[window_index_available] - customer_index;
			times_window_available[window_index_available] += processing_times[customer_index];
		}
		//顾客得到服务后将所需处理时间置为-1，即从队列移除
		processing_times[customer_index] = -1;
		total_service_num += 1.0;
	}
	if (total_service_num==0)
	{
		cout<<"0.0";
	}
	else
	{
		printf("%.1f", total_waiting_time / 60.0 / total_service_num);
	}
	return 0;
}

int resolve1017::find_customer_waiting(int * processing_times, int current_index)
{
	for (int i = current_index+1; i < 86401; ++i)
	{
		if (processing_times[i] != -1)
		{
			return i;
		}
	}
	return -1;
}

int resolve1017::find_window_available(int * times_window_available, int number_of_windows)
{
	int window_index = -1;
	int earliest_time = 86401;
	bool is_first_window_available = false;
	for (int i = 0; i < number_of_windows; ++i)
	{
		//窗口可用时间<=61200且窗口可用时间最早
		//只要顾客在17:00 : 00及之前抵达银行，就一定要被服务！！！所以窗口可用时间不需要<=61200!!!也不需要在一天之内！！！！
		if (!is_first_window_available)
		{
			earliest_time = times_window_available[i];
			window_index = i;
			is_first_window_available = true;
		}
		else if (times_window_available[i] < earliest_time)
		{
			earliest_time = times_window_available[i];
			window_index = i;
		}
	}
	return window_index;
}
