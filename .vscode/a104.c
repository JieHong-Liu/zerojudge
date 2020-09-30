#include <stdio.h>
/*
有多筆測資以EOF為結束

第一行有一個正整數n(1<=n<=1000)，代表有幾個數字要請你幫忙排

第二行有n個可以用int儲存的正整數

測資:
6
7 9 0 4 1 8
8
1 9 9 0 0 9 2 8

0 1 4 7 8 9
0 0 1 2 8 9 9 9
*/

int main()
{
    int number;
    while (scanf("%d", &number) != EOF)
    {
        int sort_array[number];
        for (int i = 0; i < number; i++)
        {
            scanf("%d", &sort_array[i]);
        }
        for (int i = 0; i < number; i++)
        {
            for (int j = i; j < number; j++)
            {
                if (sort_array[i] > sort_array[j])
                {
                    int temp = sort_array[i];
                    sort_array[i] = sort_array[j];
                    sort_array[j] = temp;
                }
            }
        }
        for (int k = 0; k < number; k++)
        {
            printf("%d ", sort_array[k]);
        }
        printf("\n");
    }
    return 0;
}
