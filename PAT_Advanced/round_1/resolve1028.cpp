#include "resolve1028.h"

/**
	奇怪的OJ
	第一次用vector+string id OAC 300ms
	后面再用 string id 就一直报超时了
	改为 int id + printf 后稳定至270ms
	将vector 改为 array 后降至240ms
	估计把string name换为char*会更快，省了一个c_str()，懒得搞了╮(╯▽╰)╭
	抬走，下一个
*/
int resolve1028::resolve()
{
	int n = 0, c = 0;
	cin >> n >> c;
	record* records = new record[n];
	for (size_t i = 0; i < n; i++)
	{
		cin >> records[i].id >> records[i].name >> records[i].score;
	}
	if (1 == c)
	{
		sort(records, records + n, cmp_by_id_asc);
	}
	else if (2 == c)
	{
		sort(records, records + n, cmp_by_name_ndesc);
	}
	else if (3 == c)
	{
		sort(records, records + n, cmp_by_score_ndesc);
	}
	--n;
	for (size_t i = 0; i < n; i++)
	{
		printf("%06d %s %d\n", records[i].id, records[i].name.c_str(), records[i].score);
	}
	printf("%06d %s %d", records[n].id, records[n].name.c_str(), records[n].score);
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
