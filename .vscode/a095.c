#include <stdio.h>
// 輸入兩數N，M （1 <= M <= N < 2^31）

// 代表N個犯人，M頂紅帽
int main()
{
    int prisonor, redHat;
    while (scanf("%d%d", &prisonor, &redHat) != EOF)
    {
        int days = 0;
        if (prisonor == redHat)
        {
            days = redHat;
            printf("%d\n", days);
        }
        else
        {
            days = redHat + 1;
            printf("%d\n", days);
        }
    }
    return 0;
}
