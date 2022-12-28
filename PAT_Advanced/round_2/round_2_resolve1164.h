#include <bits/stdc++.h>
using namespace std;
namespace round_2_resolve1164 {
	typedef struct alpha
	{
		vector<string> matrix;
		alpha() {
			matrix.resize(7);
			for (size_t i = 0; i < 7; i++)
			{
				matrix[i].resize(5);
			}
		}
	}alpha;
	void print_word(vector<alpha*> as);
	bool is_capital_letter(char c);
	int resolve();
}