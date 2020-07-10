#include "resolve1078.h"
/*
	�Ƚ����СתΪ����
    ����ɢ�У���ͨ�����η�̽�鷨�����ͻ
*/
int resolve1078::resolve()
{
    int m = 0, n = 0, key = 0;
    scanf("%d %d", &m, &n);
    get_prime(m);
    bool *has_used = new bool[m];
    fill(has_used, has_used + m, false);
    for (size_t i = 0; i < n; ++i)
    {
        scanf("%d", &key);
        if (i != 0)
        {
            printf(" ");
        }
        //���η�̽�취�����ͻ
        size_t j = 0;
        for (; j < m; ++j)
        {
            //hashɢ��
            int pos = (key + j * j) % m;
            if (!has_used[pos])
            {
                printf("%d", pos);
                has_used[pos] = true;
                break;
            }
        }
        if (m == j)
        {
            printf("-");
        }
    }
    return 0;
}
void resolve1078::get_prime(int &size)
{
    if (1 == size)
    {
        ++size;
    }
    for (size_t i = 2; i * i <= size; ++i)
    {
        if (size % i == 0)
        {
            //��������
            ++size;
            i = 1;
        }
    }
}
