/*
各位在國小時都學過因數分解，都瞭解怎麼樣用紙筆計算出結果，現在由你來敎電腦做因數分解。

因數分解就是把一個數字，切分為數個質數的乘積，如 12=2^2 * 3

其中, 次方的符號以 ^ 來表示
*/
#include <stdio.h>
int main()
{
    int number;
    scanf("%d", &number);
    for (int i = 2; i <= number; i++)
    {
        int times = 0;
        while (number % i == 0)
        {
            number /= i;
            times++;
        }
        if (times != 1 && times != 0)
        {
            printf("%d^%d", i, times);
            if (number != 1)
            {
                printf(" * ");
            }
        }
        else if (times == 1)
        {
            printf("%d", i);
            if (number != 1)
            {
                printf(" * ");
            }
        }
    }
    printf("\n");
    return 0;
}
