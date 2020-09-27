#include <stdio.h>

int asc2int(char c)
{
    return c - 48;
}
int main()
{
    int city[] = {10, 11, 12, 13, 14, 15, 16, 17, 34, 18, 19, 20, 21, 22, 35, 23, 24, 25, 26, 27, 28, 29, 32, 30, 31, 33};

    char id[10]; // 要留一格存'\0'
    while (scanf("%s", id) != EOF)
    {
        int check = asc2int(id[8]); // 存檢查碼
        // printf("check number is %d\n", check);
        int city_number[26];
        for (int i = 0; i < 26; i++)
        {
            int ten = city[i] / 10;
            int one = city[i] % 10;
            city_number[i] = ten + one * 9;
        }

        int sum = 0;

        for (int i = 0; i <= 8; i++)
        {
            sum = sum + asc2int(id[i]) * (8 - i);
        }
        for (int i = 0; i < 26; i++)
        {
            int check_num = (sum + city_number[i]) % 10;

            if ((check + check_num) % 10 == 0)
            {
                printf("%c", 65 + i);
            }
        }
        printf("\n");
    }

    return 0;
}