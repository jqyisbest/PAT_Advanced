#include "resolve1084.h"
/*
    ע�⣡����
    transform(orginal.begin(), orginal.end(), orginal.begin(), toupper);
    transform(deficient.begin(), deficient.end(), deficient.begin(), toupper);
    �ڱ��ؿ��Ե���OJ�б����::����
    transform(orginal.begin(), orginal.end(), orginal.begin(), ::toupper);
    transform(deficient.begin(), deficient.end(), deficient.begin(), ::toupper);
*/
int resolve1084::resolve()
{
    string orginal, deficient;
    cin >> orginal >> deficient;
    transform(orginal.begin(), orginal.end(), orginal.begin(), ::toupper);
    transform(deficient.begin(), deficient.end(), deficient.begin(), ::toupper);
    map<char, int> times;
    for (size_t i = 0; i < deficient.size(); ++i)
    {
        times[deficient[i]] = 1;
    }
    for (size_t i = 0; i < orginal.size(); ++i)
    {
        if (times.count(orginal[i]) == 0)
        {
            cout << orginal[i];
            times[orginal[i]] = 1;
        }
    }
    return 0;
}