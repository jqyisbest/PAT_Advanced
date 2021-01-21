#include "resolve1042.h"
/*
	OAC
	0
	答案正确
	4 ms	356 KB
	1
	答案正确
	4 ms	404 KB
	2
	答案正确
	3 ms	424 KB
	3
	答案正确
	4 ms	384 KB
	4
	答案正确
	3 ms	384 KB
*/
int resolve1042::resolve()
{
	const string* cards = new string[55]{ "*",
		"S1","S2","S3" ,"S4" ,"S5" ,"S6" ,"S7" ,"S8","S9" ,"S10" ,"S11" ,"S12" ,"S13" ,
		"H1","H2","H3" ,"H4" ,"H5" ,"H6" ,"H7" ,"H8","H9" ,"H10" ,"H11" ,"H12" ,"H13" ,
		"C1","C2","C3" ,"C4" ,"C5" ,"C6" ,"C7" ,"C8","C9" ,"C10" ,"C11" ,"C12" ,"C13" ,
		"D1","D2","D3" ,"D4" ,"D5" ,"D6" ,"D7" ,"D8","D9" ,"D10" ,"D11" ,"D12" ,"D13" ,
		"J1","J2" };
	int* card_index = new int[55];
	for (size_t i = 0; i < 55; i++)
	{
		card_index[i] = i;
	}
	vector<int> order;
	order.resize(55);
	int times = 0;
	scanf("%d", &times);
	for (size_t i = 1; i < 55; ++i)
	{
		scanf("%d", &order[i]);
	}
	for (size_t i = 0; i < times; i++)
	{
		shuffle(card_index, order);
	}
	for (size_t i = 1; i < 54; i++)
	{
		cout << cards[card_index[i]] << " ";
	}
	cout << cards[card_index[54]];
	return 0;
}

void resolve1042::shuffle(int * original, vector<int>& order)
{
	int* original_copy = new int[order.size()];
	memcpy(original_copy, original, order.size() * sizeof(int));
	for (int i = 1; i < order.size(); i++)
	{
		original[order[i]] = original_copy[i];
	}
	free(original_copy);
}