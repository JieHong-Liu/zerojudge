/*
每行有一正整數T，代表有幾組測試資料

接下來有T行， 每行有N、M兩正整數

N為矩陣長寬，就是會有N*N矩陣

M為方向，M=1為順時鐘，M=2為逆時鐘

N範圍為1~100之間 


把矩陣輸出，矩陣值之間寬度為5，就是[00000]寬度

C++可用setw(5)或C的%5d輸出

*/
#include <stdio.h>
void direction(int angle, int M)
{
    if (M == 1)
        angle = (angle + 270) % 360;
    else if (M == 2)
        angle = (angle + 90) % 360;
}

int main()
{
    int N, M;
    int T;
    scanf("%d", &T); // input T
    for (int i = 0; i < T; i++)
    {
        scanf("%d%d", &N, &M); // input N and M
        int array[N][N];
        // clear the array
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                array[i][j] = 0;
            }
        }
        int angle;
        if (M == 1) // M = 1為順時鐘
        {
            angle = 0;
        }
        else if (M == 2)
        {
            angle = 270;
        }
        int i = 0, j = 0;
        for (int count = 1; count <= N * N; count++)
        {
            if (array[i][j] != 0)
            {
                direction(angle, M);
            }
            else
            {
                array[i][j] = count;
                switch (angle)
                {
                case 0:
                    j++;
                    break;
                case 90:
                    i--;
                    break;
                case 180:
                    j--;
                    break;
                case 270:
                    i++;
                    break;
                }
            }
        }
        // print array
        for (int k = 0; k < N; k++)
        {
            for (int l = 0; l < N; l++)
            {
                printf("%5d", array[k][l]);
            }
            printf("\n");
        }
    }

    return 0;
}
