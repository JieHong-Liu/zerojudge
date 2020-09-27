#include <stdio.h>

int asc2int(char c)
{
    return c - 48;
}
int main()
{
    int city[] = {10, 11, 12, 13, 14, 15, 16, 17, 34, 18, 19, 20, 21, 22, 35, 23, 24, 25, 26, 27, 28, 29, 32, 30, 31, 33};

    char id[10]; // 要留一格存'\0'
    int city_number[26];
    while (scanf("%s", id) != EOF)
    {
        for (int i = 0; i < 26; i++)
        {
            int ten = city[i] / 10;
            int one = city[i] % 10;
            city_number[i] = ten + one * 9;
            printf("i here is %d , city[i] is %d, and city_number[i] is %d \n", i, city[i], city_number[i]);
        }
        int sum = 0;
        for (int i = 0; i <= 8; i++)
        {
            sum = sum + asc2int(id[i]) * (8 - i);
        }
        printf("sum is %d", sum);
    }

    return 0;
}