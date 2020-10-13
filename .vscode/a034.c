#include <stdio.h>
// 二進位轉換
// 針對每一行的整數輸出其二進位制的結果

int main()
{
    int number;
    while (scanf("%d", &number) != EOF)
    {
        int ans[100] = {};
        int finished = 0;
        if (number == 1 || number == 0)
        {
            finished = 1;
            printf("%d\n", number);
        }
        while (number >= 2)
        {
            int j;
            for (j = 0; number >= 2; j++)
            {
                ans[j] = number % 2;
                number /= 2;
            }
            ans[j] = number;
        }
        int array_size;
        for (int i = 99; i >= 0; i--)
        {
            if (ans[i] != 0)
            {
                array_size = i + 1;
                break;
            }
        }
        if (!finished)
        {

            for (int i = array_size - 1; i >= 0; i--)
            {
                printf("%d", ans[i]);
            }
            printf("\n");
        }
    }

    return 0;
}
