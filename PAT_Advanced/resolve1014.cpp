#include "resolve1014.h"

/**
	�൱�ڽ������ڶ����˾Ͳ��ܸ��ˣ���ô����ʱ��Ҳ��ȷ����
	��ôֻҪ�������ڶ����пͻ��ķ������ʱ�䣬���г�����������17:00�ģ���ô��������ֹͣ�����¹˿�
	�൱��һ�����ȳ���

*/
int resolve1014::resolve()
{
	int number_of_windows = 0, capacity_of_each_line_inside= 0, number_of_customers = 0, number_of_queries = 0;
	cin >> number_of_windows >> capacity_of_each_line_inside >> number_of_customers >> number_of_queries;
	//��ʼ��δ��ֹ����ķ�����У����ڶ��У�
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
	//��¼ÿһ��������Щ�˿Ͱ�����ҵ��
	vector<int>* minutes_customer_finished = new vector<int>[542];
	//��¼��һλѡ����еĹ˿���˭���˿ͱ�Ŵ�1��ʼ
	int next_customer = 1;
	//ʱ��i
	for (int i = 0; next_customer<= number_of_customers&&i <541; ++i)
	{
		//�˿������뿪
		if (!minutes_customer_finished[i].empty())
		{
			for (int j = 0; j < minutes_customer_finished[i].size(); ++j)
			{
				service_lines[customers[minutes_customer_finished[i][j]].line_num].capacity_available++;
			}
		}
		//�ж��Ƿ��ж��п��Խ���
		int line_num = -1;
		while (next_customer <= number_of_customers&&-1!=(line_num=find_line(service_lines)))
		{
			//���¹˿����ڵĶ��кźͿ�ʼ����ʱ��
			customers[next_customer].line_num = line_num;
			customers[next_customer].minutes_service_start = service_lines[line_num].last_finish_minutes;
			customers[next_customer].minutes_service_finished = service_lines[line_num].last_finish_minutes + customers[next_customer].minutes_cost;
			//���¶������������һλ�˿ͷ������ʱ��
			service_lines[line_num].capacity_available--;
			service_lines[line_num].last_finish_minutes = customers[next_customer].minutes_service_finished;
			//����minutes_customer_finished
			if (customers[next_customer].minutes_service_finished<540)
			{
				//���ڵ���540˵�����������޷��ٷ����������¼
				minutes_customer_finished[customers[next_customer].minutes_service_finished].push_back(next_customer);
			}
			//������һλ�˿�
			++next_customer;
		}
	}
	//������һ���Ӫҵ
	for (int i = 0; i < number_of_queries-1; ++i)
	{
		//ע����>=540��17:00ǰ���ɽӿ�
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
			//���ܴ�=�ţ���ͬ����ʱ���ں�С������
			line_num = i;
			max_capacity = service_lines[i].capacity_available;
		}
	}
	return line_num;
}
