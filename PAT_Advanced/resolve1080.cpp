#include "resolve1080.h"
int resolve1080::resolve()
{
    int n = 0, m = 0, k = 0, rank = 0;
    scanf("%d %d %d", &n, &m, &k);
    //ѧУ����
    int *quota = new int[m];
    for (size_t i = 0; i < m; ++i)
    {
        scanf("%d", &quota[i]);
    }
    //ѧ���б�
    vector<student *> stu_list;
    //�����б�
    vector<student *> *rank_list = new vector<student *>[n];
    //¼ȡ�б�
    vector<int> *admit_list = new vector<int>[m];
    //¼�������־Ը
    for (size_t i = 0; i < n; ++i)
    {
        double g_e = 0.0, g_i = 0.0;
        scanf("%lf %lf", &g_e, &g_i);
        student *s = new student();
        s->id = i;
        s->g_e = g_e;
        s->total = (g_e + g_i) / 2.0;
        s->choice.resize(k);
        for (size_t j = 0; j < k; ++j)
        {
            scanf("%d", &s->choice[j]);
        }
        stu_list.push_back(s);
    }
    //����
    sort(stu_list.begin(), stu_list.end(), cmp_student);
    for (size_t i = 0; i < n; ++i)
    {
        if (0 != i && (stu_list[i]->total != stu_list[i - 1]->total || stu_list[i]->g_e != stu_list[i - 1]->g_e))
        {
            ++rank;
        }
        rank_list[rank].push_back(stu_list[i]);
    }
    //¼ȡ
    for (size_t i = 0; i <= rank; ++i)
    {
        //ͳ��ÿ��ÿ��ѧԺ���˼�������
        int *used = new int[m];
        fill(used, used + m, 0);
        for (size_t j = 0; j < rank_list[i].size(); ++j)
        {
            vector<int> choice = rank_list[i][j]->choice;
            for (size_t k = 0; k < choice.size(); ++k)
            {
                //���������¼ȡ��
                //��Ϊʣ����������ͬ����ѧ��¼ȡ�����£�������ͬ��ѧ��ͬУһ��¼ȡ��ԭ��
                if (quota[choice[k]] > 0)
                {
                    used[choice[k]]++;
                    admit_list[choice[k]].push_back(rank_list[i][j]->id);
                    break;
                }
            }
        }
        //����ʣ������
        for (size_t j = 0; j < m; ++j)
        {
            quota[j] -= used[j];
        }
        delete used;
    }
    //��ӡ¼ȡ���
    for (size_t i = 0; i < m; ++i)
    {
        sort(admit_list[i].begin(), admit_list[i].end());
        for (size_t j = 0; j < admit_list[i].size(); ++j)
        {
            if (0 != j)
            {
                printf(" ");
            }
            printf("%d", admit_list[i][j]);
        }
        printf("\n");
    }
    return 0;
}
bool resolve1080::cmp_student(student *s1, student *s2)
{
    return s1->total == s2->total ? s1->g_e == s2->g_e ? s1->id < s2->id : s1->g_e > s2->g_e : s1->total > s2->total;
}