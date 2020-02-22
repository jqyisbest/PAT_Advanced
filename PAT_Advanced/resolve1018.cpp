#include "resolve1018.h"
/**
	Dijkstra�������������·��
	��ÿ�����·�������ȥ�ʹ������ĳ�����
	���ݴ���ȥ�������ʹ�������������С��������
	������ٵ���һ��
*/
int resolve1018::resolve()
{
	//ÿ��վ���������վ�������������վ���������0Ϊ��㡢����վ���1��ʼ����·������
	int capacity_of_each_station = 0, number_of_stations = 0, index_of_the_problem_station = 0, number_of_roads = 0;
	cin >> capacity_of_each_station >> number_of_stations >> index_of_the_problem_station >> number_of_roads;
	//ÿ��վ�����г���
	int* current_number_of_bikes = new int[number_of_stations+1];
	for (int i = 1; i < number_of_stations+1; ++i)
	{
		cin >> current_number_of_bikes[i];
	}
	//�����������
	int* visited = new int[number_of_stations+1];
	fill(visited, visited + number_of_stations+1, 0);
	//�����������
	int* distance = new int[number_of_stations+1];
	fill(distance, distance + number_of_stations+1, -1);
	//0���������ȫ�����·��
	vector<shorest_path>* all_station_shorest_paths = new vector<shorest_path>[number_of_stations + 1];
	//�洢����ͼ����ʼ����������ͺ�0ֱ�������ĵ�����·��
	int** station_map = new int*[number_of_stations+1];
	for (int i = 0; i < number_of_stations+1; ++i)
	{
		station_map[i] = new int[number_of_stations+1];
		fill(station_map[i], station_map[i] + number_of_stations+1, -1);
	}
	for (int i = 0; i < number_of_roads; ++i)
	{
		int vertex_1=0, vertex_2=0, length=0;
		cin >> vertex_1 >> vertex_2 >> length;
		station_map[vertex_1][vertex_2] = length;
		station_map[vertex_2][vertex_1] = length;
		if (vertex_1==0)
		{
			distance[vertex_2] = length;
			shorest_path p;
			p.num_of_send = 0;
			p.num_of_take_back = 0;
			p.path_num.push_back(0);
			all_station_shorest_paths[vertex_2].push_back(p);
		}
		if (vertex_2 == 0)
		{
			distance[vertex_1] = length;
			shorest_path p;
			p.num_of_send = 0;
			p.num_of_take_back = 0;
			p.path_num.push_back(0);
			all_station_shorest_paths[vertex_1].push_back(p);
		}
	}
	//Dijkstra�ҳ��������·��
	
	for (int i = 1; i < number_of_stations+1; i++)
	{
		int minn = 0;
		//���ֿ�ʼ��n1����Ľڵ�u
		int u = -1;
		for (int j = 1; j < number_of_stations + 1; ++j)
		{
			if (visited[j] == 0 && distance[j] != -1)
			{
				u = j;
				minn = distance[j];
				break;
			}
		}
		for (int j = 1; j < number_of_stations + 1; ++j)
		{
			if (visited[j] == 0 && distance[j] != -1 && distance[j] < minn)
			{
				u = j;
				minn = distance[j];
			}
		}
		//cout << "\n����ѡ��ڵ㣺" << u << "\n";
		if (u == -1)
		{
			break;
		}
		visited[u] = 1;
		for (int v = 1; v < number_of_stations + 1; ++v)
		{
			int edge_length = station_map[u][v];
			if (visited[v] == 0 && edge_length != -1)
			{
				//�ҵ�uδ�����ʵ��ڽӵ�
				if (distance[v]==-1||distance[u] + edge_length<distance[v])
				{
					//��0��u�ľ������uv�ľ���С��0��v�ľ���ʱ����0����u��vΪ�������0��v��·����������ǰ��ɶ������Ϊ����u��v��
					distance[v] = distance[u] + edge_length;
					//���0��v���е����·��������0��u��ȫ�����·����������v������u�ڵ�
					all_station_shorest_paths[v].clear();
					//��0��u��ȫ�����·��������v
					for (int k = 0; k < all_station_shorest_paths[u].size(); ++k)
					{
						shorest_path p;
						copy_path(&all_station_shorest_paths[u][k], &p);
						p.path_num.push_back(u);
						all_station_shorest_paths[v].push_back(p);
					}
				}
				else if (distance[u] + edge_length == distance[v])
				{
					//��0��u�ľ������uv�ľ������0��v�ľ���ʱ����0����u��vΪһ���µ����·����
					//��0��u��ȫ�����·��������v
					for (int k = 0; k < all_station_shorest_paths[u].size(); ++k)
					{
						shorest_path p;
						copy_path(&all_station_shorest_paths[u][k], &p);
						p.path_num.push_back(u);
						all_station_shorest_paths[v].push_back(p);
					}
				}
			}
		}
	}
	//����0��index_of_the_problem_stationȫ�����·����������ʹ��صĳ�������num_of_send��num_of_take_back
	vector<shorest_path> shorest_paths = all_station_shorest_paths[index_of_the_problem_station];
	for (int i = 0; i < shorest_paths.size(); ++i)
	{
		//���յ������·����
		shorest_paths[i].path_num.push_back(index_of_the_problem_station);
		vector<int> path_num = shorest_paths[i].path_num;
		//���ó�����
		int current_bike_redundant = 0;
		//��������վ��
		for (int j = 1; j < path_num.size(); ++j)
		{
			int deviant_num = current_number_of_bikes[path_num[j]] - capacity_of_each_station / 2;
			if (deviant_num > 0) {
				//˵����ǰվ���и�ԣ���ۻ������ó������У����¸�վ��ȡ��
				current_bike_redundant += deviant_num;
			}
			else if (deviant_num < 0)
			{
				//˵����ǰվ�㲻��
				current_bike_redundant += deviant_num;
				//����ʱ���ó�����<0��˵��ǰ��վ��û���㹻��ĳ��ֲ���վ����Ҫ��ʼ��վ������
				if (current_bike_redundant<0)
				{
					shorest_paths[i].num_of_send += 0 - current_bike_redundant;
					current_bike_redundant = 0;
				}
			}
		}
		//��Ҫ���صĳ�����
		if (current_bike_redundant > 0)
		{
			shorest_paths[i].num_of_take_back = current_bike_redundant;
		}
	}
	//�����������������س��������������·����������
	sort(shorest_paths.begin(), shorest_paths.end(),cmp_shorest_path);
	cout << shorest_paths[0].num_of_send << " " << print_path(shorest_paths[0].path_num) << " " << shorest_paths[0].num_of_take_back;
	return 0;
}

void resolve1018::copy_path(path* source, path* target)
{
	target->num_of_send = source->num_of_send;
	target->num_of_take_back = source->num_of_take_back;
	for (int i = 0; i < source->path_num.size(); ++i)
	{
		target->path_num.push_back(source->path_num[i]);
	}
}

bool resolve1018::cmp_shorest_path(shorest_path p1, shorest_path p2)
{
	return p1.num_of_send==p2.num_of_send?p1.num_of_take_back<p2.num_of_take_back: p1.num_of_send<p2.num_of_send;
}

string resolve1018::print_path(vector<int> path)
{
	string a;
	for (size_t i = 0; i < path.size()-1; ++i)
	{
		a.append(to_string(path[i])).append("->");
	}
	a.append(to_string(path[path.size() - 1]));
	return a;
}