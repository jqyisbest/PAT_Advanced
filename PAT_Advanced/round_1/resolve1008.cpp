#include "resolve1008.h"
#include "resolve1008.h"
#include "common.h"
int resolve1008::resolve()
{
	//�������������ǰ��������¥�㡢���ݼ���ǰ����¥��
	int current_floor = 0, next_floor = 0;
	long num_of_request = 0;
	cin >> num_of_request;
	//�ܼ�ʱ�� =�ܼ�ͣ��ʱ��+�ܼ��˶�ʱ��
	long times_all = num_of_request * 5;
	for (int i = 0; i < num_of_request; ++i)
	{
		cin >> next_floor;
		if (next_floor>current_floor)
		{
			//����
			times_all += 6 * (next_floor - current_floor);
		}
		else if (next_floor<current_floor)
		{
			//����
			times_all += 4 * (current_floor-next_floor);
		}
		current_floor = next_floor;
	}
	cout << times_all;
	return 0;
}
