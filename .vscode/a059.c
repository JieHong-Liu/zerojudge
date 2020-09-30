#include <stdio.h>

// a059 : 完全平方和
// 給你一個範圍 a 到 b ，請你找出 a 與 b 之間所有完全平方數的和。

// 例如：範圍[3, 25] 中所有完全平方數的和就是 4 + 9 + 16 + 25 = 54 。

int main()
{
    int T = 0;
    scanf("%d", &T); // 代表有幾組測資
    for (int i = 0; i < T; i++)
    {
        int first, final;
        int sum = 0;
        scanf("%d%d", &first, &final);
        for (int j = first; j <= final; j++)
        {
            for (int k = 0; k <= final; k++)
            {
                if (k * k == j)
                {
                    sum += j;
                }
            }
        }
        printf("Case %d: %d\n", i + 1, sum);
    }

    return 0;
}
