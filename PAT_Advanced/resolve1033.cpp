#include "resolve1033.h"
/*
	�������е���˼��ÿ��һ������վ���Ͳ�����������������¼���
	��ô���Ǵ��յ㿪ʼ�������ǣ��ɽ���Զ�����ÿһ������վA�����ͺ����ٻ��軨����Ǯ�����յ�
	���ڼ���ʱδ���ҵ���A���յ��������������ڿɴ����һ������վ������Ϊ�յ㲻�ɴ��ת���ж���Զ�����������
	�ж���Զ��������̣�������A���ɴ��յ㣬����A����㷽�򾡿�����Դ��������Դ����㣬����Զ�ɴ�A����ֻ����Դ��B�����B����վ���¿�ʼ�ж���Զ����

	���˼·��Щ���⡣
	���˼·Ĭ�ϵ���ÿ������վʱ��Ϊ���ͣ���ʵ���ϣ���ǰһ��վ���ͼ۽�Ϊ���ˣ��ҿ���ѡ����Щ�͡�
	�������ǲ������жϵ��ﱾվʱ������������֮��תΪ����̰�ģ���ÿ��̵��ͼ�̰�ģ������ܾ��컻�ɱ��˵���

	��ÿ�������ļ���վA ��������̷�Χ�ڣ�ѡ����������һ����A�ͼ۵ͻ��߼۸���͵��۸��A�ߵļ���վB�������ܾ�����ͻ��ɵͼ۵ġ�
	���B���ͼ۱�A���ͼ۵ͣ�����A�Ͱ�����ӵ���A��B����
	���B���ͼ۲���A�ͣ�����A�Ͱ�����ӵ�������B����������

	������Ϊʲô����̰�Ĳ������Զ·�����Ӱ��
	��Ϊ̰�����ڶ����ѡվ����ѡ����һ��վ�㡣��ѡ��Ĳ�����Զ�����վ��C����ô��������ѡ����վ��D��D�ض����Ե���C
	��ֻ��һ�����������ѡվ��ʱ���޷�����̰�ġ����Ͽ�֪���κ�һ��վ�����̰��ѡ�񲻻�Ӱ����Զ�ɴ����

	���OAC �ü��ѣ���ʱ3�죬һֱû���������̰�ġ�
	��Ҫע�����ѡ����һ������վ���۸�ȱ�վ���������� ���� �۸񲻱ȱ�վ�͵�������˵�
*/
int resolve1033::resolve()
{
	double capacity_of_tank, distance, distance_avg, number_of_gas_stations = 0.0;
	scanf("%lf %lf %lf %lf", &capacity_of_tank, &distance, &distance_avg, &number_of_gas_stations);
	vector<gas_station> stations;
	stations.resize(number_of_gas_stations);
	for (size_t i = 0; i < number_of_gas_stations; i++)
	{
		scanf("%lf %lf", &stations[i].price, &stations[i].distance);
		stations[i].oil = 0;
	}
	sort(stations.begin(), stations.end(), cmp_station);
	//����㿪ʼ����
	//һ�������ܶ�Զ
	double tank_distance = distance_avg*capacity_of_tank;
	double result = 0.0;
	if (stations[0].distance != 0)
	{
		cout << "The maximum travel distance = ";
	}
	else
	{
		//double last_res = 0.0;
		for (int current_station = 0,next_station = -1; current_station < number_of_gas_stations; current_station= next_station, next_station=-1)
		{
			//�ж��µ�ǰ�����Ƿ���Եִ��յ�
			if (stations[current_station].oil*distance_avg + stations[current_station].distance >= distance)
			{
				//��ǰ�������Եִ��յ㣬�ڱ�վ������ͣ�ֱ���յ㼴��
				break;
			}
			//��ǰվ���ܵ������Զվ���� -3�յ� -1��Ҳȥ����
			int max_station_index = find_max_distance_tank(stations, true, current_station, tank_distance, distance);
			double min_pirce = 0.0;
			if (max_station_index==-3)
			{
				//��Զ������Ե��յ��ˣ���ʱ��ֻ����ȥ�ȱ�վ�ͼ۱��˵�վ
				//�ҵ�δ����������վ���ͼ�����˵��Ǹ����۸�ȱ�վ���������� ���� �۸񲻱ȱ�վ�͵�������˵ģ�
				for (int j = current_station; j < number_of_gas_stations; ++j)
				{
					if (stations[j].price<stations[current_station].price)
					{
						next_station = j;
						break;
					}else if (min_pirce > stations[j].price|| next_station == -1)
					{
						min_pirce = stations[j].price;
						next_station = j;
					}
				}
				if (stations[next_station].price<stations[current_station].price)
				{
					stations[next_station].oil = stations[current_station].oil - (stations[next_station].distance - stations[current_station].distance) / distance_avg;
					if (stations[next_station].oil<0)
					{
						//�Ͳ������ڱ�վ����
						result += (0 - stations[next_station].oil)*stations[current_station].price;
						stations[next_station].oil = 0;
					}
				}
				else
				{
					//��ǰվ�����Ѿ��ܱ����ˣ����ͼӵ����Ե��յ����
					result += ((distance - stations[current_station].distance)/distance_avg- stations[current_station].oil)*stations[current_station].price;
					stations[next_station].oil = (distance - stations[next_station].distance) / distance_avg;
				}
			}
			else if (max_station_index == -1)
			{
				//Ŷ���߲�����һ������վ�ˣ��ǾͰ��ͼ��������߶�Զ�߶�Զ
				result = stations[current_station].distance + tank_distance;
				cout << "The maximum travel distance = ";
				break;
			}
			else
			{
				//�ҵ���һ������վ �۸�ȱ�վ���������� ���� �۸񲻱ȱ�վ�͵�������˵�
				for (int j = current_station + 1; j <= max_station_index; ++j)
				{
					if (stations[j].price<stations[current_station].price)
					{
						next_station = j;
						break;
					}
					else if (min_pirce > stations[j].price || next_station == -1)
					{
						min_pirce = stations[j].price;
						next_station = j;
					}
				}
				if (stations[next_station].price < stations[current_station].price)
				{
					stations[next_station].oil = stations[current_station].oil - (stations[next_station].distance - stations[current_station].distance) / distance_avg;
					if (stations[next_station].oil<0)
					{
						//�Ͳ������ڱ�վ����
						result += (0 - stations[next_station].oil)*stations[current_station].price;
						stations[next_station].oil = 0;
					}
				}
				else
				{
					//��ǰվ�����Ѿ��ܱ����ˣ����ͼ���
					result += (capacity_of_tank - stations[current_station].oil)*stations[current_station].price;
					stations[next_station].oil = capacity_of_tank-(stations[next_station].distance - stations[current_station].distance) / distance_avg;
				}
			}
			/*cout << current_station << " " << next_station << " " <<result-last_res<<endl;
			last_res = result;*/
		}
	}
	cout << fixed << setprecision(2) << result;
	return 0;
}

bool resolve1033::cmp_station(gas_station & s1, gas_station & s2)
{
	return s1.distance <= s2.distance;
}

int resolve1033::find_max_distance_tank(vector<gas_station>& stations_distance_asc, bool asc, int current_station_index, double tank_distance,double total_distance)
{
	int index = current_station_index;
	if (asc)
	{
		//���յ㷽����
		double max_distance = stations_distance_asc[current_station_index].distance + tank_distance;
		if (max_distance>=total_distance)
		{
			index = -3;
		}
		else
		{
			for (; index < stations_distance_asc.size(); ++index)
			{
				if (max_distance<stations_distance_asc[index].distance)
				{
					//��ǰ����վ���ɴ�
					break;
				}
			}
			--index;
		}
	}
	else
	{
		//����㷽����
		double min_distance = stations_distance_asc[current_station_index].distance - tank_distance;
		if (min_distance<=0.0)
		{
			index = -2;
		}
		else
		{
			for (; index >= 0; --index)
			{
				if (stations_distance_asc[index].distance<min_distance)
				{
					break;
				}
			}
			++index;
		}
	}
	return index== current_station_index ?-1: index;
}

double resolve1033::find_max_distance(vector<gas_station>& stations_distance_asc, int current_station_index, double tank_distance, double total_distance)
{
	int max_distance_station_index = current_station_index;
	while (-2 != (max_distance_station_index = find_max_distance_tank(stations_distance_asc, false, current_station_index, tank_distance, total_distance)))
	{
		if (-1 == max_distance_station_index)
		{
			--current_station_index;
		}
		else
		{
			current_station_index = max_distance_station_index;
		}
	}
	return stations_distance_asc[current_station_index].distance;
}
