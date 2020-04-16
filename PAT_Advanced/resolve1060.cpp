#include "resolve1060.h"
/*
    100λ���϶����ַ�������
    �ֱ�ͳ��k����Ч����
    Ȼ��ȶ���Ч�����Ƿ�һ��
    ������������ĸ�������ǰ����������Ч0==���ҿ��ǽ���
    ���粻����� 001�������������֡�3 1230 12300 �ж�ΪNO
    
    �ðɣ����ο��𰸵�֪ǰ�����ǻ������Ч0�����ҿ�ѧ������Ҫ����Чλ����Ҫ��0(���Ե�6)
    1��ǰ��0
    2����С���ĸ�ָ�����
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
            //�����0����ָ��λ���
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
                //����С������
                is_float_part = true;
                is_integral_part = false;
                //����Ǵ�С��������Ч�������
                if (significant_digits[i] == "0")
                {
                    significant_digits[i] = "";
                    k[i] = 0;
                }
                continue;
            }
            if (!is_float_part && !is_integral_part)
            {
                //��������ǰ����Ч��
                if (digit > '0' && digit <= '9')
                {
                    is_integral_part = true;
                    valuable_in_float = true;
                }
            }
            if (is_float_part && !valuable_in_float)
            {
                //���˴�С����ǰ����Ч��
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
                //ͳ���м�λ
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

    //�Ƚ���Чλ
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