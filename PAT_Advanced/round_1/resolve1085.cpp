#include "resolve1085.h"
int resolve1085::resolve()
{
    int n = 0, num = 0, temp = 0;
    long long p = 0;
    scanf("%d %lld", &n, &p);
    vector<long long> nums(n);
    for (size_t i = 0; i < n; ++i)
    {
        scanf("%lld", &nums[i]);
    }
    sort(nums.begin(), nums.end());
    //贪心 i是小的 j是大的 逐个尝试
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + num; j < n && nums[i] * p >= nums[j]; ++j)
        {
            num = max(num, j - i + 1);
        }
    }
    printf("%d", num);
    return 0;
}