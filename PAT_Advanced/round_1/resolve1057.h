#include "common.h"
namespace resolve1057 {
	int resolve();
	/*
	���ַ���ȡֵ�������е�λ��
	���ֵ�����ڣ��򷵻�Ӧ����λ�õĺ�һ��iterator;
	���ֵ���ڶ�����򷵻ص�һ��ƥ�䵽��
	*/
	vector<int>::iterator get_it_with_order(vector<int>& keys, int value);
	void insert_with_order(vector<int>& keys, int value);
	void erase_with_order(vector<int>& keys, int value);
}