#include "resolve1018.h"
/**
	Dijkstra搜索到所有最短路径
	对每条最短路径求带出去和带回来的车辆数
	根据带出去的数量和带回来的数量从小到大排序
	输出最少的那一条
*/
int resolve1018::resolve()
{
	//每个站点的容量、站点的数量、问题站点的索引（0为起点、其余站点从1开始）、路径数量
	int capacity_of_each_station = 0, number_of_stations = 0, index_of_the_problem_station = 0, number_of_roads = 0;
	cin >> capacity_of_each_station >> number_of_stations >> index_of_the_problem_station >> number_of_roads;
	//每个站点现有车数
	int* current_number_of_bikes = new int[number_of_stations+1];
	for (int i = 1; i < number_of_stations+1; ++i)
	{
		cin >> current_number_of_bikes[i];
	}
	//定义访问数组
	int* visited = new int[number_of_stations+1];
	fill(visited, visited + number_of_stations+1, 0);
	//定义距离数组
	int* distance = new int[number_of_stations+1];
	fill(distance, distance + number_of_stations+1, -1);
	//0到各个点的全部最短路径
	vector<shorest_path>* all_station_shorest_paths = new vector<shorest_path>[number_of_stations + 1];
	//存储无向图并初始化距离数组和和0直接相连的点的最短路径
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
	//Dijkstra找出所有最短路径
	
	for (int i = 1; i < number_of_stations+1; i++)
	{
		int minn = 0;
		//本轮开始离n1最近的节点u
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
		//cout << "\n本轮选择节点：" << u << "\n";
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
				//找到u未被访问的邻接点
				if (distance[v]==-1||distance[u] + edge_length<distance[v])
				{
					//当0至u的距离加上uv的距离小于0至v的距离时，从0经由u至v为最近，则将0至v的路径（不管以前是啥）更改为经由u至v。
					distance[v] = distance[u] + edge_length;
					//清空0至v现有的最短路径，将从0至u的全部最短路径，拷贝至v并加上u节点
					all_station_shorest_paths[v].clear();
					//将0至u的全部最短路径复制至v
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
					//当0至u的距离加上uv的距离等于0至v的距离时，从0经由u至v为一条新的最短路径。
					//将0至u的全部最短路径复制至v
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
	//计算0至index_of_the_problem_station全部最短路径所需带出和带回的车辆数：num_of_send、num_of_take_back
	vector<shorest_path> shorest_paths = all_station_shorest_paths[index_of_the_problem_station];
	for (int i = 0; i < shorest_paths.size(); ++i)
	{
		//将终点添加至路径中
		shorest_paths[i].path_num.push_back(index_of_the_problem_station);
		vector<int> path_num = shorest_paths[i].path_num;
		//可用车数量
		int current_bike_redundant = 0;
		//修正各个站点
		for (int j = 1; j < path_num.size(); ++j)
		{
			int deviant_num = current_number_of_bikes[path_num[j]] - capacity_of_each_station / 2;
			if (deviant_num > 0) {
				//说明当前站点有富裕，累积至可用车数量中，供下个站点取用
				current_bike_redundant += deviant_num;
			}
			else if (deviant_num < 0)
			{
				//说明当前站点不足
				current_bike_redundant += deviant_num;
				//若此时可用车数量<0，说明前面站点没有足够多的车弥补本站，需要从始发站带车来
				if (current_bike_redundant<0)
				{
					shorest_paths[i].num_of_send += 0 - current_bike_redundant;
					current_bike_redundant = 0;
				}
			}
		}
		//需要带回的车辆数
		if (current_bike_redundant > 0)
		{
			shorest_paths[i].num_of_take_back = current_bike_redundant;
		}
	}
	//按带出车辆数、带回车辆数对所有最短路径进行排序
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