#include "resolve1139.h"

int resolve1139::resolve()
{
	int n, m, k;
	scanf("%d%d", &n, &m);
	map<int, bool> arr;
	vector<int> v[10000];
	for (int i = 0; i < m; i++) {
		string a, b;
		cin >> a >> b;
		if (a.length() == b.length()) {
			v[abs(stoi(a))].push_back(abs(stoi(b)));
			v[abs(stoi(b))].push_back(abs(stoi(a)));
		}
		arr[abs(stoi(a)) * 10000 + abs(stoi(b))] = arr[abs(stoi(b)) * 10000 +
			abs(stoi(a))] = true;
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int c, d;
		cin >> c >> d;
		vector<node> ans;
		for (int j = 0; j < v[abs(c)].size(); j++) {
			for (int k = 0; k < v[abs(d)].size(); k++) {
				if (v[abs(c)][j] == abs(d) || abs(c) == v[abs(d)][k]) continue;
				if (arr[v[abs(c)][j] * 10000 + v[abs(d)][k]] == true)
					ans.push_back(node{ v[abs(c)][j], v[abs(d)][k] });
			}
		}
		sort(ans.begin(), ans.end(), cmp_node);
		printf("%d\n", int(ans.size()));
		for (int j = 0; j < ans.size(); j++)
			printf("%04d %04d\n", ans[j].id_1, ans[j].id_2);
	}
	return 0;
}

bool resolve1139::cmp_node(node &n_1, node &n_2)
{
	return n_1.id_1 == n_2.id_1 ? n_1.id_2 < n_2.id_2 : n_1.id_1 < n_2.id_1;
}
