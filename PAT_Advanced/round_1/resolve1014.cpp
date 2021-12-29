#include "resolve1014.h"

/**
	相当于进入线内队列了就不能改了，那么服务时间也就确定了
	那么只要计算线内队列中客户的服务结束时间，如有超过（包括）17:00的，那么该条队列停止接受新顾客
	相当于一个调度程序？

*/
int resolve1014::resolve()
{
	int number_of_windows = 0, capacity_of_each_line_inside= 0, number_of_customers = 0, number_of_queries = 0;
	cin >> number_of_windows >> capacity_of_each_line_inside >> number_of_customers >> number_of_queries;
	//初始化未终止服务的服务队列（线内队列）
	vector<service_line> service_lines =vector<service_line>(number_of_windows);
	for (int i = 0; i < number_of_windows; ++i)
	{
		service_lines[i].capacity_available = capacity_of_each_line_inside;
		service_lines[i].last_finish_minutes = 0;
	}
	customer* customers = new customer[number_of_customers+1];
	for (int i = 1; i < number_of_customers+1; ++i)
	{
		cin >> customers[i].minutes_cost;
		customers[i].line_num = -1;
		customers[i].minutes_service_start = 999;
		customers[i].minutes_service_finished = 999;
	}
	int* query_customers = new int[number_of_queries];
	for (int i = 0; i < number_of_queries; ++i)
	{
		cin >> query_customers[i];
	}
	//记录每一分钟有哪些顾客办完了业务
	vector<int>* minutes_customer_finished = new vector<int>[542];
	//记录下一位选择队列的顾客是谁，顾客编号从1开始
	int next_customer = 1;
	//时刻i
	for (int i = 0; next_customer<= number_of_customers&&i <541; ++i)
	{
		//顾客起身离开
		if (!minutes_customer_finished[i].empty())
		{
			for (int j = 0; j < minutes_customer_finished[i].size(); ++j)
			{
				service_lines[customers[minutes_customer_finished[i][j]].line_num].capacity_available++;
			}
		}
		//判断是否有队列可以进人
		int line_num = -1;
		while (next_customer <= number_of_customers&&-1!=(line_num=find_line(service_lines)))
		{
			//更新顾客所在的队列号和开始结束时间
			customers[next_customer].line_num = line_num;
			customers[next_customer].minutes_service_start = service_lines[line_num].last_finish_minutes;
			customers[next_customer].minutes_service_finished = service_lines[line_num].last_finish_minutes + customers[next_customer].minutes_cost;
			//更新队列容量和最后一位顾客服务结束时间
			service_lines[line_num].capacity_available--;
			service_lines[line_num].last_finish_minutes = customers[next_customer].minutes_service_finished;
			//更新minutes_customer_finished
			if (customers[next_customer].minutes_service_finished<540)
			{
				//大于等于540说明这条队列无法再服务，亦无须记录
				minutes_customer_finished[customers[next_customer].minutes_service_finished].push_back(next_customer);
			}
			//更新下一位顾客
			++next_customer;
		}
	}
	//结束了一天的营业
	for (int i = 0; i < number_of_queries-1; ++i)
	{
		//注意是>=540，17:00前方可接客
		if (customers[query_customers[i]].minutes_service_start>=540)
		{
			cout << "Sorry" << endl;
		}
		else
		{
			cout << convert_to_time(customers[query_customers[i]].minutes_service_finished) << endl;
		}
	}
	if (customers[query_customers[number_of_queries - 1]].minutes_service_start>=540)
	{
		cout << "Sorry" ;
	}
	else
	{
		cout << convert_to_time(customers[query_customers[number_of_queries - 1]].minutes_service_finished);
	}
	return 0;
}

string resolve1014::convert_to_time(int minutes)
{
	int hh = 8,mm=0;
	hh += minutes / 60;
	mm += minutes % 60;
	return (hh<10?"0"+to_string(hh): to_string(hh)) +":"+ (mm<10 ? "0" + to_string(mm) : to_string(mm));
}

int resolve1014::find_line(vector<service_line> service_lines)
{
	int line_num = -1;
	int max_capacity = 0;
	for (int i = 0; i<service_lines.size(); ++i)
	{
		if (service_lines[i].last_finish_minutes<540 && service_lines[i].capacity_available>max_capacity)
		{
			//不能带=号，相同长度时窗口号小的优先
			line_num = i;
			max_capacity = service_lines[i].capacity_available;
		}
	}
	return line_num;
}
