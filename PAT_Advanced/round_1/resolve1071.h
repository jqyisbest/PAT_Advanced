#include "common.h"
namespace resolve1071 {
	int resolve();
    typedef struct word_node
    {
        string content;
        long times;
    }word_node;
    bool is_alphanumerical(char& c);
    bool cmp_word(word_node* n1,word_node* n2);
}