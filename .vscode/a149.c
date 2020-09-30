#include <stdio.h>
#include <string.h>
//你拿到一個整數，卻忍不住想把每個位數都乘在一起。例如看到 356 就會想要知道 3 * 5 * 6 的值為何。快寫個程式幫幫為了乘數字而快發瘋的自己吧！

int asc2int(char c)
{
    return c - 48;
}

int main()
{
    int T;
    unsigned int product = 1;
    while (scanf("%d", &T) != EOF)
    {
        char num[80];
        for (int i = 0; i < T; i++)
        {
            product = 1;
            scanf("%s", num);
            for (int j = 0; j < strlen(num); j++)
            {
                product *= asc2int(num[j]);
            }
            printf("%u\n", product);
        }
    }
    return 0;
}
