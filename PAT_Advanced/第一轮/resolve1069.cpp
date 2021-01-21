#include "resolve1069.h"

int resolve1069::resolve()
{
	vector<char> digit_chr;
	digit_chr.resize(4);
	int digits = 0,temp1=0,temp2=0;
	scanf("%d", &digits);
	if (digits%1111==0)
	{
		//四位数均相同
		printf("%04d - %04d = 0000", digits, digits);
	}
	else
	{
		do
		{
			change_to_str(digits, digit_chr);
			sort(digit_chr.begin(), digit_chr.end(), cmp_desc);
			change_to_int(digit_chr, temp1);
			sort(digit_chr.begin(), digit_chr.end(), cmp_asc);
			change_to_int(digit_chr, temp2);
			digits = temp1 - temp2;
			printf("%04d - %04d = %04d\n", temp1, temp2, digits);
		} while (digits!= 6174);
	}
	return 0;
}

void resolve1069::change_to_str(int digits, vector<char>& digit_chr)
{
	digit_chr.clear();
	do
	{
		digit_chr.insert(digit_chr.begin(), '0'+digits % 10);
		digits /= 10;
	} while (digits > 0);
	for (size_t i = digit_chr.size(); i < 4; i++)
	{
		digit_chr.insert(digit_chr.begin(), '0');
	}
}

void resolve1069::change_to_int(vector<char>& digit_chr, int & digits)
{
	string a;
	for (size_t i = 0; i < 4; i++)
	{
		a.append(1, digit_chr[i]);
	}
	digits = stoi(a);
}

bool resolve1069::cmp_asc(char c1, char c2)
{
	return c1<c2;
}

bool resolve1069::cmp_desc(char c1, char c2)
{
	return c1>c2;
}
