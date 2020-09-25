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

        printf("\n");
    }
}
void add(char *a, char *b, char *ans)
{

    for (int i = (strlen(a) - 1); i >= 0; i--) // size is the same, so it doesn't matter who is bigger.
    {
        ans[i] = asc2int(a[i]) + asc2int(b[i]);
    }

    int ans_size = strlen(a);

    for (int i = ans_size - 1; i >= 0; i--)
    {
        if (ans[i] >= 10 && i != 0)
        {
            ans[i - 1] = ans[i - 1] + (ans[i] / 10);
            ans[i] = ans[i] % 10;
        }
    }

    for (int i = 0; i < ans_size; i++)
    {
        printf("%d", ans[i]);
    }
}

void bignum_Reverse(char *a) /*倒轉儲存大數*/
{
    int len, i, temp;
    for (i = 0; i < 500; i++)
    {
        if (a[i] == '\0')
            break;
        a[i] = a[i] - '0';
    }
    len = i;
    a[len] = 0;
    for (i = 0; i < len; i++)
    {
        if (i >= len / 2)
            break;
        temp = a[i];
        a[i] = a[len - 1 - i];
        a[len - 1 - i] = temp;
    }
}
// a 如果比 b 小，傳回0
int bigger(char *a, char *b)
{
    int a_size, b_size;
    for (int i = 499; i > 0; i++)
    {
        if (a[i] != 0)
        {
            break;
        }
        a_size = i;
    }
    for (int i = 499; i > 0; i++)
    {
        if (b[i] != 0)
        {
            break;
        }
        b_size = i;
    }
    if (a_size > b_size)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void substract(char *a, char *b, char *ans)
{
    int borrow = 0;

    for (int i = 0; i < strlen(ans); i++)
    {
        printf("%d ", ans[i]);
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
        switch (operator)
        {
        case '+':
            solvearrays(a, b);
            add(a, b, ans);
            break;
        case '-':
            substract(a, b, ans);
            break;
        default:
            break;
        }
    }
    return 0;
}
