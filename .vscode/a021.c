// 大數運算
// 我們都知道電腦擅長於各種數字的計算，可是，我們又知道各種程式語言的變數又都有上限，比如整數只有216 或 232 個。如果要計算更大的數字時又該如何計算呢? 就交給聰明的您來解決囉。

// 以 + 代表加法
// 以 - 代表減法
// 以 * 代表乘法
// 以 / 代表除法 (取商數)

#include <stdio.h>
#include <string.h>
int asc2int(char c)
{
    // remember to shown as char
    c -= 48;
    return c;
}

void solvearrays(char *a, char *b)

{
    int a_size = strlen(a);
    int b_size = strlen(b);
    int difference = a_size - b_size; // 代表相差幾位數，相差幾位數就要讓比較小的那個陣列往後幾格，前面記得補0
    if (difference > 0)
    {
        printf("difference = %d\n", difference);
        for (int i = 0; i < b_size; i++)
        {
            b[b_size - i - 1 + difference] = b[b_size - i - 1]; // b_size - i - 1 代表b的最後一個位元的index
        }
        for (int i = 0; i < difference; i++)
        {
            b[i] = '0';
        }
        // for (int i = 0; i < b_size + difference; i++)
        // {
        //     printf("%c", b[i]);
        // }
        printf("\n");
    }
    else if (difference < 0)
    {
        printf("difference = %d\n", difference);
        difference = difference * -1;
        // 要跑differernce + 1 次
        for (int i = 0; i < a_size; i++)
        {
            a[a_size - i - 1 + difference] = a[a_size - i - 1]; // a_size - i - 1 代表a的最後一個位元的index
        }
        for (int i = 0; i < difference; i++)
        {
            a[i] = '0';
        }
        // for (int i = 0; i < a_size + difference; i++)
        // {
        //     printf("%c", a[i]);
        // }
        printf("\n");
    }
}
void add(char *a, char *b, char *ans)
{
    if (strlen(a) >= strlen(b))
    {

        for (int i = (strlen(a) - 1); i >= 0; i--)
        {
            ans[i] = asc2int(a[i]) + asc2int(b[i]);
        }
    }
    else if (strlen(a) < strlen(b))
    {
        for (int i = (strlen(a) - 1); i >= 0; i--)
        {
            ans[i] = asc2int(a[i]) + asc2int(b[i]);
        }
    }

    for (int i = strlen(ans) - 1; i >= 0; i--)
    {
        if (ans[i] >= 10 && i != 0)
        {
            ans[i - 1] = ans[i - 1] + (ans[i] / 10);
            ans[i] = ans[i] % 10;
        }
        printf("%d .", ans[i]);
    }
    printf("\n");
    if (ans[0] >= 10)
    {
        for (int i = (strlen(ans) - 1); i >= 0; i--)
        {
            a[i + 1] = a[i];
        }
    }
    for (int i = 0; i < strlen(ans); i++)
    {
        printf("%d", ans[i]);
    }
}

int main()
{
    char a[500] = {0}; // A
    char b[500] = {0}; // B
    char ans[500] = {0};
    char operator;
    while (scanf("%s %c %s", a, &operator, b) != EOF)
    {
        int a_size = strlen(a);
        int b_size = strlen(b);
        int difference = a_size - b_size; // 代表相差幾位數，相差幾位數就要讓比較小的那個陣列往後幾格，前面記得補0
        solvearrays(a, b);
        add(a, b, ans);

        // for (int i = (strlen(a) - 1); i >= 0; i--)
        // {
        //     printf("The a[i] before change is %d, The b[i] before change is %d \n", a[i], b[i]);

        //     if (operator== '+')
        //     {
        //         ans[i] = a[i] + b[i];
        //         printf("Here is plus\n");
        //         printf("The a[i] here is %d, The b[i] here is %d \n", a[i], b[i]);
        //         printf("The i here is %d, The ans[i] here is %c \n", i, asc2int(ans[i]));
        //     }
        //     else if (operator== '-')
        //     {
        //         a[i] -= b[i];
        //         printf("Here is minus\n");
        //     }

        //     if (a[i] >= 10 && i != 0)
        //     {
        //         a[i - 1] += a[i] / 10;
        //         a[i] = a[i] % 10;
        //     }
        // }
        // 如果a[0]>10 每一位都要往後放一位
        // if (a[0] >= 10)
        // {
        //     for (int i = 498; i >= 0; i--)
        //     {
        //         a[i + 1] = a[i];
        //     }
        // }
    }
    return 0;
}
