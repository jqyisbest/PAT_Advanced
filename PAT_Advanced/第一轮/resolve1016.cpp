#include "resolve1016.h"

/*
	���ͳһ������
*/
int resolve1016::resolve()
{
	int* toll_rate = new int[24];
	for (int i = 0; i < 24; ++i)
	{
		cin >> toll_rate[i];
	}
	int num_of_record = 0;
	cin >> num_of_record;
	if (num_of_record > 1)
	{
		//�����¼
		string month;
		vector<record_input>records;
		records.resize(num_of_record);
		for (int i = 0; i < num_of_record; ++i)
		{
			string time, status;
			cin >> records[i].name >> time >> status;
			//����ʱ��
			if (month.size() == 0)
			{
				month.push_back(time[0]);
				month.push_back(time[1]);
			}
			records[i].day_str.push_back(time[3]);
			records[i].day_str.push_back(time[4]);
			records[i].hour_str.push_back(time[6]);
			records[i].hour_str.push_back(time[7]);
			records[i].minute_str.push_back(time[9]);
			records[i].minute_str.push_back(time[10]);
			records[i].day = stoi(records[i].day_str);
			records[i].hour = stoi(records[i].hour_str);
			records[i].minute = stoi(records[i].minute_str);
			if (status == "on-line")
			{
				//����
				records[i].action = 1;
			}
			else
			{
				//����
				records[i].action = 0;
			}
		}
		//�����֡�ʱ����е�������
		sort(records.begin(), records.end(), cmp_record);
		//��˳��������
		map<string, vector<record_input>> user_records;
		for (int i = 0; i < num_of_record-1;)
		{
			if (records[i].name== records[i+1].name&&records[i].action==1&& records[i+1].action == 0)
			{
				user_records[records[i].name].push_back (records[i]);
				user_records[records[i+1].name].push_back(records[i+1]);
				i += 2;
			}
			else
			{
				++i;
			}
		}
		int endl_count = 0;
		//��һ����绰��Ҫ����Ǯ
		long charge_cents_all_day = calculate_charge_cents(toll_rate, 0, 0, 23, 60);
		for (auto each_user:user_records)
		{
			//����ÿһ���ͻ�
			vector<record_input> records_for_each_user = each_user.second;
			//�ܽ��
			long current_customer_total_cents = 0;
			//1�����̧ͷ
			cout << each_user.first << " " << month << endl;
			//2�����ÿһ����¼����������
			for (size_t i = 0; i < records_for_each_user.size(); i+=2)
			{
				string time_start, time_end;
				time_start.append(records_for_each_user[i].day_str);
				time_start.append(":");
				time_start.append(records_for_each_user[i].hour_str);
				time_start.append(":");
				time_start.append(records_for_each_user[i].minute_str);
				time_end.append(records_for_each_user[i+1].day_str);
				time_end.append(":");
				time_end.append(records_for_each_user[i+1].hour_str);
				time_end.append(":");
				time_end.append(records_for_each_user[i+1].minute_str);

				long minutes = ((records_for_each_user[i + 1].day - 1) * 1440 + records_for_each_user[i + 1].hour * 60 + records_for_each_user[i + 1].minute) - ((records_for_each_user[i].day - 1) * 1440 + records_for_each_user[i].hour * 60 + records_for_each_user[i].minute);
				
				long cents = 0;
				if (records_for_each_user[i].day == records_for_each_user[i + 1].day)
				{
					//û����
					cents += calculate_charge_cents(toll_rate, records_for_each_user[i].hour, records_for_each_user[i].minute, records_for_each_user[i + 1].hour, records_for_each_user[i + 1].minute);
				}
				else {
					for (int k = records_for_each_user[i].day; k < records_for_each_user[i + 1].day + 1; ++k)
					{
						if (k == records_for_each_user[i].day)
						{
							//��һ�죬�ӿ�ʼ��绰ͳ�Ƶ���ǰ24��
							cents += calculate_charge_cents(toll_rate, records_for_each_user[i].hour, records_for_each_user[i].minute, 23, 60);
						}
						else if (k == records_for_each_user[i + 1].day)
						{
							//���һ�죬��0��ͳ�Ƶ���ǰʱ��
							cents += calculate_charge_cents(toll_rate, 0, 0, records_for_each_user[i + 1].hour, records_for_each_user[i + 1].minute);
						}
						else {
							cents += charge_cents_all_day;
						}
					}
				}

				//�����ǰ��¼
				cout << time_start << " " << time_end << " " << minutes << " " << format_money(cents) << endl;

				//�ۼ�����ǰ�ͻ��ܶ���
				current_customer_total_cents += cents;
			}
			//3������ÿͻ����ܼ�
			cout << "Total amount: " << format_money(current_customer_total_cents);
			if (endl_count<user_records.size()-1)
			{
				cout << endl;
				endl_count++;
			}
		}
	}
	return 0;
}

bool resolve1016::cmp_record(record_input r1, record_input r2)
{
	if (r1.name == r2.name)
	{
		return r1.day == r2.day ? r1.hour == r2.hour ? r1.minute < r2.minute : r1.hour < r2.hour : r1.day < r2.day;
	}
	else {
		return r1.name < r2.name;
	}
}

string resolve1016::format_money(long cents)
{
	long dollar = cents / 100;
	int cent = cents % 100;
	//���������������� ��cent<10ʱ����Ҫ�ֶ���0 ��Ϊ������һֱֻ�е�һ�����Ե���ˣ�ܳ��
	return "$" + to_string(dollar) + "." + (cent<10 ? "0" + to_string(cent) : to_string(cent));
}

long resolve1016::calculate_charge_cents(int * toll_rate, int start_hour, int start_minute, int end_hour, int end_minute)
{
	long charge_cents = 0;
	if (start_hour==end_hour)
	{
		//û��ʱ��
		charge_cents += (end_minute - start_minute)*toll_rate[start_hour];
	}
	else {
		for (int i = start_hour; i < end_hour + 1; ++i)
		{
			if (i == start_hour)
			{
				//��һ��Сʱ��
				charge_cents += (60 - start_minute)*toll_rate[start_hour];
			}
			else if (i == end_hour)
			{
				//���һ��Сʱ��
				charge_cents += end_minute*toll_rate[end_hour];
			}
			else
			{
				charge_cents += 60 * toll_rate[i];
			}
		}
	}
	return charge_cents;
}
