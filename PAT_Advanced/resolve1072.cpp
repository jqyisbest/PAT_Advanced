#include "resolve1072.h"
/*
	从M个候选点分别计算单源最短路径，从计算出的结果中遍历出是否每个住宅都在服务范围内以及离住宅最短的距离是多少。
*/
int resolve1072::resolve()
{
    int num_of_house = 0, num_of_station = 0, num_of_loads = 0, max_service_range = 0, gas_mark_index = 1, house_mark_index = 1;
    scanf("%d %d %d %d", &num_of_house, &num_of_station, &num_of_loads, &max_service_range);
    //生成城市/加油站index->索引号的映射关系
    map<string, int> node_index;
    // for (size_t i = 1; i <= num_of_house; ++i)
    // {
    //     string index = "";
    //     index.push_back('0' + i);
    //     node_index[index] = i + num_of_station;
    // }
    // for (size_t i = 1; i <= num_of_station; ++i)
    // {
    //     string index = "G";
    //     index.push_back('0' + i);
    //     node_index[index] = i;
    // }
    long **station_maps = new long *[num_of_station + num_of_house + 1];
    fill(station_maps, station_maps + num_of_station + num_of_house + 1, nullptr);
    for (int i = 0; i < num_of_loads; ++i)
    {
        string index_1, index_2;
        index_1.resize(4);
        index_2.resize(4);
        long dist = 0;
        scanf("%s %s %ld", &index_1[0], &index_2[0], &dist);
        index_1 = index_1.substr(0, strlen(index_1.c_str()));
        index_2 = index_2.substr(0, strlen(index_2.c_str()));
        if (node_index.count(index_1) == 0)
        {
            if (index_1[0] == 'G')
            {
                node_index[index_1] = gas_mark_index++;
            }
            else
            {
                node_index[index_1] = num_of_station + house_mark_index++;
            }
        }
        if (node_index.count(index_2) == 0)
        {
            if (index_2[0] == 'G')
            {
                node_index[index_2] = gas_mark_index++;
            }
            else
            {
                node_index[index_2] = num_of_station + house_mark_index++;
            }
        }
        int index_1_int = node_index[index_1], index_2_int = node_index[index_2];
        if (station_maps[index_1_int] == nullptr)
        {
            station_maps[index_1_int] = new long[num_of_station + num_of_house + 1];
            fill(station_maps[index_1_int], station_maps[index_1_int] + num_of_station + num_of_house + 1, -1);
        }
        if (station_maps[index_2_int] == nullptr)
        {
            station_maps[index_2_int] = new long[num_of_station + num_of_house + 1];
            fill(station_maps[index_2_int], station_maps[index_2_int] + num_of_station + num_of_house + 1, -1);
        }
        station_maps[index_1_int][index_2_int] = dist;
        station_maps[index_2_int][index_1_int] = dist;
    }

    vector<gas_station *> candidate_stations;
    for (int k = 1; k <= num_of_station; ++k)
    {
        string start_node = "G";
        start_node.push_back('0' + k);
        int station_index = node_index[start_node];
        //dijkstra start
        bool *visited = new bool[num_of_house + num_of_station + 1];
        fill(visited, visited + num_of_house + num_of_station + 1, false);
        long *distance = new long[num_of_house + num_of_station + 1];
        //初始化distance
        long *paths = station_maps[node_index[start_node]];
        if (nullptr != paths)
        {
            for (size_t i = 0; i < num_of_house + num_of_station + 1; ++i)
            {
                distance[i] = paths[i];
            }
        }
        //选择一个离起点最近且未被访问的节点作为下一个访问点u
        for (size_t i = 0; i < num_of_house + num_of_station + 1; ++i)
        {
            int u = -1;
            int min = 0;
            visited[0] = true;
            visited[station_index] = true;
            //找一个离start_node最近的未访问节点
            for (size_t j = 0; j < num_of_house + num_of_station + 1; ++j)
            {
                if (!visited[j] && distance[j] != -1)
                {
                    if (distance[j] < min || u == -1)
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
            long *adjacent_path = station_maps[u];
            for (size_t j = 0; j < num_of_house + num_of_station + 1; ++j)
            {
                if (adjacent_path[j] != -1 && !visited[j])
                {
                    long new_dist = distance[u] + adjacent_path[j];
                    if (distance[j] == -1 || new_dist < distance[j])
                    {
                        distance[j] = new_dist;
                    }
                }
            }
        }
        //dijkstra end

        bool can_service_all = true;
        long min_dist = -1;
        double avg_dist = 0.0;
        for (size_t i = num_of_station + 1; i <= num_of_house + num_of_station; ++i)
        {
            if (distance[i] == -1 || distance[i] > max_service_range)
            {
                //存在不在服务范围内的城市
                can_service_all = false;
                break;
            }
            if (distance[i] < min_dist || min_dist == -1)
            {
                min_dist = distance[i];
            }
            avg_dist += distance[i];
        }
        if (can_service_all)
        {
            double num_temp = (double)num_of_house;
            avg_dist /= num_temp;
            gas_station *g = new gas_station();
            g->index = start_node;
            g->min_dist = min_dist;
            g->average_dist = avg_dist;
            candidate_stations.push_back(g);
        }
        free(visited);
        free(distance);
    }
    //dijkstra end
    if (candidate_stations.size() == 0)
    {
        printf("No Solution");
    }
    else
    {
        sort(candidate_stations.begin(), candidate_stations.end(), cmp_station);
        printf("%s\n%.1f %.1f", candidate_stations[0]->index.c_str(), candidate_stations[0]->min_dist, candidate_stations[0]->average_dist);
    }
    return 0;
}

bool resolve1072::cmp_station(gas_station *g1, gas_station *g2)
{
    return g1->min_dist == g2->min_dist ? g1->average_dist == g2->average_dist ? g1->index < g2->index : g1->average_dist < g2->average_dist : g1->min_dist > g2->min_dist;
}