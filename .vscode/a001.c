#include <stdio.h>
int main()
{
    char buf[80];
    scanf("%s", buf);
    printf("hello, %s\n", buf);
    return 0;
}
// 編譯方法 gcc -o hello hello.c
