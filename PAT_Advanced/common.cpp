#include "common.h"
namespace common {
	void print_array(int* a, int n) {
		for (int i = 0; i < n - 1; ++i)
		{
			cout << a[i] << ",";
		}
		cout << a[n - 1] << "\n";
	}

	void print_array(int** a, int m, int n) {
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n - 1; ++j)
			{
				cout << a[i][j] << ",";
			}
			cout << a[i][n - 1] << "\n";
		}
	}
	void fill_array(int* a, int n,int val) {
		for (int i = 0; i < n; ++i)
		{
			a[i] = val;
		}
	}
	void fill_array(int** a, int m, int n, int val) {
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				a[i][j] = val;
			}
		}
	}
	
}