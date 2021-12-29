#include "resolve1097.h"

int resolve1097::resolve()
{
	string start_add;
	start_add.resize(5);
	int node_num = 0;
	bool keys[100000];
	fill(keys, keys + 100000, false);
	scanf("%s %d", &start_add[0], &node_num);
	map<string, node *>nodes;
	for (int i = 0; i < node_num; i++) {
		string add, next;
		add.resize(6);
		next.resize(6);
		int key = 0;
		scanf("%s %d %s", &add[0], &key, &next[0]);
		add = add.substr(0, strlen(add.c_str()));
		next = next.substr(0, strlen(next.c_str()));
		node *n = new node();
		n->add = add;
		n->key = key;
		n->next = next;
		nodes[add] = n;
	}
	node *current_node = nodes[start_add], *original_node_start = nullptr, *original_now = nullptr, *redundant_node_start = nullptr, *redundant_node_now = nullptr;
	while (current_node != nullptr) {
		if (keys[abs(current_node->key)]) {
			if (redundant_node_start == nullptr) {
				redundant_node_start = redundant_node_now = current_node;
				if (current_node->next == "-1") {
					current_node = nullptr;
				}
				else {
					current_node = nodes[current_node->next];
				}
			}
			else {
				redundant_node_now->next = current_node->add;
				redundant_node_now = current_node;
				if (current_node->next == "-1") {
					current_node = nullptr;
				}
				else {
					current_node = nodes[current_node->next];
				}
				redundant_node_now->next = "-1";
			}
		}
		else {
			keys[abs(current_node->key)] = true;
			if (original_node_start == nullptr) {
				original_node_start = original_now = current_node;
				if (current_node->next == "-1") {
					current_node = nullptr;
				}
				else {
					current_node = nodes[current_node->next];
				}
			}
			else {
				original_now->next = current_node->add;
				original_now = current_node;
				if (current_node->next == "-1") {
					current_node = nullptr;
				}
				else {
					current_node = nodes[current_node->next];
				}
				original_now->next = "-1";
			}
		}
	}
	original_now = original_node_start;
	while (original_now != nullptr) {
		if (original_now != original_node_start) {
			printf("%s\n", original_now->add.c_str());
		}
		if (original_now->next == "-1") {
			printf("%s %d -1\n", original_now->add.c_str(), original_now->key);
			original_now = nullptr;
		}
		else {
			printf("%s %d ", original_now->add.c_str(), original_now->key);
			original_now = nodes[original_now->next];
		}
	}
	redundant_node_now = redundant_node_start;
	while (redundant_node_now != nullptr) {
		if (redundant_node_now != redundant_node_start) {
			printf("%s\n", redundant_node_now->add.c_str());
		}
		if (redundant_node_now->next == "-1") {
			printf("%s %d -1\n", redundant_node_now->add.c_str(), redundant_node_now->key);
			redundant_node_now = nullptr;
		}
		else {
			printf("%s %d ", redundant_node_now->add.c_str(), redundant_node_now->key);
			redundant_node_now = nodes[redundant_node_now->next];
		}
	}
	return 0;
}
