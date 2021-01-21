#include "resolve1008.h"
#include "resolve1008.h"
#include "common.h"
int resolve1008::resolve()
{
	//总请求次数、当前电梯所在楼层、电梯即将前往的楼层
	int current_floor = 0, next_floor = 0;
	long num_of_request = 0;
	cin >> num_of_request;
	//总计时长 =总计停留时长+总计运动时长
	long times_all = num_of_request * 5;
	for (int i = 0; i < num_of_request; ++i)
	{
		cin >> next_floor;
		if (next_floor>current_floor)
		{
			//向上
			times_all += 6 * (next_floor - current_floor);
		}
		else if (next_floor<current_floor)
		{
			//向下
			times_all += 4 * (current_floor-next_floor);
		}
		current_floor = next_floor;
	}
	cout << times_all;
	return 0;
}
