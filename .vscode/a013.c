/*
以下是七個基本的羅馬數字︰

 

羅馬數字	數目
I	1
V	5
X	10
L	50
C	100
D	500
M	1,000

IX,IV,XL,XC,CM,CD
問題
然而，羅馬數字還是經常用於書本章節及頁碼的編號。在這一題工作是讀入兩個正整數，然後輸出兩個數字差的絕對值。所有的數字都必須以羅馬數字來表示。而連續四個相同符號出現時，必須用減法規則來化簡之。

I still can't handle it QQ
*/
#include <stdio.h>
#include <string.h>
int romaToInt(char *first)
{
    int numOfFirst = 0;

    for (int i = 0; first[i] != '\0'; i++)
    {
        if (first[i] == 'M')
        {
            numOfFirst += 1000;
        }
        else if (first[i] == 'D')
        {
            numOfFirst += 500;
        }
        else if (first[i] == 'C')
        {
            if (first[i + 1] == 'D')
            {
                numOfFirst += 400;
                i += 1;
            }
            else if (first[i + 1] == 'M')
            {
                numOfFirst += 900;
                i += 1;
            }
            else
            {
                numOfFirst += 100;
            }
        }
        else if (first[i] == 'L')
        {
            numOfFirst += 50;
        }
        else if (first[i] == 'X')
        {
            if (first[i + 1] == 'L')
            {
                numOfFirst += 40;
                i += 1;
            }
            else if (first[i + 1] == 'C')
            {
                numOfFirst += 90;
                i += 1;
            }
            else
            {
                numOfFirst += 10;
            }
        }
        else if (first[i] == 'V')
        {
            numOfFirst += 5;
        }
        else if (first[i] == 'I')
        {
            if (first[i + 1] == 'X')
            {
                numOfFirst += 9;
                i += 1;
            }
            else if (first[i + 1] == 'V')
            {
                numOfFirst += 4;
                i += 1;
            }
            else
            {
                numOfFirst += 1;
            }
        }
    }
    return numOfFirst;
}
void intToRoma(int ans)
{
    int thousands = ans / 1000;
    ans %= 1000;
    while (thousands > 0)
    {
        printf("M");
        thousands--;
    }
    int ninehunds = ans / 900;
    ans %= 900;
    while (ninehunds > 0)
    {
        printf("CM");
        ninehunds--;
    }

    int fivehunds = ans / 500;
    ans %= 500;
    while (fivehunds > 0)
    {
        printf("D");
        fivehunds--;
    }
    int fourhunds = ans / 400;
    ans %= 400;
    while (fourhunds > 0)
    {
        printf("CD");
        fourhunds--;
    }
    int onehunds = ans / 100;
    ans %= 100;
    while (onehunds > 0)
    {
        printf("C");
        onehunds--;
    }
    int ninety = ans / 90;
    ans %= 90;
    while (ninety > 0)
    {
        printf("XC");
        ninety--;
    }
    int fifity = ans / 50;
    ans %= 50;
    while (fifity > 0)
    {
        printf("L");
        fifity--;
    }
    int fourty = ans / 40;
    ans %= 40;
    while (fourty > 0)
    {
        printf("XL");
        fourty--;
    }
    int ten = ans / 10;
    ans %= 10;
    while (ten > 0)
    {
        printf("X");
        ten--;
    }
    int nine = ans / 9;
    ans %= 9;
    while (nine > 0)
    {
        printf("IX");
        nine--;
    }
    int five = ans / 5;
    ans %= 5;
    while (five > 0)
    {
        printf("V");
        five--;
    }
    int four = ans / 4;
    ans %= 4;
    while (four > 0)
    {
        printf("IV");
        four--;
    }
    int one = ans / 1;
    while (one > 0)
    {
        printf("I");
        one--;
    }
}
int main()
{
    char first[20];  // 被減數
    char second[20]; // 減數
    while (scanf("%s", first) && first[0] != '#')
    {
        scanf("%s", second);
        int same = 1;
        int ans = 0;
        if (romaToInt(first) == romaToInt(second))
        {
            printf("ZERO");
        }
        else
        {
            ans = romaToInt(first) - romaToInt(second);
            if (ans < 0)
            {
                ans = ans * -1;
            }
            intToRoma(ans);
        }
        printf("\n");
    }
    return 0;
}
