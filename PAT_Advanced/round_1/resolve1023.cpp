#include "resolve1023.h"
/**
	�Ƚ�doubleǰ��0-9�ĸ�����������һ�£�����ΪYes

	������string����int*���棬ֱ��longlong ���� unsigned  longlong���ǲ�����

	����������һ����˽ӽ����������
*/
int resolve1023::resolve()
{
	string original_num, double_num;
	cin >> original_num;
	//0-9��λ��
	int* num_of_digits = new int[10];
	fill(num_of_digits, num_of_digits + 10, 0);
	//��λ���
	bool flag = false;
	for (int i = original_num.length()-1; i >=0 ; --i)
	{
		int digit = original_num[i] - 48;
		++num_of_digits[digit];
		digit *= 2;
		int digit_result = flag ? (digit % 10 + 1) : (digit % 10);
		double_num.insert(0,1,digit_result + 48);
		--num_of_digits[digit_result];
		flag = digit > 9;
	}
	string result = "Yes";
	for (size_t i = 0; i < 10; ++i)
	{
		if (flag||num_of_digits[i] != 0)
		{
			result = "No";
			break;
		}
	}
	cout << result<<endl;
	//���������һλ���Ľ�λ==
	flag ? cout << '1' << double_num : cout << double_num;
	return 0;
}
