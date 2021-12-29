#include "resolve1001.h"

int resolve1001::resolve()
{
	int a = 0, b = 0;
	cin >> a >> b;
	int c = a + b;
	string s = "";
	s = to_string(c);
	vector<char> v;
	for (int i = s.size() - 1, j = 1; i >= 0; --i, ++j)
	{
		v.push_back(s[i]);
		if (j % 3 == 0 && i > 0 && s[i - 1] != '-')
		{
			v.push_back(',');
		}
	}
	reverse(v.begin(), v.end());
	for (size_t i = 0; i < v.size(); i++)
	{
		printf("%c", v[i]);
	}
	return 0;
}
