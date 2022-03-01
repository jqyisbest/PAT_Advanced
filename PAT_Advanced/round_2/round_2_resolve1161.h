#include <bits/stdc++.h>
using namespace std;
namespace round_2_resolve1161 {
	typedef struct node
	{
		int add, data, next;
		node(int add, int data, int next) {
			this->add = add;
			this->data = data;
			this->next = next;
		}
	}node;
	int resolve();
}