#include "resolve1082.h"
/*
    按位把后缀翻译好
    按数字把位数翻译好
    贼简单，感觉比上一题20分的都容易

    是我想简单了==

    注意最后两个测试点 0 和 -0 处理
*/
int resolve1082::resolve()
{
    //0-从右往左数前四位，单位为空
    //1-从右往左数中间四位，单位为万
    //2-从右往左数第9位，单位为亿
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
            //加第一个单位 wan
            result.insert(result.begin(), suffix[3].begin(), suffix[3].end());
        }
        else if (current_pos == 9)
        {
            //加第二个单位 yi
            result.insert(result.begin(), suffix[4].begin(), suffix[4].end());
        }
        else if (c == '-')
        {
            //负号
            result.insert(result.begin(), suffix[5].begin(), suffix[5].end());
            break;
        }
        int c_int = c - '0', pos = current_pos % 4;
        if (c_int != 0)
        {
            if (pos == 2)
            {
                //十位
                result.insert(result.begin(), suffix[0].begin(), suffix[0].end());
            }
            else if (3 == pos)
            {
                //百位
                result.insert(result.begin(), suffix[1].begin(), suffix[1].end());
            }
            else if (0 == pos)
            {
                //千位
                result.insert(result.begin(), suffix[2].begin(), suffix[2].end());
            }
        }
        //加入数字
        if (c_int != 0 || (current_pos != 1 && digits[i + 1] != '0') || (current_pos != digits.size() && digits[i - 1] == '-') || (current_pos == digits.size()))
        {
            result.insert(result.begin(), num[c_int].begin(), num[c_int].end());
            //加空格
            if (i != 0)
            {
                result.insert(result.begin(), suffix[6].begin(), suffix[6].end());
            }
        }
    }
    cout << result;
    return 0;
}