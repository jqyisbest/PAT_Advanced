#include "resolve1104.h"
/*
	这道题理应用树状数组/线段树解决。
	但我找到了sum的规律233333
	sum=每个数字 * 从前往后这是第几个数（从1起，后同） * 从后往前这是第几个数

	卧槽。不对。为啥啊。

	吐了，原来是有同学遇到了由于c++double类型在高精度多次运算下的误差较大，导致采用不同算法（说实话我完全没想过他那种算法_(°:з」∠)_）得出的sum值差异过大，超出了OJ的精度限制（https://blog.zhengrh.com/post/about-double/）。
	然后，然后PTA就改了测试样例2。。。/(ㄒoㄒ)/~~

	新的AC代码要求考虑到C++double类型精度损失问题，需要先*1000并存至longlong类型再计算（柳神说的对，这样并不能完全避免精度损失问题==；但这样可以让不同算法（这位Z同学的算法）和其它算法得出的结果均通过OJ）

	注意是相乘后的结果的小数点右移3位，不能是temp这个数本身！
	这题告诉我们以后写题要考虑double精度问题，在遇到double类型多次运算的问题都放大1000用longlong运算，运算结果/1000.0
*/
int resolve1104::resolve()
{
	double n = 0.0, temp = 0.0;
	long long num = 0, sum = 0;
	scanf("%lf", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lf", &temp);
		//num = temp * 1000;
		sum += (long long)(temp * 1000 * (n - i)*(i + 1));
	}
	printf("%.2lf", sum / 1000.0);
	return 0;
}
