#include "resolve1076.h"
/*
	��������ֻ��ת��һ��
    ���Ĳ������
    n�������ÿ���ڵ�ڼ�����ԴӸ��ڵ㿪ʼ�ݹ飬�ӽڵ����=���ڵ����+1��
*/
int resolve1076::resolve()
{
    int n = 0, l = 0, k = 0, user = 0;
    scanf("%d %d", &n, &l);
    vector<int> *followers = new vector<int>[n + 1];
    for (size_t i = 1; i <= n; ++i)
    {
        int num = 0;
        scanf("%d", &num);
        for (size_t j = 0; j < num; ++j)
        {
            scanf("%d", &user);
            followers[user].push_back(i);
        }
    }
    scanf("%d", &k);
    for (size_t i = 0; i < k; ++i)
    {
        int *levels = new int[n + 1];
        fill(levels, levels + n + 1, -1);
        int forward_times = 0;
        set<int> wait_forward_list;
        scanf("%d", &user);
        levels[user] = 0;
        get_new_forwarders(user, wait_forward_list, followers, levels, l);
        //���������ʼ
        while (wait_forward_list.size() != 0)
        {
            set<int>::iterator current_user = wait_forward_list.begin();
            //ת��
            ++forward_times;
            get_new_forwarders(*current_user, wait_forward_list, followers, levels, l);
            wait_forward_list.erase(current_user);
        }
        printf("%d\n", forward_times);
    }
    return 0;
}

void resolve1076::get_new_forwarders(int current_user, set<int> &wait_forward_list, vector<int> *followers, int *levels, const int level)
{
    vector<int> follower = followers[current_user];
    for (size_t i = 0; i < follower.size() && levels[current_user] < level; ++i)
    {
        if (levels[follower[i]] == -1)
        {
            levels[follower[i]] = levels[current_user] + 1;
            wait_forward_list.insert(follower[i]);
        }
    }
}