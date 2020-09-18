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

問題
然而，羅馬數字還是經常用於書本章節及頁碼的編號。在這一題工作是讀入兩個正整數，然後輸出兩個數字差的絕對值。所有的數字都必須以羅馬數字來表示。而連續四個相同符號出現時，必須用減法規則來化簡之。

I still can't handle it QQ
*/
#include <stdio.h>

int romaToInt(char *);
int intToRoma(int);
int main()
{
    char hashtag;
    while (scanf("%c", &hashtag) != '#')
    {
        char first[80];  // 被減數
        char second[80]; // 減數
        // char roma[6][2] = {'IV', 'IX', 'XC', 'CM', 'CD', 'XL'};
        int same = 1;
        int numOfFirst = 0;
        int numOfSecond = 0;

        scanf("%s", first);
        scanf("%s", second);

        for (int i = 0; first[i] != '\0'; i++)
        {
            if (first[i] == 'M')
            {
                numOfFirst += 1000;
            }
        }

        return 0;
    }
}

int romaToInt(char first[80])
{
    i
}
