#include "common.h"
namespace resolve1028 {
	int resolve();
	typedef struct record_node {
		int id;
		string name;
		int score;
	}record;
	bool cmp_by_id_asc(record& r1, record& r2);
	bool cmp_by_name_ndesc(record& r1, record& r2);
	bool cmp_by_score_ndesc(record& r1, record& r2);
}