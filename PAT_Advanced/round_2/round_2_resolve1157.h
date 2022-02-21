#include <bits/stdc++.h>
using namespace std;
namespace round_2_resolve1157 {
	int resolve();
	struct cmp_age
	{
		bool operator () (string a, string b) {
			string a_birth = a.substr(6, 8), b_birth = b.substr(6, 8);
			return a_birth < b_birth;
		}
	};
}