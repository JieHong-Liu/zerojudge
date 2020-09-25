#include <stdio.h>
#include <string.h>
// 迴文判斷
// 迴文的定義為正向，反向讀到的字串均相同

// 如：abba , abcba ... 等就是迴文

//  請判斷一個字串是否是一個迴文？
int main()
{
    char buf[1000];
    int yes = 1;

    while (scanf("%s", buf) != EOF)
    {
        char a[1000]; // 從前面看過去
        char b[1000]; // 從後面看回來
        int length = strlen(buf);
        yes = 0;
        int half = length / 2;
        if (length == 1)
        {
            yes = 1;
        }
        for (int i = 0; i < half; i++)
        {
            a[i] = buf[i];
        }
        for (int i = 0; i < half; i++)
        {
            int b_pointer = length - 1;
            b_pointer = b_pointer - i;
            b[i] = buf[b_pointer];
        }

        for (int i = 0; i < half; i++)
        {
            if (a[i] == b[i])
            {
                yes = 1;
            }
            if (a[i] != b[i])
            {
                yes = 0;
                break;
            }
        }

        if (yes == 1)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }

        // for (int i = 0; i < length; i++)
        // {
        //     printf("%c", buf[i]);
        // }
    }
    return 0;
}