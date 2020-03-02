#include "resolve1030.h"
/**
	�����1003��1018���񰡡�1018�Ǹ�������µ�������������µ���С
	dijsktra
*/
int resolve1030::resolve()
{
	//city��0��ʼ���
	int number_of_cities = 0, number_of_highways = 0, start_city = 0, destination_city = 0;
	scanf("%d %d %d %d", &number_of_cities, &number_of_highways, &start_city, &destination_city);
	//array used for Dijkstra
	bool* visited = new bool[number_of_cities];
	int* distance = new int[number_of_cities];
	int* cost = new int[number_of_cities];
	fill(visited, visited + number_of_cities, false);
	fill(distance, distance + number_of_cities, -1);
	fill(cost, cost + number_of_cities, 0);
	//�洢��Ч��
	vector<highway_node> highways;
	highways.resize(number_of_highways);
	//������Ŀ��֤�����ǰ��ÿ������·������Һķ���͵�·��ֻ��һ������������������һ�µ�·��
	vector<int>* shorest_path = new vector<int>[number_of_cities];
	for (size_t i = 0; i < number_of_highways; ++i)
	{
		highway_node *highway = &highways[i];
		scanf("%d %d %d %d", &highway->city_1, &highway->city_2, &highway->distance, &highway->cost);
		if (highway->city_1 == start_city)
		{
			distance[highway->city_2] = highway->distance;
			cost[highway->city_2] = highway->cost;
			shorest_path[highway->city_2].push_back(start_city);
			shorest_path[highway->city_2].push_back(highway->city_2);
		}
		if (highway->city_2 == start_city)
		{
			distance[highway->city_1] = highway->distance;
			cost[highway->city_1] = highway->cost;
			shorest_path[highway->city_1].push_back(start_city);
			shorest_path[highway->city_1].push_back(highway->city_1);
		}
	}
	//Dijkstra start
	visited[start_city] = true;
	for (size_t i = 0; i < number_of_cities; ++i)
	{
		//��һ����start_city�����δ���ʳ���u
		int u = -1;
		int min = 0;
		for (size_t j = 0; j < number_of_cities; ++j)
		{
			if (!visited[j] && distance[j] != -1)
			{
				if (distance[j] < min||u == -1)
				{
					u = j;
					min = distance[j];
				}
			}
		}
		if (u == -1)
		{
			break;
		}
		visited[u] = true;
		for (size_t j = 0; j < number_of_highways; ++j)
		{
			int adjacent_city = -1;
			if (highways[j].city_1 == u)
			{
				adjacent_city = highways[j].city_2;
			}
			else if (highways[j].city_2 == u)
			{
				adjacent_city = highways[j].city_1;
			}
			if (-1 != adjacent_city&&!visited[adjacent_city])
			{
				//��u���ڽӳ���
				if (distance[adjacent_city] == -1 || distance[u] + highways[j].distance < distance[adjacent_city] || (distance[u] + highways[j].distance == distance[adjacent_city] && cost[u] + highways[j].cost < cost[adjacent_city]))
				{
					//�ҵ�һ��ͨ��adjacent_city���̵Ļ���·��һ������costС����·��
					distance[adjacent_city] = distance[u] + highways[j].distance;
					cost[adjacent_city] = cost[u] + highways[j].cost;
					copy_path(shorest_path[u], shorest_path[adjacent_city], adjacent_city);
				}
			}
		}
	}
	//������
	for (size_t i = 0; i < shorest_path[destination_city].size(); ++i)
	{
		cout << shorest_path[destination_city][i] << " ";
	}
	cout << distance[destination_city] << " " << cost[destination_city];
	return 0;
}

void resolve1030::copy_path(vector<int>& source, vector<int>& target, int target_num)
{
	target.clear();
	for (size_t i = 0; i < source.size(); ++i)
	{
		target.push_back(source[i]);
	}
	target.push_back(target_num);
}
