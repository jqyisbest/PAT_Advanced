#include "resolve1028.h"

/**
	�����ԣ���vector�滻Ϊ* �����һ�����Ե㳬ʱ
	˵��resize(n)��newҪ�졣��
	Ҫ����printf��������
*/
int resolve1028::resolve()
{
	vector<record> records;
	int n = 0, c = 0;
	cin >> n >> c;
	records.resize(n);
	for (size_t i = 0; i < n; i++)
	{
		cin >> records[i].id >> records[i].name >> records[i].score;
	}
	if (1 == c)
	{
		sort(records.begin(), records.end(), cmp_by_id_asc);
	}
	else if (2 == c)
	{
		sort(records.begin(), records.end(), cmp_by_name_ndesc);
	}
	else if (3 == c)
	{
		sort(records.begin(), records.end(), cmp_by_score_ndesc);
	}
	--n;
	for (size_t i = 0; i < n; i++)
	{
		cout << records[i].id << " " << records[i].name << " " << records[i].score << endl;
	}
	cout << records[n].id << " " << records[n].name << " " << records[n].score;
	return 0;
}

bool resolve1028::cmp_by_id_asc(record & r1, record & r2)
{
	return r1.id < r2.id;
}

bool resolve1028::cmp_by_name_ndesc(record & r1, record & r2)
{
	return r1.name == r2.name ? r1.id < r2.id : r1.name < r2.name;
}

bool resolve1028::cmp_by_score_ndesc(record & r1, record & r2)
{
	return r1.score == r2.score ? r1.id < r2.id : r1.score < r2.score;
}
