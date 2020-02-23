#include <iostream>
#include <math.h>
#include <string>
#include <algorithm> 
#include <list>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
namespace common {
	void print_array(int* a, int n);
	void print_array(int** a, int m, int n);
	void fill_array(int* a, int n, int val);
	void fill_array(int** a, int m, int n, int val);
	bool is_prime(long long n);
	/**
	    按字符升序排序的比较函数
	*/
	bool sort_by_alphabetical_asc(string a, string b);
	/**
	    按字符降序排序的比较函数
	*/
	bool sort_by_alphabetical_desc(string a, string b);
	int symbol_to_int(char digit);
	long long change_to_radix_ten(string digits, long long radix);
	string change_from_radix_ten(long long digits_in_radix_ten, long long target_radix);
	
}