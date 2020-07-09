#include "resolve1077.h"
/*
	倒序找出最长相同字符串
    经验证，scanf和cin混用时可在scanf里直接读取掉当前行\n
    和cin.get()起到相同效果
*/
int resolve1077::resolve()
{
    int n = 0;
    scanf("%d\n", &n);
    string lines[100];
    for (size_t i = 0; i < n; ++i)
    {
        lines[i].resize(257);
        cin.getline(&lines[i][0], 257);
        lines[i] = lines[i].substr(0, strlen(lines[i].c_str()));
    }
    for (size_t i = 1; i < n; ++i)
    {
        int common_len = 0, lens_0 = lines[0].length(), lens_i = lines[i].length();
        for (size_t j = 1; j <= min(lens_0, lens_i) && lines[0][lens_0 - j] == lines[i][lens_i - j]; ++j)
        {
            ++common_len;
        }
        lines[0] = lines[0].substr(lens_0 - common_len);
    }
    printf("%s", lines[0].length() == 0 ? "nai" : lines[0].c_str());
    return 0;
}