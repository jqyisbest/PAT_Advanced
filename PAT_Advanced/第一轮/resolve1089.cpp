#include "resolve1089.h"
/*
    插入排序
    部分有序部分原序，有序个数即为轮数
    合并排序
    至多有一段有序序列个数不一致，有序个数即为2^轮数
    题目设定升序为有序

    坑。。每轮排序结果可能出现和上轮顺序一样的情况，但。。
    题目要的是第一次出现这个有序序列的循环数加1，而不是最后一次
    那就不能用有序个数来推定循环数了

    合并排序部分借鉴（照搬）了柳神的操作
    秀啊，学到了如何模拟归并排序==
*/
int resolve1089::resolve()
{
    int n = 0;
    scanf("%d", &n);
    vector<int> original_nums(n), ordered_nums(n);
    for (size_t i = 0; i < n; ++i)
    {
        scanf("%d", &original_nums[i]);
    }
    for (size_t i = 0; i < n; ++i)
    {
        scanf("%d", &ordered_nums[i]);
    }
    bool is_insert = true, first_num = true;
    int ordered_num_1 = get_ordered_length(ordered_nums, 0);
    for (size_t i = ordered_num_1; i < n; ++i)
    {
        if (original_nums[i] != ordered_nums[i])
        {
            is_insert = false;
            break;
        }
    }

    if (is_insert)
    {
        //插入排序 再插一个
        printf("Insertion Sort\n");
        int i = 0;
        for (; i < ordered_num_1; ++i)
        {
            if (ordered_nums[i] >= original_nums[ordered_num_1])
            {
                break;
            }
            if (!first_num)
            {
                printf(" ");
            }
            printf("%d", ordered_nums[i]);
            first_num = false;
        }
        if (!first_num)
        {
            printf(" ");
        }
        printf("%d", original_nums[ordered_num_1]);
        first_num = false;
        for (; i < ordered_num_1; ++i)
        {
            printf(" ");
            printf("%d", ordered_nums[i]);
        }
        i = ordered_num_1 + 1;
        for (; i < n; ++i)
        {
            printf(" ");
            printf("%d", original_nums[i]);
        }
    }
    else
    {
        //合并排序 再合并一次
        printf("Merge Sort\n");
        bool is_same = false;
        int i = 0, k = 1;
        while (!is_same)
        {
            is_same = true;
            for (i = 0; i < n; i++)
            {
                if (original_nums[i] != ordered_nums[i])
                    is_same = false;
            }
            k = k * 2;
            for (i = 0; i < n / k; ++i)
            {
                sort(original_nums.begin() + i * k, original_nums.begin() + (i + 1) * k);
            }
            sort(original_nums.begin() + n / k * k, original_nums.begin() + n);
        }
        for (size_t j = 0; j < n; j++)
        {
            if (j != 0)
            {
                printf(" ");
            }
            printf("%d", original_nums[j]);
        }
    }
    return 0;
}
int resolve1089::get_ordered_length(vector<int> &nums, int start_index)
{
    int i = start_index;
    for (; i < nums.size(); ++i)
    {
        if (i != 0 && nums[i] < nums[i - 1])
        {
            return i;
        }
    }
    return i - start_index;
}