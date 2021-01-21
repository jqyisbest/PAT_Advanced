#include "resolve1058.h"
/*
    相加进位即可
*/
int resolve1058::resolve()
{
    //a无进制，b17进制，c29进制
    int digits[6];
    int carry_limit[3] = {-1, 17, 29};
    bool need_carry = false;
    scanf("%d.%d.%d %d.%d.%d", &digits[0], &digits[1], &digits[2], &digits[3], &digits[4], &digits[5]);
    for (int i = 2; i >= 0; --i)
    {
        digits[i] = digits[i] + digits[i + 3] + (need_carry ? 1 : 0);
        need_carry = carry_limit[i] != -1 && digits[i] >= carry_limit[i];
        if (need_carry)
        {
            digits[i] %= carry_limit[i];
        }
    }
    printf("%d.%d.%d", digits[0], digits[1], digits[2]);
    return 0;
}