#include "resolve1049.h"
/*
	遍历统计肯定不行
	通过数位来排列组合计算吧
	哎，想了很久还是没思路，先按答案的做以后重做吧/(ㄒoㄒ)/~~

	答案思路大致明白了。但还没想明白为啥不会算重==；
*/
int resolve1049::resolve()
{
	int n, left = 0, right = 0, a = 1, now = 1, ans = 0;    
	scanf("%d", &n);    
	while(n / a) {        
		left = n / (a * 10), now = n / a % 10, right = n % a;        
		if(now == 0) ans += left * a;        
		else if(now == 1) ans += left * a + right + 1;        
		else ans += (left + 1) * a;        
		a = a * 10;    
	}    
	printf("%d", ans);    
	return 0; 
}
