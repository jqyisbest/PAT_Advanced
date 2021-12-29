#include "common.h"
namespace resolve1014 {
	int resolve();
	typedef struct customer{
		//�����ʱ�����ӣ�
		int minutes_cost;
		//�����ڵĶ��к�
		int line_num;
		//�����˿Ϳ�ʼ�����ʱ�̣���8:00����
		int minutes_service_start;
		//�����˿Ͱ��ʱ��ʱ�̣���8:00����
		int minutes_service_finished;
	}customer;
	typedef struct service_line {
		//���е�ǰ�ɽ�����
		int capacity_available;
		//���������һλ�ͻ����������ʱ�̣���8:00����������541=(17-8)*60+1(����)����ö��н��޷���������
		int last_finish_minutes;
	}service_line;
	/**
		��8�����ƫ�Ʒ�����תΪʱ�䣨HH:MM������ʾ
		����540ֱ����ʾSorry
	*/
	string convert_to_time(int minutes);
	/**
		�ҵ�һ�����Խ���Ķ��к� �Ҳ�������-1
		��ǰ�ܼƷ����������<=540���������������
	*/
	int find_line(vector<service_line> service_lines);
}