#include "common.h"
namespace resolve1087
{
    int resolve();
    typedef struct path
    {
        vector<int> citys;
        int total_happiness;
        double average_happiness;
        path(){
            this->total_happiness=0;
            this->average_happiness=0;
        }
        path(path *p){
            this->total_happiness=p->total_happiness;
            this->average_happiness=p->average_happiness;
            for (size_t i = 0; i < p->citys.size(); ++i)
            {
                this->citys.push_back(p->citys[i]);
            }
        }
    }path;
    typedef struct city_node
    {
        int happiness;
        string name;
        map<int,int> adjacent_cities;
        vector<path*> best_paths;
        city_node(){
            this->happiness=0;
            name.resize(3);
        }
    }city;
    bool cmp_path(path *p1,path *p2);
} // namespace resolve1087