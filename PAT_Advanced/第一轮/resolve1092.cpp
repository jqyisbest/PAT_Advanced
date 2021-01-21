#include "resolve1092.h"
/*
    看整个字符串中是否包含所需的字符
*/
int resolve1092::resolve()
{
    int miss_num = 0, redundant_num = 0;
    string a, b;
    cin >> a >> b;
    map<char, int> char_map;
    for (size_t i = 0; i < a.size(); ++i)
    {
        if (char_map.count(a[i]) > 0)
        {
            char_map[a[i]]++;
        }
        else
        {
            char_map[a[i]] = 1;
        }
    }
    for (size_t i = 0; i < b.size(); ++i)
    {
        if (char_map.count(b[i]) > 0)
        {
            char_map[b[i]]--;
        }
        else
        {
            char_map[b[i]] = -1;
        }
    }
    for (map<char, int>::iterator ch = char_map.begin(); ch != char_map.end(); ++ch)
    {
        if (ch->second > 0)
        {
            redundant_num += ch->second;
        }
        else
        {
            miss_num += -ch->second;
        }
    }
    if (miss_num > 0)
    {
        printf("No %d", miss_num);
    }
    else
    {
        printf("Yes %d", redundant_num);
    }
    return 0;
}