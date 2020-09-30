#include <stdio.h>
#include <math.h>
/*
a121: 質數又來囉

輸入兩個正整數a,b(1<=a<=b<=100000000)。

保證b-a<=1000 

輸出一個非負整數，代表a到b之間(包含a,b)總共有幾個質數。
測資:
3 7
6 6
30 50

3
0
5

 */
int main()
{
    int a, b, ans = 0;
    while (scanf("%d%d", &a, &b) != EOF)
    {
        if (a > b)
        {
            int temp = a;
            a = b;
            b = a;
        }
        ans = 0;
        for (int i = a; i <= b; i++)
        {
            if (b - a > 1000)
            {
                ans = 0;
                break;
            }
            int k = 0;

            for (int j = 1; j <= sqrt(i); j++)
            {

                if (i % j == 0)
                {
                    if (i == 1)
                    {
                        break;
                    }
                    k++;
                }
                if (k > 1)
                {
                    break;
                }
            }
            if (k == 1)
            {
                ans++;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
