#include "common.h"
namespace resolve1139 {
	int resolve();
	typedef struct node {
		int id_1, id_2;
		node(int id_1, int id_2) {
			this->id_1 = id_1;
			this->id_2 = id_2;
		}
	}node;
	bool cmp_node(node &n_1, node &n_2);
}