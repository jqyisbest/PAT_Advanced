#include "resolve1006.h"
#include "common.h"
int resolve1006::resolve()
{
	//ѧ���15λ��INFΪ16λ
	const string INF = "****************";
	//һ��֮�ڵļ�¼�������ô����,��������һ��
	const int MAX_SECONDS = 24 * 60 * 60+1;
	int num_of_records = 0;
	cin >> num_of_records;
	string* sign_in = new string[MAX_SECONDS];
	string* sign_out = new string[MAX_SECONDS];
	fill(sign_in, sign_in + MAX_SECONDS, INF);
	fill(sign_out, sign_out + MAX_SECONDS, INF);
	//����������������������
	for (int i = 0; i < num_of_records; ++i)
	{
		int second = 0;
		int HH=0, MM=0, SS = 0;
		//��������
		string id_number,in_time,out_time;
		cin >> id_number>>in_time>>out_time;
		int first_colon_index = 0;
		int last_colon_index = 0;
		//����ǩ��ʱ�䣬ת��Ϊ��
		first_colon_index = in_time.find_first_of(":");
		last_colon_index = in_time.find_last_of(":");
		HH = stoi(in_time.substr(0, first_colon_index));
		MM = stoi(in_time.substr(first_colon_index+1, last_colon_index - first_colon_index));
		SS= stoi(in_time.substr(last_colon_index+1));
		second = HH * 3600 + MM * 60 + SS;
		sign_in[second] = id_number;
		//����ǩ��ʱ�䣬ת��Ϊ��
		first_colon_index = out_time.find_first_of(":");
		last_colon_index = out_time.find_last_of(":");
		HH = stoi(out_time.substr(0, first_colon_index));
		MM = stoi(out_time.substr(first_colon_index+1, last_colon_index - first_colon_index));
		SS = stoi(out_time.substr(last_colon_index+1));
		second = HH * 3600 + MM * 60 + SS;
		sign_out[second] = id_number;
	}
	//���ŵľ���sign_in�е�һ����ΪINF�ģ�ͬ��ɵù��ŵ�
	bool has_find_unlock = false;
	bool has_find_lock = false;
	int unlock_index = -1, lock_index = MAX_SECONDS;
	for (;(!(has_find_unlock&&has_find_lock))&&(unlock_index < MAX_SECONDS|| lock_index >=0);)
	{
		if ((!has_find_unlock)&&sign_in[++unlock_index] != INF)
		{
			has_find_unlock = true;
		}
		if ((!has_find_lock)&&sign_out[--lock_index] != INF)
		{
			has_find_lock = true;
		}
	}
	cout<< sign_in[unlock_index] << " "<< sign_out[lock_index];
	return 0;
}
