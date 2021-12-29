#include "resolve1125.h"

int resolve1125::resolve()
{
	int n = 0;
	cin >> n;
	vector<int> nums(n);
	for (size_t i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());
	int result = nums[0];
	for (size_t i = 1; i < n; i++)
	{
		result = (result + nums[i]) / 2;
	}
	cout << result;
	return 0;
}