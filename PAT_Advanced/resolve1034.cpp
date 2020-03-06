#include "resolve1034.h"

/*
	������һ��ͼ
	ÿ���˶���һ���ڵ�
	һ��relation����һ����
	�ڵ��Ȩֵ�����ڽӱߵ�Ȩֵ
	Ȼ���������� �ҳ�ÿ����ϵ����ͼ��ͳ����Ȩֵ�͹�ϵ����Ȩֵ���ĵ�

	����� ���Ե�3 OJ������ 

	���������1000ͨ����¼�������2000�ˣ����relation_weights ���鿪2000˵�δ��󣬿�С�ˡ�
	0
	����ȷ
	17 ms	16140 KB
	1
	����ȷ
	17 ms	16000 KB
	2
	����ȷ
	18 ms	16000 KB
	3
	�δ���
	25 ms	16712 KB
	4
	����ȷ
	26 ms	16384 KB
	5
	����ȷ
	26 ms	16256 KB

	relation_weights�ĳ�3000 ��Ȼ���������ʱ���󡣡���
	0
	����ȷ
	33 ms	35584 KB
	1
	����ȷ
	34 ms	35584 KB
	2
	����ȷ
	25 ms	35792 KB
	3
	����ʱ����
	71 ms	36096 KB
	4
	����ȷ
	44 ms	35812 KB
	5
	����ȷ
	32 ms	35900 KB

	relation_weights�ĳ�4000 �պ��ܹ� �������ڴ�������
	0
	����ȷ
	51 ms	62988 KB
	1
	����ȷ
	39 ms	63068 KB
	2
	����ȷ
	40 ms	63024 KB
	3
	����ȷ
	65 ms	63436 KB
	4
	����ȷ
	72 ms	63232 KB
	5
	����ȷ
	73 ms	63232 KB
*/
int resolve1034::resolve()
{
	int number_of_phone_calls, weight_threthold, person_num = 0;
	scanf("%d %d", &number_of_phone_calls, &weight_threthold);
	//���� ��Ȩ��
	map<string, long> person_weight;
	//���� ����
	map<int, string>index_person;
	//���� ���� 
	map<string, int >person_index;
	vector<vector<long>> relation_weights;
	//���1000��ͨ����¼�漰2000����
	relation_weights.resize(4000);
	for (size_t i = 0; i < 4000; ++i)
	{
		//�����Ǵ洢
		relation_weights[i].resize(4000 - i);
	}
	for (size_t i = 0; i < number_of_phone_calls; ++i)
	{
		string name_1, name_2;
		int time, person_index_1, person_index_2 = 0;
		cin >> name_1 >> name_2 >> time;
		if (person_weight.count(name_1) == 0)
		{
			person_index[name_1] = person_num;
			index_person[person_num++] = name_1;
			person_weight[name_1] = 0;
			fill(relation_weights[person_num - 1].begin(), relation_weights[person_num - 1].end(), 0);
		}
		if (person_weight.count(name_2) == 0)
		{
			person_index[name_2] = person_num;
			index_person[person_num++] = name_2;
			person_weight[name_2] = 0;
			fill(relation_weights[person_num - 1].begin(), relation_weights[person_num - 1].end(), 0);
		}
		if (person_index[name_1] < person_index[name_2])
		{
			person_index_1 = person_index[name_1];
			person_index_2 = person_index[name_2];
		}
		else
		{
			person_index_1 = person_index[name_2];
			person_index_2 = person_index[name_1];
		}
		relation_weights[person_index_1][person_index_2] += time;
		person_weight[name_1] += time;
		person_weight[name_2] += time;
	}
	if (person_num < 3)
	{
		//���������������İ���
		cout << "0";
	}
	else {
		//��������relation_weights �ӵ�һ�п�ʼ�ҳ�����weight_threthold�ļ�¼����
		//��¼ÿ�����Ƿ��жϹ�
		bool* visited = new bool[person_num];
		fill(visited, visited + person_num, false);
		//��ͳ��ÿ����ϵ������Ȩ��ʱ�����ж��Ƿ����ۼƹ�
		bool* weight_added = new bool[person_num];
		//��������������
		map<string, int> gangs;
		list<int> person_index_list;
		for (int i = 0; i < person_num; ++i)
		{
			//�µĹ�ϵ����
			int person_index_start = -1;
			for (int j = 0; j < person_num; ++j)
			{
				if (!visited[j])
				{
					person_index_start = j;
					break;
				}
			}
			if (person_index_start == -1)
			{
				break;
			}
			int gang_num = 0;
			string gang_head;
			long total_weight = 0;
			fill(weight_added, weight_added + person_num, false);
			person_index_list.push_back(person_index_start);
			while (person_index_list.size() != 0)
			{
				int person_index_current_visit = *person_index_list.begin();
				person_index_list.pop_front();
				if (!visited[person_index_current_visit])
				{
					visited[person_index_current_visit] = true;
					++gang_num;
				}
				if (gang_head.size() == 0||person_weight[gang_head]<person_weight[index_person[person_index_current_visit]])
				{
					//�ҳ���ǰ��ϵ������Ȩ�������Ǹ���
					gang_head = index_person[person_index_current_visit];
				}
				for (int j = 0; j < person_index_current_visit; ++j)
				{
					if (relation_weights[j][person_index_current_visit] > 0)
					{
						if (!visited[j])
						{
							//�¹�ϵ��
							visited[j] = true;
							++gang_num;
							person_index_list.push_back(j);
						}
						if (!weight_added[j])
						{
							total_weight += relation_weights[j][person_index_current_visit];
						}
					}
				}
				for (int j = person_index_current_visit + 1; j < person_num; ++j)
				{
					if (relation_weights[person_index_current_visit][j] > 0)
					{
						if (!visited[j])
						{
							//�¹�ϵ��
							visited[j] = true;
							++gang_num;
							person_index_list.push_back(j);
						}
						if (!weight_added[j])
						{
							total_weight += relation_weights[person_index_current_visit][j];
						}
					}
				}
				weight_added[person_index_current_visit] = true;
			}
			if (gang_num>2&&total_weight>weight_threthold)
			{
				//�ж���ϵ���Ƿ�Ϊ���ɣ���Ա����������������Ȩ�ش��ڽ綨ֵ
				gangs[gang_head] = gang_num;
			}
		}
		cout << gangs.size();
		if (gangs.size()>0)
		{
			cout << endl;
			int print_count = 1;
			for (map<string, int>::iterator gang = gangs.begin(); gang != gangs.end(); ++gang)
			{
				cout << gang->first << " " << gang->second;
				if (print_count != gangs.size())
				{
					++print_count;
					cout << endl;
				}
			}
		}
	}
	return 0;
}