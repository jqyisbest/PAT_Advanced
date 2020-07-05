#include "resolve1071.h"
/*
	用map存储每一个词的引用
    用vector存储每一个词，用于排序
*/
int resolve1071::resolve()
{
    char c = ' ';
    string word = "";
    map<string, word_node *> words_cite;
    vector<word_node *> words;
    do
    {
        scanf("%c", &c);
        if (is_alphanumerical(c))
        {
            word.push_back(c);
        }
        else if ("" != word)
        {
            if (words_cite.count(word) == 0)
            {
                word_node *node = new word_node();
                node->content = word;
                node->times = 1;
                words_cite[word] = node;
                words.push_back(node);
            }
            else
            {
                words_cite[word]->times++;
            }
            word = "";
        }
    } while (c != '\n');
    sort(words.begin(), words.end(), cmp_word);
    printf("%s %ld", words[0]->content.c_str(), words[0]->times);
    return 0;
}

bool resolve1071::is_alphanumerical(char &c)
{
    if (c >= 'A' && c <= 'Z')
    {
        //大写转小写
        c = c + 32;
        return true;
    }
    else
    {
        return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z');
    }
}

bool resolve1071::cmp_word(word_node *n1, word_node *n2)
{
    return n1->times == n2->times ? n1->content < n2->content : n1->times > n2->times;
}