#include "common.h"
namespace resolve1129 {
	int resolve();
	typedef struct goods {
		int index;
		int times;
		goods() {
			index = 0;
			times = 0;
		}
		bool operator < (const goods& g) const;
	}goods;
}