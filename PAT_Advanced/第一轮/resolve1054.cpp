#include "resolve1054.h"
/*
	hash
	800*600=480000 unsigned short int 足以
	2B*2^24 <64MB 可行！

	居然有一个答案错误/(ㄒoㄒ)/~~
	0
	答案正确
	38 ms	33064 KB
	1
	答案正确
	37 ms	33220 KB
	2
	答案错误
	118 ms	33172 KB
	3
	答案正确
	42 ms	33376 KB
	4
	答案正确
	38 ms	33360 KB

	把picture[temp] > max_times改成picture[temp] >= max_times就AC了。。猜的，不理解为啥
	虽然，如果存在一种颜色a和旧的主要颜色b出现次数相同，那么b肯定不是主要颜色，是可以被排除的，但不一定一相等就要替换吧？
	0
	答案正确
	34 ms	33196 KB
	1
	答案正确
	38 ms	33272 KB
	2
	答案正确
	118 ms	33124 KB
	3
	答案正确
	38 ms	33192 KB
	4
	答案正确
	34 ms	33124 KB
*/
int resolve1054::resolve()
{
	const int digit_color_num = 1 << 24;
	//n行 m列 亦一行有m个，一列有n个 
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
