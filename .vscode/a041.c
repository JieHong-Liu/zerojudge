#include <stdio.h>
#include <math.h>
/*----------------------------------------------------------------
所謂 Armstrong number 指的是一個 n 位數的整數，它的所有位數的 n 次方和恰好等於自己。

如；1634 = 14 + 64 + 34+ 44 

請依題目需求在一定範圍內找出該範圍內的所有 armstrong numbers.
*/
int main()
{
    int start, end;
    while (scanf("%d%d", &start, &end) != EOF)
    {
        int any = 0;
        for (int i = start; i <= end; i++)
        {
            int digit_count = 1;
            int copy_start = i;
            int armstrong = 0;
            while (copy_start >= 10)
            {
                digit_count++;
                copy_start /= 10;
            }
            for (int j = 0; j < digit_count; j++)
            {
                int temp = pow(10, j);
                armstrong += pow(((i / temp) % 10), digit_count);
            }
            if (armstrong == i)
            {
                printf("%d ", armstrong);
                any = 1;
            }
        }
        if (any == 0)
        {
            printf("none\n");
        }
        else
        {
            printf("\n");
        }
    }
    return 0;
}
