#include "resolve1083.h"
/*
    利用数组排序
*/
int resolve1083::resolve()
{
    int n = 0, low = 0, high = 0;
    cin >> n;
    vector<student *> ss(101, nullptr);
    for (; n > 0; --n)
    {
        student *s = new student();
        cin >> s->name >> s->id >> s->grade;
        ss[s->grade] = s;
    }
    cin >> low >> high;
    if (low > high)
    {
        swap(low, high);
    }
    for (size_t i = high; i >= low; --i)
    {
        if (ss[i]!=nullptr)
        {
            cout<<ss[i]->name<<" "<<ss[i]->id<<"\n";
            ++n;
        }
    }
    if (n<=0)
    {
        cout<<"NONE";
    }
    return 0;
}