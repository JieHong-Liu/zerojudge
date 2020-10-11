/*

多筆輸入。
第一行有四個介於0-9之間的數字，代表正確的密碼
第二行有一個整數n，1<=n<=10000，代表接下來嘗試n組密碼
接下來有n行，每行有四個介於0-9之間的數字，每行各代表一組嘗試的密碼。


輸出n行。
對於每組嘗試的密碼，若有p個數字的值正確，且在正確的位子上，
另外有q個數字的值正確，但不在正確的位子上，
輸出pAqB。
範例見測資。

*/

#include <stdio.h>

int main()
{
    int password[4];
    int test[4];
    int temp[4]; // 不要讓B去存到A的數字
    int quiz;
    while (scanf("%d%d%d%d", &password[0], &password[1], &password[2], &password[3]) != EOF)
    {
        for (int i = 0; i < 4; i++)
        {
            temp[i] = password[i];
        }

        scanf("%d", &quiz); // 代表有幾組要嘗試的密碼
        for (int i = 0; i < quiz; i++)
        {
            int A = 0, B = 0;

            for (int i = 0; i < 4; i++)
            {
                scanf("%d", &test[i]); // 這次猜的密碼
            }

            for (int i = 0; i < 4; i++)
            {
                // 先判斷A再判斷B
                if (password[i] == test[i])
                {
                    A++;
                    test[i] = -1; // 存一個永遠不會對的變數
                    password[i] = -10;
                }
            }
            for (int i = 0; i < 4; i++) // 判斷B的時候要用雙層loop
            {
                for (int j = 0; j < 4; j++)
                {
                    if (password[i] == test[j])
                    {
                        B++;
                        test[j] = -1; // 比過的就不要比了好嗎= =
                        password[i] = -10;
                        break;
                    }
                }
            }
            printf("%dA%dB\n", A, B);
            for (int i = 0; i < 4; i++)
            {
                password[i] = temp[i]; // 將答案賦歸
            }
        }
    }
    return 0;
}
