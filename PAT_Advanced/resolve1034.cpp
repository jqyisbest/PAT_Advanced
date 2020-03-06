#include "resolve1034.h"

/*
	构建起一张图
	每个人都是一个节点
	一对relation就是一条边
	节点的权值就是邻接边的权值
	然后类层序遍历 找出每个关系网子图、统计总权值和关系网中权值最大的点

	这题的 测试点3 OJ很神奇 

	按题意最多1000通话记录，那最多2000人，结果relation_weights 数组开2000说段错误，开小了。
	0
	答案正确
	17 ms	16140 KB
	1
	答案正确
	17 ms	16000 KB
	2
	答案正确
	18 ms	16000 KB
	3
	段错误
	25 ms	16712 KB
	4
	答案正确
	26 ms	16384 KB
	5
	答案正确
	26 ms	16256 KB

	relation_weights改成3000 居然变成了运行时错误。。？
	0
	答案正确
	33 ms	35584 KB
	1
	答案正确
	34 ms	35584 KB
	2
	答案正确
	25 ms	35792 KB
	3
	运行时错误
	71 ms	36096 KB
	4
	答案正确
	44 ms	35812 KB
	5
	答案正确
	32 ms	35900 KB

	relation_weights改成4000 刚好能过 几乎把内存用满了
	0
	答案正确
	51 ms	62988 KB
	1
	答案正确
	39 ms	63068 KB
	2
	答案正确
	40 ms	63024 KB
	3
	答案正确
	65 ms	63436 KB
	4
	答案正确
	72 ms	63232 KB
	5
	答案正确
	73 ms	63232 KB
*/
int resolve1034::resolve()
{
	int number_of_phone_calls, weight_threthold, person_num = 0;
	scanf("%d %d", &number_of_phone_calls, &weight_threthold);
	//名字 总权重
	map<string, long> person_weight;
	//索引 名字
	map<int, string>index_person;
	//名字 索引 
	map<string, int >person_index;
	vector<vector<long>> relation_weights;
	//最多1000条通话记录涉及2000个人
	relation_weights.resize(4000);
	for (size_t i = 0; i < 4000; ++i)
	{
		//上三角存储
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
		//少于三个人哪来的帮派
		cout << "0";
	}
	else {
		//类层序遍历relation_weights 从第一行开始找出大于weight_threthold的记录下来
		//记录每个人是否被判断过
		bool* visited = new bool[person_num];
		fill(visited, visited + person_num, false);
		//在统计每个关系网的总权重时用于判断是否已累计过
		bool* weight_added = new bool[person_num];
		//帮主、帮派人数
		map<string, int> gangs;
		list<int> person_index_list;
		for (int i = 0; i < person_num; ++i)
		{
			//新的关系网！
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
					//找出当前关系网中总权重最大的那个人
					gang_head = index_person[person_index_current_visit];
				}
				for (int j = 0; j < person_index_current_visit; ++j)
				{
					if (relation_weights[j][person_index_current_visit] > 0)
					{
						if (!visited[j])
						{
							//新关系！
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
							//新关系！
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
				//判定关系网是否为帮派：成员人数大于两人且总权重大于界定值
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