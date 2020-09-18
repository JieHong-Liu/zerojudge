#include <stdio.h>
int asc2int(char c)
{
    c = c - 48;
    return c;
}
int main()
{
    int city[] = {10, 11, 12, 13, 14, 15, 16, 17, 34, 18, 19, 20, 21, 22, 35, 23, 24, 25, 26, 27, 28, 29, 32, 30, 31, 33};
    char id[10];
    int sum = 0;
    scanf("%s", id);

    // 因為id[0]是英文字母，而英文字母A要等於10，而A的ASCII=65(decimal)，因此要先剪掉65，才能得到索引值0
    id[0] -= 65;

    int ten = city[id[0]] / 10; //十位數
    int one = city[id[0]] % 10; //個位數

    sum = one * 9 + ten;

    for (int i = 8; i > 0; i--)
    {
        sum += asc2int(id[9 - i]) * i;
    }
    sum += asc2int(id[9]);

    if (sum % 10 == 0)
    {
        printf("real\n");
    }
    else
    {
        printf("fake\n");
    }

    return 0;
}
