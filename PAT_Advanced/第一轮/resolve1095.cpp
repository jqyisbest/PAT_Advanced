#include "resolve1095.h"
/*
	分别统计每一时刻车辆数和每辆车的时长
	先车辆、时间顺序排序记录
	只有前一条进记录加上这一条出记录才是合法的

	查询车辆数目时上次查询索引应初始化为-1，否则会漏掉0时刻的车辆变化
*/
int resolve1095::resolve()
{
	vector<record*> car_record;
	vector<string> max_seconds_car;
	int  total_seconds = 24 * 3600, *car_num = new int[total_seconds], n = 0, k = 0, max_seconds = 0;
	fill(car_num, car_num + total_seconds, 0);
	scanf("%d %d", &n, &k);
	//先过滤出有效记录
	for (size_t i = 0; i < n; ++i)
	{
		string plate, in_or_out;
		plate.resize(7);
		in_or_out.resize(3);
		int hh = 0, mm = 0, ss = 0, seconds = 0;
		scanf("%s %d:%d:%d %s", &plate[0], &hh, &mm, &ss, &in_or_out[0]);
		in_or_out = in_or_out.substr(0, strlen(in_or_out.c_str()));
		plate = plate.substr(0, strlen(plate.c_str()));
		seconds = get_seconds(hh, mm, ss);
		record* r = new record();
		r->plate = plate;
		r->time = seconds;
		r->in_or_out = in_or_out;
		car_record.push_back(r);
	}
	sort(car_record.begin(), car_record.end(), cmp_record);
	int total = 0;
	string plate;
	for (size_t i = 0; i <= n; ++i)
	{
		if (i == 0)
		{
			plate = car_record[i]->plate;
		}
		else if (i == n)
		{
			if (total > max_seconds)
			{
				max_seconds = total;
				max_seconds_car.clear();
				max_seconds_car.push_back(plate);
			}
			else if (total == max_seconds)
			{
				max_seconds_car.push_back(plate);
			}
		}
		else
		{
			if (car_record[i]->plate != car_record[i - 1]->plate)
			{
				//新车
				if (total > max_seconds)
				{
					max_seconds = total;
					max_seconds_car.clear();
					max_seconds_car.push_back(plate);
				}
				else if (total == max_seconds)
				{
					max_seconds_car.push_back(plate);
				}
				total = 0;
				plate = car_record[i]->plate;
			}
			else if (car_record[i]->in_or_out == "out"&&car_record[i - 1]->in_or_out == "in")
			{
				//合法匹配记录
				car_num[car_record[i - 1]->time]++;
				car_num[car_record[i]->time]--;
				total += car_record[i]->time - car_record[i - 1]->time;
			}
		}
	}
	//处理查询请求
	int last_quest = -1, quest_result = 0;
	for (size_t i = 0; i < k; i++)
	{
		int hh = 0, mm = 0, ss = 0, seconds = 0;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		seconds = get_seconds(hh, mm, ss);
		for (int j = seconds; j > last_quest; --j)
		{
			quest_result += car_num[j];
		}
		last_quest = seconds;
		printf("%d\n", quest_result);
	}
	for (size_t i = 0; i < max_seconds_car.size(); ++i)
	{
		printf("%s ", max_seconds_car[i].c_str());
	}
	int hh = max_seconds / 3600, mm = max_seconds % 3600 / 60, ss = max_seconds % 3600 % 60;
	printf("%02d:%02d:%02d", hh, mm, ss);
	return 0;
}

int resolve1095::get_seconds(int hh, int mm, int ss)
{
	return hh * 3600 + mm * 60 + ss;
}

bool resolve1095::cmp_record(record * r1, record * r2)
{
	return r1->plate == r2->plate ? r1->time < r2->time : r1->plate < r2->plate;
}
