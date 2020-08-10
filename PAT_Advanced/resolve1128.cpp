#include "resolve1128.h"
/*
	Ŷ���߼��⣬���������
	б�Խ��ߣ�y�᷽��������x�᷽����룺abs(v[j] - v[t]) == abs(j - t)
*/
int resolve1128::resolve()
{
	int k, n;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> n;
		vector<int> v(n);
		bool result = true;
		for (int j = 0; j < n; j++) {
			cin >> v[j];
			for (int t = 0; t < j; t++) {
				if (v[j] == v[t] || abs(v[j] - v[t]) == abs(j - t)) {
					result = false;
					break;
				}
			}
		}
		cout << (result == true ? "YES\n" : "NO\n");
	}
	return 0;
}
