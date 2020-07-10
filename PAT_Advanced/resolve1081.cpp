#include "resolve1081.h"
int resolve1081::resolve()
{
    long long n, a, b, suma = 0, sumb = 1, gcdvalue;
    scanf("%lld", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld/%lld", &a, &b);
        gcdvalue = find_max_yueshu(a,b);
        a = a / gcdvalue;
        b = b / gcdvalue;
        suma = a * sumb + suma * b;
        sumb = b * sumb;
        gcdvalue = find_max_yueshu(suma, sumb);
        sumb = sumb / gcdvalue;
        suma = suma / gcdvalue;
    }
    long long integer = suma / sumb;
    suma = suma - (sumb * integer);
    if (integer != 0)
    {
        printf("%lld", integer);
        if (suma != 0)
            printf(" ");
    }
    if (suma != 0)
        printf("%lld/%lld", suma, sumb);
    if (integer == 0 && suma == 0)
        printf("0");
    return 0;
}

long long resolve1081::find_max_yueshu(long long a, long long b)
{
    a=abs(a);
    b=abs(b);
    long long min = a > b ? b : a;
    for (long long i = min; i > 1; --i)
    {
        if (a % i == 0 && b % i == 0)
        {
            return i;
        }
    }
    return 1;
}
long long resolve1081::find_min_beishu(long long a, long long b)
{
    a=abs(a);
    b=abs(b);
    long long max = a > b ? a : b;
    while (max % a != 0 || max % b != 0)
    {
        ++max;
    }
    return 1;
}