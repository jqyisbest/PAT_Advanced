#include "round_2_resolve1006.h"
using namespace round_2_resolve1006;
#include <bits/stdc++.h>
using namespace std;
int round_2_resolve1006::resolve()
{
	int m = 0, has_found = 0, total_seconds = 24 * 3600 + 1;
	scanf("%d", &m);
	char **sign_in = new char*[total_seconds], **sign_out = new char*[total_seconds];
	fill(sign_in, sign_in + total_seconds, nullptr);
	fill(sign_out, sign_out + total_seconds, nullptr);
	for (size_t i = 0; i < m; i++)
	{
		char *stu_name = new char[16];
		int in_h = 0, in_m = 0, in_s = 0, in_time = 0;
		int out_h = 0, out_m = 0, out_s = 0, out_time = 0;
		scanf("%s %d:%d:%d %d:%d:%d", stu_name, &in_h, &in_m, &in_s, &out_h, &out_m, &out_s);
		in_time = in_h * 3600 + in_m * 60 + in_s;
		out_time = out_h * 3600 + out_m * 60 + out_s;
		sign_in[in_time] = stu_name;
		sign_out[out_time] = stu_name;
	}

	for (size_t i = 0; i < total_seconds&&has_found == 0; i++)
	{
		if (sign_in[i] != nullptr)
		{
			printf("%s", sign_in[i]);
			has_found++;
		}

	}
	for (int i = total_seconds - 1; i >= 0 && has_found == 1; i--)
	{
		if (sign_out[i] != nullptr)
		{
			printf(" %s", sign_out[i]);
			has_found++;
		}
	}
	return 0;
}