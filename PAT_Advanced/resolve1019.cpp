#include "resolve1019.h"
/**
	除基取余法
	注意不能用string来装结果，在大进制时有一些数位无法用字符表示亦不能判断是否回文相等，会造成 2、4测试点过不了
*/
int resolve1019::resolve()
{
	long num = 0, base = 0;
	cin >> num >> base;
	if (0 == num)
	{
		cout << "Yes" << endl;
		cout << "0";
	}
	else {
		vector<long> ans ;
		//使用do{}while（）以防止输入为0的情况
		do {
			long t = num%base;
			ans.push_back(t);
			num /= base;
		} while (num != 0);
		size_t i = 0;
		bool is_palindromic = true;
		while (is_palindromic&&i<(ans.size()/2))
		{
			if (ans[i]!= ans[ans.size()-i-1])
			{
				is_palindromic = false;
			}
			else {
				++i;
			}
		}
		cout << (is_palindromic?"Yes":"No") << endl;
		for (size_t i = ans.size()-1; i >0; --i)
		{
			cout << ans[i] << " ";
		}
		cout << ans[0];
	}
	return 0;
}
