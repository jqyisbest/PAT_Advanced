#include "resolve1073.h"
/*
	��ѧ�������Ľ���
    �ԡ�E��Ϊ�ֽ����Eǰ��С�����������ԭ�������E����������ڵ���С����λ���Լ���0
    ע�⿴С�����λ�úͲ�0�����ļ�����ɣ�
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
    //����С����Ͳ�0
    if (exponent_negative)
    {
        //��0
        real_num.insert(real_start_index, exponent, '0');
        //С��������
        real_num.insert(real_start_index + 1, 1, '.');
    }
    else
    {
        //��0
        int num_after_dot_count = strlen(real_num.c_str()) - real_start_index - 1;
        int zero_add_num = exponent - num_after_dot_count;
        if (zero_add_num >= 0)
        {
            //��0�˾Ͳ���ҪС������
            real_num.insert(strlen(real_num.c_str()), zero_add_num, '0');
        }
        else
        {
            //С��������
            real_num.insert(real_start_index + 1 + exponent, 1, '.');
        }
    }
    cout << real_num;
    return 0;
}