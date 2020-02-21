#include "resolve1017.h"

/**
	ͳһ��������ʱ
	һ����86400s
	���賿0��0�뵽08:00:00����28800s
	���賿0��0�뵽17:00:00����61200s

	ע�������ӣ�
	��һ����û�й˿Ϳ��Ա�����ʱ���0.0��
	�ڶ����ǹ˿�����ʱ����ܱȿ��ô����������Ҫ�����������
	��������ֻҪ�˿���17:00:00��֮ǰ�ִ����У���һ��Ҫ�����񣡣���������ʲôʱ��������µڶ���Ҳ�У� ���һ�����Ե���ǲ������
*/
int resolve1017::resolve()
{
	//������Ա�����17:00:00��֮ǰ�����Ŀͻ�,���������账��ʱ�䣨ת��Ϊ�룩
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
			//ÿ���˿���౻����һСʱ��3600��
			processing_time = (processing_time>60 ? 60 : processing_time);
			processing_times[seconds] = processing_time * 60;
		}
	}
	//���񴰿�
	//���񴰿ڿ���ʱ�䣬��ÿ�������ڶ��ٵ����
	int*times_window_available = new int[number_of_windows];
	fill(times_window_available, times_window_available + number_of_windows, 28800);
	//ֻҪ���п����ڵȴ������һ��д��ڿ��ã���ô����Ϊû��ֹͣӪҵ
	int customer_index = -1, window_index_available = -1;
	//�ܵȴ�ʱ�䣬�ܷ�������
	double total_waiting_time = 0.0, total_service_num = 0.0;
	while (-1 != (customer_index = find_customer_waiting(processing_times,customer_index)) && -1 != (window_index_available = find_window_available(times_window_available, number_of_windows)))
	{
		//�ҵ����ô���֮���������������ڿ���ʱ��ȿͻ�����ʱ��Ҫ��/��
		if (times_window_available[window_index_available]<=customer_index)
		{
			times_window_available[window_index_available] = customer_index + processing_times[customer_index];
		}
		else
		{
			//�˿���Ҫ�ȴ�
			total_waiting_time += times_window_available[window_index_available] - customer_index;
			times_window_available[window_index_available] += processing_times[customer_index];
		}
		//�˿͵õ���������账��ʱ����Ϊ-1�����Ӷ����Ƴ�
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
		//���ڿ���ʱ��<=61200�Ҵ��ڿ���ʱ������
		//ֻҪ�˿���17:00 : 00��֮ǰ�ִ����У���һ��Ҫ�����񣡣������Դ��ڿ���ʱ�䲻��Ҫ<=61200!!!Ҳ����Ҫ��һ��֮�ڣ�������
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
