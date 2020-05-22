#include "resolve1033.h"
/*
	假设题中的意思是每到一个加油站把油补满，而不是清空重新加油
	那么我们从终点开始，反向考虑，由近及远算出从每一个加油站A加完油后，最少还需花多少钱到达终点
	若在计算时未能找到从A向终点出发满油箱里程内可达的下一个加油站，则认为终点不可达，并转入判断最远距离的流程中
	判断最远距离的流程：若发现A不可达终点，则由A向起点方向尽可能溯源，若能溯源至起点，则最远可达A，若只能溯源至B，则从B加油站重新开始判断最远距离

	这个思路有些问题。
	这个思路默认到达每个加油站时均为空油，但实际上，若前一个站的油价较为便宜，我可以选择多带些油。
	但反向考虑不便于判断到达本站时的油量，故弃之。转为正向贪心，对每里程的油价贪心，尽可能尽快换成便宜的油

	对每个所处的加油站A 在油箱里程范围内，选择离得最近的一个比A油价低或者价格最低但价格比A高的加油站B，尽可能尽快把油换成低价的。
	如果B的油价比A的油价低，那在A就把油箱加到从A到B的油
	如果B的油价不比A低，那在A就把油箱加到满，到B后再做考虑

	解释下为什么这里贪心不会对最远路程造成影响
	因为贪心是在多个候选站点中选择下一个站点。若选择的不是最远距离的站点C，那么当到达所选加油站点D后，D必定可以到达C
	当只有一个或者零个候选站点时，无法进行贪心。综上可知在任何一个站点进行贪心选择不会影响最远可达距离

	这次OAC 好艰难，历时3天，一直没整明白如何贪心。
	主要注意如何选择下一个加油站：价格比本站低且离得最近 或者 价格不比本站低但是最便宜的
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
	//由起点开始计算
	//一油箱能跑多远
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
			//判断下当前油量是否可以抵达终点
			if (stations[current_station].oil*distance_avg + stations[current_station].distance >= distance)
			{
				//当前油量可以抵达终点，在本站无需加油，直奔终点即可
				break;
			}
			//当前站点能到达的最远站索引 -3终点 -1哪也去不了
			int max_station_index = find_max_distance_tank(stations, true, current_station, tank_distance, distance);
			double min_pirce = 0.0;
			if (max_station_index==-3)
			{
				//最远距离可以到终点了，这时就只考虑去比本站油价便宜的站
				//找到未来几个加油站中油价最便宜的那个（价格比本站低且离得最近 或者 价格不比本站低但是最便宜的）
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
						//油不够，在本站加油
						result += (0 - stations[next_station].oil)*stations[current_station].price;
						stations[next_station].oil = 0;
					}
				}
				else
				{
					//当前站点油已经很便宜了，把油加到可以到终点的量
					result += ((distance - stations[current_station].distance)/distance_avg- stations[current_station].oil)*stations[current_station].price;
					stations[next_station].oil = (distance - stations[next_station].distance) / distance_avg;
				}
			}
			else if (max_station_index == -1)
			{
				//哦吼，走不到下一个加油站了，那就把油加满，能走多远走多远
				result = stations[current_station].distance + tank_distance;
				cout << "The maximum travel distance = ";
				break;
			}
			else
			{
				//找到下一个加油站 价格比本站低且离得最近 或者 价格不比本站低但是最便宜的
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
						//油不够，在本站加油
						result += (0 - stations[next_station].oil)*stations[current_station].price;
						stations[next_station].oil = 0;
					}
				}
				else
				{
					//当前站点油已经很便宜了，把油加满
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
		//朝终点方向找
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
					//当前加油站不可达
					break;
				}
			}
			--index;
		}
	}
	else
	{
		//朝起点方向找
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
