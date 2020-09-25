#include <stdio.h>
int main()
{
    int t = 0;
    int integer[100][100] = {0};
    int d = 0;
    int time = 0;

    scanf("%d", &t);
    if (0 <= t && t <= 20)
    {
        for (int i = 0; i < t; i++)
        {
            for (int x = 0; x < 4; x++)
            {
                scanf("%d", &integer[i][x]);
            }

            if ((integer[i][1] - integer[i][0]) == (integer[i][3] - integer[i][2]))
            {
                d = integer[i][1] - integer[i][0];
                integer[i][4] = integer[i][3] + d;
                for (int y = 0; y < 5; y++)
                {
                    printf("%d ", integer[i][y]);
                }
                printf("\n");
            }
            if ((integer[i][1] / integer[i][0]) == (integer[i][2] / integer[i][1]))
            {
                time = integer[i][1] / integer[i][0];
                integer[i][4] = integer[i][3] * time;
                for (int y = 0; y < 5; y++)
                {
                    printf("%d ", integer[i][y]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
