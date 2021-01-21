#include "resolve1087.h"
/*
    dijsktra
    ע�⣬��ʼ�����Ҹ��Ȳ������Ҹ��ȼ��㣬����ƽ��ֵʱ������Ӧ�ü�һ
*/
int resolve1087::resolve()
{
    int n = 0, k = 0;
    city *c = new city();
    scanf("%d %d %s", &n, &k, &c->name[0]);
    map<string, int> city_index;
    vector<city *> cities;
    cities.push_back(c);
    city_index[c->name] = 0;
    //���Ҹ���
    for (size_t i = 1; i <= n - 1; ++i)
    {
        c = new city();
        scanf("%s %d", &c->name[0], &c->happiness);
        cities.push_back(c);
        city_index[c->name] = i;
    }
    //��·��
    for (size_t i = 0; i < k; ++i)
    {
        string city_1, city_2;
        int cost = 0;
        city_1.resize(3);
        city_2.resize(3);
        scanf("%s %s %d", &city_1[0], &city_2[0], &cost);
        cities[city_index[city_1]]->adjacent_cities[city_index[city_2]] = cost;
        cities[city_index[city_2]]->adjacent_cities[city_index[city_1]] = cost;
    }
    //dijsktra
    bool *visited = new bool[n];
    int *cost = new int[n];
    fill(visited, visited + n, false);
    fill(cost, cost + n, -1);
    //��ʼ�����ڳ���·����Ϣ��cost��happiness
    for (map<int, int>::iterator it = cities[0]->adjacent_cities.begin(); it != cities[0]->adjacent_cities.end(); ++it)
    {
        cost[it->first] = it->second;
        path *p = new path();
        p->citys.push_back(0);
        p->citys.push_back(it->first);
        cities[it->first]->best_paths.push_back(p);
    }
    visited[0] = true;
    for (size_t i = 0; i < n; ++i)
    {
        //ѡ��һ�����ʵ� δ��������·�����
        int u = -1;
        int min = 0;
        for (size_t j = 0; j < n; ++j)
        {
            if (!visited[j] && cost[j] != -1 && (cost[j] < min || u == -1))
            {
                u = j;
                min = cost[j];
            }
        }
        if (u == -1)
        {
            break;
        }

        visited[u] = true;
        //���������ڳ���
        for (map<int, int>::iterator it = cities[u]->adjacent_cities.begin(); it != cities[u]->adjacent_cities.end(); ++it)
        {
            if ((cost[it->first] > cost[u] + it->second) || cost[it->first] == -1)
            {
                //��·�̶�||�µĿɴ�·��
                //��·��~��·��ȫ������
                cities[it->first]->best_paths.clear();
                for (size_t j = 0; j < cities[u]->best_paths.size(); ++j)
                {
                    path *new_path = new path(cities[u]->best_paths[j]);
                    new_path->citys.push_back(it->first);
                    cities[it->first]->best_paths.push_back(new_path);
                }
                //����·��
                cost[it->first] = cost[u] + it->second;
            }
            else if (cost[it->first] == cost[u] + it->second)
            {
                //��·��һ��
                for (size_t j = 0; j < cities[u]->best_paths.size(); ++j)
                {
                    path *new_path = new path(cities[u]->best_paths[j]);
                    new_path->citys.push_back(it->first);
                    cities[it->first]->best_paths.push_back(new_path);
                }
            }
        }
    }
    //����ÿ��·����ƽ���Ҹ��Ȳ�����
    for (size_t i = 0; i < cities[city_index["ROM"]]->best_paths.size(); ++i)
    {
        path *p = cities[city_index["ROM"]]->best_paths[i];
        for (size_t j = 0; j < p->citys.size(); ++j)
        {
            p->total_happiness += cities[p->citys[j]]->happiness;
        }
        p->average_happiness = (double)p->total_happiness / (p->citys.size() - 1.0);
    }
    sort(cities[city_index["ROM"]]->best_paths.begin(), cities[city_index["ROM"]]->best_paths.end(), cmp_path);
    printf("%d %d %d %d\n", (int)(cities[city_index["ROM"]]->best_paths.size()), cost[city_index["ROM"]], cities[city_index["ROM"]]->best_paths[0]->total_happiness, (int)(cities[city_index["ROM"]]->best_paths[0]->total_happiness / (cities[city_index["ROM"]]->best_paths[0]->citys.size() - 1)));
    path *best_path = cities[city_index["ROM"]]->best_paths[0];
    for (size_t i = 0; i < best_path->citys.size(); i++)
    {
        if (i != 0)
        {
            printf("->");
        }
        printf("%s", cities[best_path->citys[i]]->name.c_str());
    }
    return 0;
}
bool resolve1087::cmp_path(path *p1, path *p2)
{
    return p1->total_happiness == p2->total_happiness ? p1->average_happiness > p2->average_happiness : p1->total_happiness > p2->total_happiness;
}