#include<bits/stdc++.h>
using namespace std;
typedef struct node {
	int data;
	node *left, *right;
	node(int data) {
		this->data = data;
		this->left = nullptr;
		this->right = nullptr;
	}
}node;
void in_order(node *n, vector<int>&res)
{
	if (n != nullptr)
	{
		in_order(n->left, res);
		res.push_back(n->data);
		in_order(n->right, res);
	}
}
int main()
{
	int n = 0;
	cin >> n;
	vector<int> data;
	data.resize(n);
	for (size_t i = 0; i < n; i++)
	{
		cin >> data[i];
	}
	map<int, node *>nodes;
	for (size_t i = 0; i < n; i++)
	{
		if (data[i] != -1)
		{
			node *p = new node(data[i]);
			nodes[i] = p;
		}
	}
	for (size_t i = 0; i < n; i++)
	{
		if (data[i] != -1)
		{
			node *p = nodes[i];
			int l_i = 2 * i + 1, r_i = 2 * i + 2;
			if (l_i < n&&data[l_i] != -1)
			{
				p->left = nodes[l_i];
			}
			if (r_i < n&&data[r_i] != -1)
			{
				p->right = nodes[r_i];
			}
		}
	}
	vector<int> res;
	in_order(nodes[0], res);
	bool flag = true;
	for (size_t i = 0; i < res.size(); i++)
	{
		if (i != 0 && res[i] < res[i - 1])
		{
			flag = false;
			break;
		}
	}
	cout << (flag ? "YES" : "NO") << endl;
	for (size_t i = 0; i < res.size(); i++)
	{
		if (i != 0)
		{
			cout << " ";
		}
		cout << res[i];
	}
	system("pause");
	return 0;
}