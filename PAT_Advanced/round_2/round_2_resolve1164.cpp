#include "round_2_resolve1164.h"
using namespace round_2_resolve1164;
#include <bits/stdc++.h>
using namespace std;
void round_2_resolve1164::print_word(vector<alpha*> word)
{
	//一个单词占7行
	for (size_t i = 0; i < 7; i++)
	{
		for (size_t j = 0; j < word.size(); j++)
		{
			alpha* a = word[j];
			cout << a->matrix[i];
			if (j < word.size() - 1)
			{
				cout << " ";
			}
		}
		if (i < 6)
		{
			cout << endl;
		}
	}
}
bool round_2_resolve1164::is_capital_letter(char c)
{
	return c >= 'A'&&c <= 'Z';
}
int round_2_resolve1164::resolve()
{
	map<char, alpha*>get_alpha;
	for (size_t i = 0; i < 26; i++)
	{
		alpha *a = new alpha();
		for (size_t j = 0; j < 7; j++)
		{
			cin >> a->matrix[j];
		}
		get_alpha['A' + i] = a;
	}
	string sentence;
	getchar();
	getline(cin, sentence);
	vector<vector<alpha*>> words;
	vector<alpha*> word;
	for (size_t i = 0; i < sentence.size(); i++)
	{
		if (is_capital_letter(sentence[i]))
		{
			word.push_back(get_alpha[sentence[i]]);
		}
		else
		{
			if (word.size() > 0)
			{
				words.push_back(word);
			}
			word.clear();
		}
	}
	if (word.size() > 0)
	{
		words.push_back(word);
	}
	for (size_t i = 0; i < words.size(); i++)
	{
		if (i != 0)
		{
			cout << endl << endl;
		}
		print_word(words[i]);
	}
	return 0;
}