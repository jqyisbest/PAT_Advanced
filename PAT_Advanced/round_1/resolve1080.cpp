#include "resolve1080.h"
int resolve1080::resolve()
{
    int n = 0, m = 0, k = 0, rank = 0;
    scanf("%d %d %d", &n, &m, &k);
    //学校定额
    int *quota = new int[m];
    for (size_t i = 0; i < m; ++i)
    {
        scanf("%d", &quota[i]);
    }
    //学生列表
    vector<student *> stu_list;
    //排名列表
    vector<student *> *rank_list = new vector<student *>[n];
    //录取列表
    vector<int> *admit_list = new vector<int>[m];
    //录入分数和志愿
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
    //排名
    sort(stu_list.begin(), stu_list.end(), cmp_student);
    for (size_t i = 0; i < n; ++i)
    {
        if (0 != i && (stu_list[i]->total != stu_list[i - 1]->total || stu_list[i]->g_e != stu_list[i - 1]->g_e))
        {
            ++rank;
        }
        rank_list[rank].push_back(stu_list[i]);
    }
    //录取
    for (size_t i = 0; i <= rank; ++i)
    {
        //统计每轮每个学院用了几个名额
        int *used = new int[m];
        fill(used, used + m, 0);
        for (size_t j = 0; j < rank_list[i].size(); ++j)
        {
            vector<int> choice = rank_list[i][j]->choice;
            for (size_t k = 0; k < choice.size(); ++k)
            {
                //如有名额就录取。
                //因为剩余名额是在同名次学生录取完后更新，故满足同名学生同校一定录取的原则
                if (quota[choice[k]] > 0)
                {
                    used[choice[k]]++;
                    admit_list[choice[k]].push_back(rank_list[i][j]->id);
                    break;
                }
            }
        }
        //更新剩余名额
        for (size_t j = 0; j < m; ++j)
        {
            quota[j] -= used[j];
        }
        delete used;
    }
    //打印录取结果
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