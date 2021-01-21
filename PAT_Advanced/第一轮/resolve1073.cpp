#include "resolve1073.h"
/*
	科学计数法的解析
    以“E”为分界符，E前除小数点和正号外原样输出，E后的数据用于调整小数点位置以及补0
    注意看小数点的位置和补0个数的计算规律！
*/
int resolve1073::resolve()
{
    string origin_num, real_num;
    cin >> origin_num;
    bool after_e = false, exponent_negative = false;
    int real_start_index = 1, exponent = 10000;
    for (size_t i = 0; i < strlen(origin_num.c_str()); ++i)
    {
        char c = origin_num[i];
        if ('E' == c)
        {
            after_e = true;
            if ('-' == origin_num[++i])
            {
                exponent_negative = true;
            }
            continue;
        }
        else if ('.' == c)
        {
            continue;
        }
        if (after_e)
        {
            exponent = stoi(origin_num.substr(i));
            break;
        }
        else
        {
            if ('+' != c)
            {
                real_num.push_back(c);
            }
            else
            {
                real_start_index = 0;
            }
        }
    }
    //处理小数点和补0
    if (exponent_negative)
    {
        //补0
        real_num.insert(real_start_index, exponent, '0');
        //小数点左移
        real_num.insert(real_start_index + 1, 1, '.');
    }
    else
    {
        //补0
        int num_after_dot_count = strlen(real_num.c_str()) - real_start_index - 1;
        int zero_add_num = exponent - num_after_dot_count;
        if (zero_add_num >= 0)
        {
            //补0了就不需要小数点了
            real_num.insert(strlen(real_num.c_str()), zero_add_num, '0');
        }
        else
        {
            //小数点右移
            real_num.insert(real_start_index + 1 + exponent, 1, '.');
        }
    }
    cout << real_num;
    return 0;
}