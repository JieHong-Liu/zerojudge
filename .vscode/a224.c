#include <stdio.h>
#include <string.h>

/*
輸入
一筆測試資料一行，包含許許多多但總數不超過 1000 個的大小寫英文字母和標點符號。
不可思議的是，裡面不會有任何空白字元。
輸出
如果重新安排順序後，有辦法讓這一堆英文字母變成迴文的話，輸出「yes !」，否則輸出「no...」。
注意，大寫和小寫字母視為相同，即 A 和 a 是一樣的，並且，請忽視所有非英文字母的字元。


*/

int main()
{
    char buf[1000];
    while (scanf("%s", buf) != EOF)
    {
        int wrong = 0;
        char english[26] = {};
        for (int i = 0; i < strlen(buf); i++)
        {
            if (buf[i] >= 65 && buf[i] <= 90)
            {
                int change = (buf[i] - 65);
                english[change]++;
            }
            else if (buf[i] >= 97 && buf[i] <= 122)
            {
                int change = (buf[i] - 97);
                english[change]++;
            }
        }
        for (int i = 0; i < 26; i++) // 判斷英文字母
        {
            if (english[i] % 2 != 0)
            {
                wrong++;
            }
            if (wrong > 1)
            {
                break;
            }
        }

        if (wrong > 1)
        {
            printf("no...\n");
        }
        else if (wrong <= 1)
        {
            printf("yes !\n");
        }
    }
    return 0;
}
