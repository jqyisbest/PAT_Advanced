#include "common.h"
namespace resolve1075 {
	int resolve();
    typedef struct user
    {
        bool has_submit_success;
        int* submission;
        int id;
        int rank;
        int total_score;
        int num_of_perfect;
        user(int id)
        {
            this->id=id;
            this->has_submit_success=false;
            this->rank=0;
            this->total_score=0;
            this->num_of_perfect=0;
        }
    }user;
    bool cmp_user(user *u1,user *u2);
    void print_user(user *u,int k);
}