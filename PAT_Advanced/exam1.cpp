//#include<bits/stdc++.h>
//using namespace std;
//bool is_prime(int a) {
//	if (a == 1)
//	{
//		return false;
//	}
//	for (int i = 2; i <= sqrt(a); ++i)
//	{
//		if (a%i == 0)
//		{
//			return false;
//		}
//	}
//	return true;
//}
//int main() {
//	bool all_prime = true;
//	string date;
//	date.resize(8);
//	scanf("%s", &date[0]);
//	for (int i = 0; i < 8; ++i)
//	{
//		string temp = date.substr(i);
//		printf("%s ", temp.c_str());
//		if (is_prime(stoi(temp)))
//		{
//			printf("Yes\n");
//		}
//		else
//		{
//			all_prime = false;
//			printf("No\n");
//		}
//	}
//	if (all_prime)
//	{
//		printf("All Prime!");
//	}
//	//system("pause");
//	return 0;
//}