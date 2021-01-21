#include "resolve1054.h"
/*
	hash
	800*600=480000 unsigned short int ����
	2B*2^24 <64MB ���У�

	��Ȼ��һ���𰸴���/(��o��)/~~
	0
	����ȷ
	38 ms	33064 KB
	1
	����ȷ
	37 ms	33220 KB
	2
	�𰸴���
	118 ms	33172 KB
	3
	����ȷ
	42 ms	33376 KB
	4
	����ȷ
	38 ms	33360 KB

	��picture[temp] > max_times�ĳ�picture[temp] >= max_times��AC�ˡ����µģ������Ϊɶ
	��Ȼ���������һ����ɫa�;ɵ���Ҫ��ɫb���ִ�����ͬ����ôb�϶�������Ҫ��ɫ���ǿ��Ա��ų��ģ�����һ��һ��Ⱦ�Ҫ�滻�ɣ�
	0
	����ȷ
	34 ms	33196 KB
	1
	����ȷ
	38 ms	33272 KB
	2
	����ȷ
	118 ms	33124 KB
	3
	����ȷ
	38 ms	33192 KB
	4
	����ȷ
	34 ms	33124 KB
*/
int resolve1054::resolve()
{
	const int digit_color_num = 1 << 24;
	//n�� m�� ��һ����m����һ����n�� 
	int m = 0, n = 0, temp = 0, dominant_color = -1, max_times = 0;
	scanf("%d %d", &m, &n);
	unsigned short int *picture = new unsigned short int[digit_color_num];
	fill(picture, picture + digit_color_num, 0);
	for (size_t i = 0; i < m*n; i++)
	{
		scanf("%d", &temp);
		++picture[temp];
		if (picture[temp] >= max_times)
		{
			max_times = picture[temp];
			dominant_color = temp;
		}
	}
	printf("%d", dominant_color);
	return 0;
}
