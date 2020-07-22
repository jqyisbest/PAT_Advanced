#include "resolve1100.h"
/*
	先判断是数字还是英文
	在调用相应转换
*/
int resolve1100::resolve()
{
	int n = 0;
	cin >> n;
	getchar();
	string s;
	for (size_t i = 0; i < n; i++)
	{
		getline(cin, s);
		if (s[0] >= '0'&&s[0] <= '9')
		{
			//数字
			cout << translate(stoi(s)) << "|Z";
		}
		else
		{
			//字母
			cout << translate(s) << "|Z";
		}
	}
	return 0;
}

int resolve1100::translate(string s)
{
	map<string, int> nums_1;
	nums_1["tret"] = 0;
	nums_1["jan"] = 1;
	nums_1["feb"] = 2;
	nums_1["mar"] = 3;
	nums_1["apr"] = 4;
	nums_1["may"] = 5;
	nums_1["jun"] = 6;
	nums_1["jly"] = 7;
	nums_1["aug"] = 8;
	nums_1["sep"] = 9;
	nums_1["oct"] = 10;
	nums_1["nov"] = 11;
	nums_1["dec"] = 12;
	nums_1["tam"] = 1 * 13;
	nums_1["hel"] = 2 * 13;
	nums_1["maa"] = 3 * 13;
	nums_1["huh"] = 4 * 13;
	nums_1["tou"] = 5 * 13;
	nums_1["kes"] = 6 * 13;
	nums_1["hei"] = 7 * 13;
	nums_1["elo"] = 8 * 13;
	nums_1["syy"] = 9 * 13;
	nums_1["lok"] = 10 * 13;
	nums_1["mer"] = 11 * 13;
	nums_1["jou"] = 12 * 13;
	string key;
	int result = 0;
	for (size_t i = 0; i < s.size(); ++i)
	{
		if (s[i] == ' ')
		{
			result += nums_1[key];
			key = "";
		}
		else
		{
			key.push_back(s[i]);
		}
	}
	result += nums_1[key];
	return result;
}

string resolve1100::translate(int num)
{
	string s1[13] = { "tret" ,"jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec" };
	string s2[13] = { "tret" ,"tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou" };
	string result;
	if (num == 0)
	{
		result += s1[num];
	}
	else
	{
		if (num / 13 != 0)
		{
			result += s2[num / 13];
			num %= 13;
		}
		if (result.size() > 0 && num != 0)
		{
			result += " ";
		}
		if (num != 0)
		{
			result += s1[num];
		}
	}
	return result;
}