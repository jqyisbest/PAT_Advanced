#include "resolve1035.h"

int resolve1035::resolve()
{
	int account_num, modify_num = 0;
	scanf("%d", &account_num);
	vector<int>modify_index;
	vector<account_node>accounts;
	accounts.resize(account_num);
	for (size_t i = 0; i < account_num; ++i)
	{
		accounts[i].name = new char[11];
		accounts[i].password = new char[11];
		scanf("%s ", accounts[i].name);
		bool is_modify = false;
		int temp_index = 0;
		while (cin.get(accounts[i].password[temp_index]) && temp_index < 11)
		{
			if (accounts[i].password[temp_index] == '\n')
			{
				accounts[i].password[i == (account_num - 1) ? temp_index : temp_index + 1] = '\0';
				break;
			}
			else if (accounts[i].password[temp_index] == '1')
			{
				accounts[i].password[temp_index] = '@';
				is_modify = true;
			}
			else if (accounts[i].password[temp_index] == '0')
			{
				accounts[i].password[temp_index] = '%';
				is_modify = true;
			}
			else if (accounts[i].password[temp_index] == 'l')
			{
				accounts[i].password[temp_index] = 'L';
				is_modify = true;
			}
			else if (accounts[i].password[temp_index] == 'O')
			{
				accounts[i].password[temp_index] = 'o';
				is_modify = true;
			}
			temp_index++;
		}
		if (is_modify)
		{
			++modify_num;
			modify_index.push_back(i);
		}
	}
	if (modify_num == 0)
	{
		if (1 < account_num)
		{
			cout << "There are " << account_num << " accounts and no account is modified";
		}
		else
		{
			cout << "There is " << account_num << " account and no account is modified";
		}
	}
	else
	{
		cout << modify_num << endl;
		for (size_t i = 0; i < modify_num; ++i)
		{
			cout << accounts[modify_index[i]].name << " " << accounts[modify_index[i]].password;
		}
	}
	return 0;
}