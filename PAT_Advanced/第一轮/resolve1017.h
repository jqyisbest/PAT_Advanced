#include "common.h"
namespace resolve1017 {
	int resolve();
	int find_customer_waiting(int* processing_times,int current_index);
	/**
		找到可以服务的窗口编号
		找不到时返回-1
	*/
	int find_window_available(int* times_window_available,int number_of_windows);
}