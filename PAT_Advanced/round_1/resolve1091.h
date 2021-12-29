#include "common.h"
namespace resolve1091
{
    int resolve();
    typedef struct point
    {
        int x, y, z, flag;
        point(int x, int y, int z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
            this->flag = 0;
        }
    } point;
    int is_point(const int m, const int n, const int l, const int x, const int y, const int z);
    void get_neighbors(const int m, const int n, const int l, int index, vector<bool> &visited, vector<point *> &pixels, queue<point *> &wait_visited);
} // namespace resolve1091