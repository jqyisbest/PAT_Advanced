#include "common.h"
namespace resolve1057 {
	int resolve();
	/*
	二分法获取值在序列中的位置
	如果值不存在，则返回应插入位置的后一个iterator;
	如果值存在多个，则返回第一个匹配到的
	*/
	vector<int>::iterator get_it_with_order(vector<int>& keys, int value);
	void insert_with_order(vector<int>& keys, int value);
	void erase_with_order(vector<int>& keys, int value);
}