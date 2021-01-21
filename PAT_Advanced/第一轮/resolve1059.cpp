#include "resolve1059.h"
/*
    这题就尼玛离谱。题都看不懂== 看了答案加查资料才理解/(ㄒoㄒ)/~~
    整数a除以copy整数b(b≠0) 的商正好是整数而没有余数，我们就说b是a的因子。0不是0的因子
    假如整数n除以m，结果是无余数的整数，那么我们称m就是n的因子
    要注意的是，唯有被除数，除数，商皆为整数，余数为零时，此关系才成立。反过来说，我们称知n为m的倍数
    搞清概念以后，思路就是暴力遍历
    先找出根号n以内的全部素数，然后从小到大挨个判别是否为n的因子
    这道题就抄柳神的好了==
*/
int resolve1059::resolve()
{
    //这一段是找出500000以内的全部素数
    //思路是反过来标记出不是素数的数
    vector<bool> prime(500000, true);
    for (int i = 2; i * i < 500000; i++)
    {
        for (int j = 2; j * i < 500000; j++)
        {
            prime[j * i] = false;
        }
    }
    long int a;
    scanf("%ld", &a);
    printf("%ld=", a);
    if (a == 1)
        printf("1");
    //标记是否找到了质因数
    bool state = false;
    for (int i = 2; i < 50000 && a >= 2; i++)
    {
        int cnt = 0, flag = 0;
        while (prime[i] && a % i == 0)
        {
            //找到了这个质因数有几重
            cnt++;
            a = a / i;
            flag = 1;
        }
        if (flag)
        {
            if (state)
            {
                //第一个质因数不需要输出*
                printf("*");
            }
            printf("%d", i);
            state = true;
        }
        if (cnt >= 2)
            printf("^%d", cnt);
    }
    if (a > 1)
        printf("%s%ld", state ? "*" : "", a);
    return 0;
}