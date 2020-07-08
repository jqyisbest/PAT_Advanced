#include "resolve1075.h"
/*
	
*/
int resolve1075::resolve()
{
    int n = 0, k = 0, m = 0;
    scanf("%d %d %d", &n, &k, &m);
    int *p = new int[k + 1];
    for (size_t i = 1; i <= k; ++i)
    {
        scanf("%d", &p[i]);
    }
    vector<user *> users;
    for (size_t i = 0; i < n; ++i)
    {
        user *u = new user(i + 1);
        u->submission = new int[k + 1];
        fill(u->submission, u->submission + k + 1, -2);
        users.push_back(u);
    }
    for (size_t i = 0; i < m; ++i)
    {
        int user_id = 0, problem_id = 0, partial_score_obtained = 0;
        scanf("%d %d %d", &user_id, &problem_id, &partial_score_obtained);
        user *u = users[user_id - 1];
        if (!u->has_submit_success && partial_score_obtained != -1)
        {
            //提交成功！
            u->has_submit_success = true;
        }
        if (partial_score_obtained > u->submission[problem_id])
        {
            u->total_score = u->total_score - (u->submission[problem_id] < 0 ? 0 : u->submission[problem_id]) + (partial_score_obtained < 0 ? 0 : partial_score_obtained);
            u->submission[problem_id] = partial_score_obtained;
            if (partial_score_obtained == p[problem_id])
            {
                u->num_of_perfect++;
            }
        }
    }

    //排名 注意！不管是否能被输出，都参与排名
    sort(users.begin(), users.end(), cmp_user);
    for (size_t i = 1; i <= n; ++i)
    {
        users[i - 1]->rank = i;
        if (i != 1 && users[i - 1]->total_score == users[i - 2]->total_score)
        {
            users[i - 1]->rank = users[i - 2]->rank;
        }
    }

    //输出
    for (size_t i = 0; i < n; ++i)
    {
        print_user(users[i], k);
    }
    return 0;
}
bool resolve1075::cmp_user(user *u1, user *u2)
{
    return u1->total_score == u2->total_score ? u1->num_of_perfect == u2->num_of_perfect ? u1->id < u2->id : u1->num_of_perfect > u2->num_of_perfect : u1->total_score > u2->total_score;
}
void resolve1075::print_user(user *u, int k)
{
    if (u->has_submit_success)
    {
        printf("%d %05d %d", u->rank, u->id, u->total_score);
        for (size_t i = 1; i <= k; ++i)
        {
            printf(" ");
            if (u->submission[i] == -2)
            {
                printf("-");
            }
            else if (u->submission[i] == -1)
            {
                printf("0");
            }
            else
            {
                printf("%d", u->submission[i]);
            }
        }
        printf("\n");
    }
}