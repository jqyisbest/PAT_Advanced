#include "common.h"
namespace resolve1056 {
	int resolve();
	typedef struct player_node {
		int id;
		int weight;
		int rank;
	}player;
	bool cmp_player_weight(player* p1, player* p2);
}