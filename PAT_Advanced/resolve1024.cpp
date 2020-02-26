#include "resolve1024.h"

int resolve1024::resolve()
{
	long long num = 0;
	int max_step, step = 0;
	cin >> num >> max_step;
	reverse_add(num, step, max_step);
	cout << num << endl;
	cout << step;
	return 0;
}

long long resolve1024::reverse(long long num)
{
	string result;
	do
	{
		int digit = num % 10;
		result.push_back(digit + '0');
		num = num / 10;
	} while (num != 0);
	return stoll(result);
}

void resolve1024::reverse_add(long long& num, int& step,int& max_step)
{
	if(num != reverse(num)&&step<max_step)
	{
		num += reverse(num);
		++step;
		reverse_add(num,step,max_step);
	}
}
