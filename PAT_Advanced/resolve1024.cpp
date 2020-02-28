#include "resolve1024.h"
/**
	好奇怪，按位数来说，ull应该够了。
	继1023之后又写了一遍字符数加法╮(╯▽╰)╭
*/
int resolve1024::resolve()
{
	string num;
	int max_step, step = 0;
	cin >> num >> max_step;
	reverse_add(num, step, max_step);
	cout << num << endl;
	cout << step;
	return 0;
}

string resolve1024::reverse(string num)
{
	reverse(num.begin(), num.end());
	return num;
}

void resolve1024::reverse_add(string& num, int& step, int& max_step)
{
	string num_r = reverse(num);
	//进位标志
	int flag = 0;
	if (num != num_r && step < max_step)
	{
		for (int i = num.length()-1; i >=0 ; --i)
		{ 
			num[i] = num[i] + num_r[i] + flag - '0';
			flag = 0;
			if (num[i] > '9')
			{ 
				num[i] = num[i] - 10;
				flag = 1;
			} 
		}    
		if (flag)
		{
			num.insert(0,1,'1');
		}
		++step;
		reverse_add(num, step, max_step);
	}
}
