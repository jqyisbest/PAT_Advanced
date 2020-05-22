#include "resolve1060.h"
/*
    100位，肯定是字符处理了
    分别统计k和有效数字
    然后比对有效数字是否一致
    假设测试用例的浮点数的前部不包含无效0==，且考虑阶数
    比如不会存在 001这样的整数部分、3 1230 12300 判定为NO
    
    好吧，看参考答案得知前部还是会包含无效0，而且科学计数法要求有效位不够要补0(测试点6)
    1、前导0
    2、纯小数的负指数输出
*/
int resolve1060::resolve()
{
    int num_of_significant = 0, k[2]{0};
    char num[100000];
    string significant_digits[2]{""};
    scanf("%d", &num_of_significant);
    for (size_t i = 0; i < 2; ++i)
    {
        scanf("%s", num);
        bool is_integral_part = false;
        bool is_float_part = false;
        bool valuable_in_float = false;
        for (size_t j = 0; j < 100000; ++j)
        {
            //如果是0，把指数位清空
            if (num[j] == '\0')
            {
                if (significant_digits[i] == "")
                {
                    significant_digits[i] = "0";
                    k[i] = 0;
                }
                break;
            }
            char digit = num[j];

            if (digit == '.')
            {
                //进入小数部分
                is_float_part = true;
                is_integral_part = false;
                //如果是纯小数，把有效数字清空
                if (significant_digits[i] == "0")
                {
                    significant_digits[i] = "";
                    k[i] = 0;
                }
                continue;
            }
            if (!is_float_part && !is_integral_part)
            {
                //过滤整数前部无效零
                if (digit > '0' && digit <= '9')
                {
                    is_integral_part = true;
                    valuable_in_float = true;
                }
            }
            if (is_float_part && !valuable_in_float)
            {
                //过滤纯小数数前部无效零
                if (digit > '0' && digit <= '9')
                {
                    valuable_in_float = true;
                }
                else
                {
                    --k[i];
                }
            }
            if (is_integral_part)
            {
                //统计有几位
                ++k[i];
            }
            if (significant_digits[i].length() < num_of_significant && (is_integral_part || (is_float_part && valuable_in_float)))
            {
                significant_digits[i] += digit;
            }
        }
        if (num_of_significant > 0)
        {
            significant_digits[i].append(num_of_significant - significant_digits[i].length(), '0');
        }
    }

    //比较有效位
    if (significant_digits[0] == significant_digits[1] && k[0] == k[1])
    {
        printf("YES 0.%s*10^%d", significant_digits[0].c_str(), k[0]);
    }
    else
    {
        printf("NO 0.%s*10^%d 0.%s*10^%d", significant_digits[0].c_str(), k[0], significant_digits[1].c_str(), k[1]);
    }
    return 0;
}