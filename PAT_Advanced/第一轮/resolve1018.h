#include "common.h"
namespace resolve1018 {
	int resolve();
	typedef struct path {
		//ÕýÐò½Úµã±àºÅ
		vector<int> path_num;
		int num_of_send;
		int num_of_take_back;
	} shorest_path,path;
	void copy_path(path* source, path* target);
	bool cmp_shorest_path(shorest_path p1, shorest_path p2);
	string print_path(vector<int> path);
}