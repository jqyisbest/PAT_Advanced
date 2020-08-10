#include "resolve1128.h"
/*
	哦，逻辑题，抄的柳神的
	斜对角线：y轴方向距离等于x轴方向距离：abs(v[j] - v[t]) == abs(j - t)
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
