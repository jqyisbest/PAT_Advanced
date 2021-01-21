#include "resolve1022.h"

/**
	利用map快速查找
	注意输入的处理。
	多用scanf
*/
int resolve1022::resolve()
{
	//查询结果
	map<string, set<int>> book_title_search;
	map<string, set<int>> author_name_search;
	map<string, set<int>> key_word_search;
	map<string, set<int>> publisher_search;
	map<int, set<int>> published_year_search;
	int total_number_of_books = 0;
	scanf("%d\n", &total_number_of_books);
	//读取书籍信息
	for (int i = 0; i < total_number_of_books; ++i)
	{
		int id = 0, published_year = 0;
		string  title, author, key_word, key_word_str, publisher;
		scanf("%d\n", &id);
		getline(cin, title);
		getline(cin, author);
		do
		{
			cin >> key_word;
			key_word_search[key_word].insert(id);
			char c = getchar();
			if (c == '\n')
			{
				break;
			}
		} while (true);
		getline(cin, publisher);
		scanf("%d\n", &published_year);
		//存入map
		book_title_search[title].insert(id);
		author_name_search[author].insert(id);
		publisher_search[publisher].insert(id);
		published_year_search[published_year].insert(id);
	}
	int number_of_queries = 0;
	scanf("%d\n", &number_of_queries);
	int* type = new int[number_of_queries];
	string* key = new string[number_of_queries];
	for (int i = 0; i < number_of_queries; ++i)
	{
		scanf("%d: ", &type[i]);
		getline(cin, key[i]);
	}
	for (int i = 0; i < number_of_queries; ++i)
	{
		cout << type[i] << ": " << key[i] << "\n";
		switch (type[i]) {
		case 1: {
			print_set(&book_title_search[key[i]]);
			break;
		}
		case 2: {
			print_set(&author_name_search[key[i]]);
			break;
		}
		case 3: {
			print_set(&key_word_search[key[i]]);
			break;
		}
		case 4: {
			print_set(&publisher_search[key[i]]);
			break;
		}
		case 5: {
			print_set(&published_year_search[stoi(key[i])]);
			break;
		}
		default: {
			cout << "Not Found";
			break;
		}
		}
	}
	return 0;
}

void resolve1022::print_set(set<int>* result_ids)
{
	if (result_ids != nullptr&&result_ids->size()>0)
	{
		int j = 0;
		for (set<int>::iterator it = result_ids->begin(); it != result_ids->end(); it++)
		{
			printf("%07d\n", *it);
		}
	}
	else
	{
		cout << "Not Found" << endl;
	}
}
