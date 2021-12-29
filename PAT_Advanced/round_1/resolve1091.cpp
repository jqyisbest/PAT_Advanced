#include "resolve1091.h"
/*
    先降维
    再用bfs判定连通子图

    降不了维度==但可以转为一维数组
    xyz和index的关系：index=z*m*n+x*n+y;

    bfs的带访问队列如果用vector实现最后两个测试点会超时
    但用queue就不会==
    可见queue的效率远高于vector
    0	
    Accepted
    4 ms	452 KB
    1	
    Accepted
    4 ms	296 KB
    2	
    Accepted
    4 ms	404 KB
    3	
    Accepted
    4 ms	496 KB
    4	
    Accepted
    386 ms	38888 KB
    5	
    Accepted
    396 ms	38888 KB
*/
int resolve1091::resolve()
{
    int m = 0, n = 0, l = 0, t = 0, result = 0;
    scanf("%d %d %d %d", &m, &n, &l, &t);
    vector<point *> pixels;
    for (size_t k = 0; k < l; k++)
    {
        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                point *p = new point(i, j, k);
                scanf("%d", &p->flag);
                pixels.push_back(p);
            }
        }
    }

    //bfs start
    //访问数组准备
    vector<bool> visited(l * m * n);
    fill(visited.begin(), visited.begin() + l * m * n, false);
    for (size_t i = 0; i < l * m * n; ++i)
    {
        if (!visited[i] && pixels[i]->flag == 1)
        {
            int total = 0;
            queue<point *> wait_visited;
            wait_visited.push(pixels[i]);
            while (wait_visited.size() > 0)
            {
                point *current_point = wait_visited.front();
                wait_visited.pop();
                int index = is_point(m, n, l, current_point->x, current_point->y, current_point->z);
                total++;
                get_neighbors(m, n, l, index, visited, pixels, wait_visited);
            }
            //走完了一个肿块，看看是否符合大小要求
            // printf("total:%d\n", total);
            if (total >= t)
            {
                result += total;
            }
            total = 0;
        }
    }
    printf("%d", result);
    return 0;
}

int resolve1091::is_point(const int m, const int n, const int l, const int x, const int y, const int z)
{
    if (x < 0 || y < 0 || z < 0)
    {
        return -1;
    }
    if (x >= m || y >= n || z >= l)
    {
        return -1;
    }
    return z * m * n + x * n + y;
}

void resolve1091::get_neighbors(const int m, const int n, const int l, int index, vector<bool> &visited, vector<point *> &pixels, queue<point *> &wait_visited)
{
    visited[index] = true;
    int x = pixels[index]->x;
    int y = pixels[index]->y;
    int z = pixels[index]->z;
    //六个邻接点
    index = is_point(m, n, l, x + 1, y, z);
    if (index >= 0 && !visited[index] && pixels[index]->flag == 1)
    {
        wait_visited.push(pixels[index]);
        visited[index] = true;
    }

    index = is_point(m, n, l, x - 1, y, z);
    if (index >= 0 && !visited[index] && pixels[index]->flag == 1)
    {
        wait_visited.push(pixels[index]);
        visited[index] = true;
    }

    index = is_point(m, n, l, x, y + 1, z);
    if (index >= 0 && !visited[index] && pixels[index]->flag == 1)
    {
        wait_visited.push(pixels[index]);
        visited[index] = true;
    }

    index = is_point(m, n, l, x, y - 1, z);
    if (index >= 0 && !visited[index] && pixels[index]->flag == 1)
    {
        wait_visited.push(pixels[index]);
        visited[index] = true;
    }

    index = is_point(m, n, l, x, y, z + 1);
    if (index >= 0 && !visited[index] && pixels[index]->flag == 1)
    {
        wait_visited.push(pixels[index]);
        visited[index] = true;
    }

    index = is_point(m, n, l, x, y, z - 1);
    if (index >= 0 && !visited[index] && pixels[index]->flag == 1)
    {
        wait_visited.push(pixels[index]);
        visited[index] = true;
    }
}
