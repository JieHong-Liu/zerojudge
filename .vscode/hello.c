#include <stdio.h>
#include <string.h>
int main(void)
{
    char str[20];

    puts("請輸入字串：");
    gets(str);
    for (int i = 0; i < strlen(str); i += 2)
    {
        printf("%c", str[i]);
    }
    return 0;
}
