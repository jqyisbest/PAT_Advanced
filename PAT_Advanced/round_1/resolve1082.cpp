#include "resolve1082.h"
/*
    ��λ�Ѻ�׺�����
    �����ְ�λ�������
    ���򵥣��о�����һ��20�ֵĶ�����

    ���������==

    ע������������Ե� 0 �� -0 ����
*/
int resolve1082::resolve()
{
    //0-����������ǰ��λ����λΪ��
    //1-�����������м���λ����λΪ��
    //2-������������9λ����λΪ��
    int current_pos = 1;
    string suffix[7]{" Shi", " Bai", " Qian", " Wan", " Yi", "Fu", " "};
    string num[10]{"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    string digits, result;
    cin >> digits;
    for (int i = digits.size() - 1; i >= 0; --i, ++current_pos)
    {
        char c = digits[i];

        if (current_pos == 5)
        {
            //�ӵ�һ����λ wan
            result.insert(result.begin(), suffix[3].begin(), suffix[3].end());
        }
        else if (current_pos == 9)
        {
            //�ӵڶ�����λ yi
            result.insert(result.begin(), suffix[4].begin(), suffix[4].end());
        }
        else if (c == '-')
        {
            //����
            result.insert(result.begin(), suffix[5].begin(), suffix[5].end());
            break;
        }
        int c_int = c - '0', pos = current_pos % 4;
        if (c_int != 0)
        {
            if (pos == 2)
            {
                //ʮλ
                result.insert(result.begin(), suffix[0].begin(), suffix[0].end());
            }
            else if (3 == pos)
            {
                //��λ
                result.insert(result.begin(), suffix[1].begin(), suffix[1].end());
            }
            else if (0 == pos)
            {
                //ǧλ
                result.insert(result.begin(), suffix[2].begin(), suffix[2].end());
            }
        }
        //��������
        if (c_int != 0 || (current_pos != 1 && digits[i + 1] != '0') || (current_pos != digits.size() && digits[i - 1] == '-') || (current_pos == digits.size()))
        {
            result.insert(result.begin(), num[c_int].begin(), num[c_int].end());
            //�ӿո�
            if (i != 0)
            {
                result.insert(result.begin(), suffix[6].begin(), suffix[6].end());
            }
        }
    }
    cout << result;
    return 0;
}