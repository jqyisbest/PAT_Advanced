#include "resolve1049.h"
/*
	����ͳ�ƿ϶�����
	ͨ����λ��������ϼ����
	�������˺ܾû���û˼·���Ȱ��𰸵����Ժ�������/(��o��)/~~

	��˼·���������ˡ�����û������Ϊɶ��������==��
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
