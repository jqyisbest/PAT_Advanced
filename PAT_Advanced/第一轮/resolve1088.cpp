#include "resolve1088.h"
/*
    有理分数计算
    先化简
*/
int resolve1088::resolve()
{
    long long a, b, c, d;
    scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
    func(a, b);
    printf(" + ");
    func(c, d);
    printf(" = ");
    func(a * d + b * c, b * d);
    printf("\n");
    func(a, b);
    printf(" - ");
    func(c, d);
    printf(" = ");
    func(a * d - b * c, b * d);
    printf("\n");
    func(a, b);
    printf(" * ");
    func(c, d);
    printf(" = ");
    func(a * c, b * d);
    printf("\n");
    func(a, b);
    printf(" / ");
    func(c, d);
    printf(" = ");
    func(a * d, b * c);
    return 0;
}
long long resolve1088::gcd(long long a, long long b)
{
    if (a < b)
    {
        swap(a, b);
    }
    long long c = a % b;
    if (c != 0)
    {
        return gcd(b, c);
    }
    else
    {
        return b;
    }
}
void resolve1088::func(long long m, long long n)
{
    if (m * n == 0)
    {
        printf("%s", n == 0 ? "Inf" : "0");
        return;
    }
    bool flag = ((m < 0 && n > 0) || (m > 0 && n < 0));
    m = abs(m);
    n = abs(n);
    long long x = m / n;
    printf("%s", flag ? "(-" : "");
    if (x != 0)
        printf("%lld", x);
    if (m % n == 0)
    {
        if (flag)
            printf(")");
        return;
    }
    if (x != 0)
        printf(" ");
    m = m - x * n;
    long long t = gcd(m, n);
    m = m / t;
    n = n / t;
    printf("%lld/%lld%s", m, n, flag ? ")" : "");
}
