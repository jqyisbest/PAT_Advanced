#include "resolve1019.h"
/**
	����ȡ�෨
	ע�ⲻ����string��װ������ڴ����ʱ��һЩ��λ�޷����ַ���ʾ�಻���ж��Ƿ������ȣ������ 2��4���Ե������
*/
int resolve1019::resolve()
{
	long num = 0, base = 0;
	cin >> num >> base;
	if (0 == num)
	{
		cout << "Yes" << endl;
		cout << "0";
	}
	else {
		vector<long> ans ;
		//ʹ��do{}while�����Է�ֹ����Ϊ0�����
		do {
			long t = num%base;
			ans.push_back(t);
			num /= base;
		} while (num != 0);
		size_t i = 0;
		bool is_palindromic = true;
		while (is_palindromic&&i<(ans.size()/2))
		{
			if (ans[i]!= ans[ans.size()-i-1])
			{
				is_palindromic = false;
			}
			else {
				++i;
			}
		}
		cout << (is_palindromic?"Yes":"No") << endl;
		for (size_t i = ans.size()-1; i >0; --i)
		{
			cout << ans[i] << " ";
		}
		cout << ans[0];
	}
	return 0;
}
