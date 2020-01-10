#include "resolve1003.h"
#include "common.h"

namespace resolve1003 {

	const int INF = 99999999;

	void calculate(int n1, int n2, int nodeNum, int pathNum, int* node_weight, int** map, int* number_of_path, int* max_weight) {
		//����������飬1Ϊ�ѷ���
		int* visited = new int[nodeNum];
		//common::fill_array(visited, nodeNum, 0);
		//���岢��ʼ��n1�������������̾���
		int* distance = new int[nodeNum] ;
		//common::fill_array(distance, nodeNum, -1);
		//���岢��ʼ��n1�������������̾����·����
		int* num = new int[nodeNum] ;
		//common::fill_array(num, nodeNum, 0);
		num[n1] = 1;
		//���岢��ʼ��n1��������������Ȩֵ
		int* weight = new int[nodeNum];
		//common::fill_array(weight, nodeNum, 0);
		weight[n1] = node_weight[n1];
		for (int i = 0; i < nodeNum; ++i)
		{
			distance[i] = map[n1][i];
		}
		/*cout << "\n���ݳ�ʼ����ϣ���ӡ���£�\n";
		cout << "map:\n";
		common::print_array(map, nodeNum, nodeNum);
		cout << "distance��\n";
		common::print_array(distance, nodeNum);
		cout << "num��\n";
		common::print_array(num, nodeNum);
		cout << "weight:\n";
		common::print_array(weight, nodeNum);*/
	
		/*
			�����ǣ�
				ÿ��ѡ��ͼ�������n1�����distance��С����һ��δ���ʽڵ�u���൱����ѡ����һ������·������u������֪���·�����У����轫u��Ϊ�ѷ��ʡ�
				�˿̣�n1��u�ľ���Ϊ��̣����ڴˣ�����n1����u���ڵ�����δ���ʽڵ㣨b\c\d...����distance���ɵõ������n1����u�ڵ���b\c\d...����̾��롣
				��һ�֣�ѡ��ı�����һ������·���������£�ͼ��ÿһ�����Ϊ��ͨ��ͼ��iѭ��nodeNum�֡�
		*/
		for (int i = 0; i < nodeNum; ++i)
		{
			int minn = 0;
			//���ֿ�ʼ��n1����Ľڵ�u
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
			//cout << "\n����ѡ��ڵ㣺" << u << "\n";
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
					//�ҵ�uδ�����ʵ��ڽӵ�
					if (distance[u]+ edge_length<distance[v])
					{
						//��n1��u�ľ������uv�ľ���С��n1��v�ľ���ʱ����n1����u��vΪ�������n1��v��·����������ǰ��ɶ������Ϊ����u��v��
						distance[v] = distance[u] + edge_length;
						//uv֮��ֻ��һ��·������num[v]=num[u]
						num[v] = num[u];
						//��������Ԯ������Ϊ��n1��u������Ԯ����������v����ľ�Ԯ������
						weight[v] = weight[u] + node_weight[v];
					}
					else
					{
						//��n1��u�ľ������uv�ľ������n1��v�ľ���ʱ����n1����u��vΪһ���µ����·����
						//��n1��v��·�����·����num[v]����Ϊnum[v]+num[u]��
						num[v] = num[u] + num[v];
						//�Ƚ��·��ֵ�n1->u->v·���;ɵ�n1->v·�����ܵõ�������Ԯ������������µ�·���ܵõ�����ľ�Ԯ�ӣ����������Ԯ������
						if (weight[u] + node_weight[v]>weight[v])
						{
							weight[v] = weight[u] + node_weight[v];
						}
					}
				}
			}
			/*cout<<"���ָ��º��dis,num,weight" << "\n";
			common::print_array(distance, nodeNum);
			common::print_array(num, nodeNum);
			common::print_array(weight, nodeNum);*/
		}
		/*cout << "\n�������,��ӡdis,num,weight��\n";
		common::print_array(distance, nodeNum);
		common::print_array(num, nodeNum);
		common::print_array(weight, nodeNum);
		cout << "\n";*/
		*number_of_path = num[n2];
		*max_weight = weight[n2];
	}

	int resolve() {
		int N, M, c1, c2 = 0;
		//����ڵ������·�����������ڳ��У���0��ʼ����Ŀ�ĳ��У���0��ʼ��
		cin >> N >> M >> c1 >> c2;
		//Ȩֵ
		int* weight = new int[N];
		//�ڽӾ���洢��Ȩ����ͼ
		int** map = new int*[N];
		//����Ȩֵ��˳������ڽӾ���ĳ�ʼ��
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
		//�����Ȩ����ͼ
		for (int i = 0; i < M; ++i)
		{
			int ii, jj, ww = 0;
			cin >> ii >> jj >> ww;
			map[ii][jj] = ww;
			map[jj][ii] = ww;
		}
		//������:���·������Ŀ�����Ȩֵ
		int number_of_path, max_weight = -1;
		//����
		calculate(c1, c2, N, M, weight, map, &number_of_path, &max_weight);
		//����ʽ������
		cout << number_of_path << " " << max_weight;
		return 0;
	}
}