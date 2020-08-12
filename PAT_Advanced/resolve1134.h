#include "common.h"
namespace resolve1134 {
	int resolve();
	typedef struct edge {
		int n1, n2;
		edge() {
			this->n1 = 0;
			this->n2 = 0;

		}
		edge(int n1, int n2) {
			this->n1 = n1;
			this->n2 = n2;
		}
		bool operator < (const edge& e)const;
	}edge;
}