#include <stdio.h>

/*

明明喜歡把數字排成一列－－用他自己的方式！
他首先先看個位數，把個位數由小到大排。接著，如果個位數字一樣的話，他會將這些數字，由大至小排。
例如，如果數字有 38 106 98 26 13 46 51 的話，那麼 51 會排最前面，因為個位數字 1 是其中最小的一個。
而 106 26 46 這三個數字，個位數同樣都是 6，所以明明會直接將他們由大至小排，也就是 106 46 26。
所以，排好之後是：51 13 106 46 26 98 38，請你幫他輸出最終結果吧！

*/
int main()
{
    int number;
    while (scanf("%d", &number) != EOF)
    {
        int array[number];
        for (int k = 0; k < number; k++)
        {
            scanf("%d", &array[k]);
        }
        for (int i = 0; i < number; i++)
        {
            for (int j = i; j < number; j++)
            {
                if (array[i] % 10 > array[j] % 10)
                {
                    int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
                if (array[i] % 10 == array[j] % 10)
                {
                    if (array[i] < array[j])
                    {
                        int temp = array[i];
                        array[i] = array[j];
                        array[j] = temp;
                    }
                }
            }
        }
        for (int i = 0; i < number; i++)
        {
            printf("%d ", array[i]);
        }
        printf("\n");
    }
    return 0;
}
