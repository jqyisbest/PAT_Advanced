#include "resolve1093.h"
/*
    试试暴力穷举

    234超时。。。

    尝试二分法减少遍历次数
*/
int resolve1093::resolve()
{
    string s;
    cin >> s;
    vector<int> p, a, t;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == 'P')
        {
            p.push_back(i);
        }
        else if (s[i] == 'A')
        {
            a.push_back(i);
        }
        else if (s[i] == 'T')
        {
            t.push_back(i);
        }
    }
    int total = 0, last_j = 0, last_k = 0;
    for (int i = 0; i < p.size(); i++)
    {
        for (int j = last_j = find_pos(p[i], a, last_j); j < a.size(); j++)
        {
            for (int k = last_k = find_pos(a[j], t, last_k); k < t.size(); k++)
            {
                if (p[i] < a[j] && a[j] < t[k])
                {
                    ++total;
                }
            }
        }
    }
    cout << total;
    return 0;
}

int resolve1093::find_pos(int a, vector<int> &target, int start)
{
    int end = target.size() - 1;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (target[mid] < a)
        {
            start = mid + 1;
        }
        else if (target[mid] > a)
        {
            end = mid - 1;
        }
        else
        {
            break;
        }
    }
    return end;
}