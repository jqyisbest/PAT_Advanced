#include <bits/stdc++.h>
using namespace std;
namespace round_3_resolve1107 {
	int find_father(int a, map<int, int>& fathers);
	void union_father(int a, int b, int *childs_num, map<int, int>& fathers);
	int resolve();
}