#include "resolve1003.h"
#include "common.h"

namespace resolve1003 {

	const int INF = 99999999;

	void calculate(int n1, int n2, int nodeNum, int pathNum, int* node_weight, int** map, int* number_of_path, int* max_weight) {
		//定义访问数组，1为已访问
		int* visited = new int[nodeNum];
		//common::fill_array(visited, nodeNum, 0);
		//定义并初始化n1至其它各点的最短距离
		int* distance = new int[nodeNum] ;
		//common::fill_array(distance, nodeNum, -1);
		//定义并初始化n1至其它各点的最短距离的路径数
		int* num = new int[nodeNum] ;
		//common::fill_array(num, nodeNum, 0);
		num[n1] = 1;
		//定义并初始化n1至其它各点的最大权值
		int* weight = new int[nodeNum];
		//common::fill_array(weight, nodeNum, 0);
		weight[n1] = node_weight[n1];
		for (int i = 0; i < nodeNum; ++i)
		{
			distance[i] = map[n1][i];
		}
		/*cout << "\n数据初始化完毕，打印如下：\n";
		cout << "map:\n";
		common::print_array(map, nodeNum, nodeNum);
		cout << "distance：\n";
		common::print_array(distance, nodeNum);
		cout << "num：\n";
		common::print_array(num, nodeNum);
		cout << "weight:\n";
		common::print_array(weight, nodeNum);*/
	
		/*
			正向考虑：
				每轮选择图中离起点n1最近（distance最小）的一个未访问节点u，相当于是选择了一条访问路径，将u纳入已知最短路径集中，故需将u置为已访问。
				此刻，n1至u的距离为最短，基于此，更新n1至与u相邻的其它未访问节点（b\c\d...）的distance，可得到自起点n1经由u节点至b\c\d...的最短距离。
				下一轮，选择的便是另一条访问路径，最坏情况下，图中每一个点均为连通子图，i循环nodeNum轮。
		*/
		for (int i = 0; i < nodeNum; ++i)
		{
			int minn = 0;
			//本轮开始离n1最近的节点u
			int u = -1;
			for (int j = 0; j < nodeNum; ++j)
			{
				if (visited[j]==0&&distance[j]!= INF)
				{
					u = j;
					minn = distance[j];
					break;
				}
			}
			for (int j = 0; j < nodeNum; ++j)
			{
				if (visited[j] == 0 && distance[j] < minn)
				{
					u = j;
					minn = distance[j];
				}
			}
			//cout << "\n本轮选择节点：" << u << "\n";
			if (u==-1)
			{
				break;
			}
			visited[u] = 1;
			for (int v = 0; v < nodeNum; ++v)
			{
				int edge_length = map[u][v];
				if (visited[v]==0&& edge_length != INF)
				{
					//找到u未被访问的邻接点
					if (distance[u]+ edge_length<distance[v])
					{
						//当n1至u的距离加上uv的距离小于n1至v的距离时，从n1经由u至v为最近，则将n1至v的路径（不管以前是啥）更改为经由u至v。
						distance[v] = distance[u] + edge_length;
						//uv之间只有一条路径，故num[v]=num[u]
						num[v] = num[u];
						//更新最大救援队数量为：n1到u的最大救援队数量加上v本身的救援队数量
						weight[v] = weight[u] + node_weight[v];
					}
					else
					{
						//当n1至u的距离加上uv的距离等于n1至v的距离时，从n1经由u至v为一条新的最短路径。
						//则将n1至v的路径最短路径数num[v]更新为num[v]+num[u]。
						num[v] = num[u] + num[v];
						//比较新发现的n1->u->v路径和旧的n1->v路径所能得到的最大救援队数量，如果新的路径能得到更多的救援队，则更新最大救援队数量
						if (weight[u] + node_weight[v]>weight[v])
						{
							weight[v] = weight[u] + node_weight[v];
						}
					}
				}
			}
			/*cout<<"本轮更新后的dis,num,weight" << "\n";
			common::print_array(distance, nodeNum);
			common::print_array(num, nodeNum);
			common::print_array(weight, nodeNum);*/
		}
		/*cout << "\n计算完毕,打印dis,num,weight：\n";
		common::print_array(distance, nodeNum);
		common::print_array(num, nodeNum);
		common::print_array(weight, nodeNum);
		cout << "\n";*/
		*number_of_path = num[n2];
		*max_weight = weight[n2];
	}

	int resolve() {
		int N, M, c1, c2 = 0;
		//输入节点个数、路径个数、所在城市（从0开始）、目的城市（从0开始）
		cin >> N >> M >> c1 >> c2;
		//权值
		int* weight = new int[N];
		//邻接矩阵存储带权无向图
		int** map = new int*[N];
		//输入权值并顺便完成邻接矩阵的初始化
		for (int i = 0; i < N; ++i)
		{
			cin >> weight[i];
			map[i] = new int[N] ;
			for (int j = 0; j < N; ++j)
			{
				map[i][j] = INF;
			}
			map[i][i] = 0;
		}
		//输入带权无向图
		for (int i = 0; i < M; ++i)
		{
			int ii, jj, ww = 0;
			cin >> ii >> jj >> ww;
			map[ii][jj] = ww;
			map[jj][ii] = ww;
		}
		//定义结果:最短路径的数目、最大权值
		int number_of_path, max_weight = -1;
		//计算
		calculate(c1, c2, N, M, weight, map, &number_of_path, &max_weight);
		//按格式输出结果
		cout << number_of_path << " " << max_weight;
		return 0;
	}
}