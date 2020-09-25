#include <stdio.h>
#include <string.h>
// 輸入任意數字，並將其數字全部倒轉

int main()
{
    char buf[500];

    while (scanf("%s", buf) != EOF)
    {
        // 把最後的0都刪掉
        while (buf[strlen(buf) - 1] == '0')
        {
            buf[strlen(buf) - 1] = '\0';
        }
        int length = strlen(buf);
        for (int i = length - 1; i >= 0; i--)
        {
            printf("%c", buf[i]);
        }
        if (length == 0)
        {
            printf("0");
        }
        printf("\n");
    }
    return 0;
}
