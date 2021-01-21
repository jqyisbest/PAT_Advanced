#include"common.h"
namespace resolve1154
{
	int resolve();
	typedef struct edge
	{
		int node_1, node_2;
		edge(int node_1, int node_2) {
			this->node_1 = node_1;
			this->node_2 = node_2;
		}
	}edge;
}