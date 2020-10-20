/*
每行有一正整數T，代表有幾組測試資料

接下來有T行， 每行有N、M兩正整數

N為矩陣長寬，就是會有N*N矩陣

M為方向，M=1為順時鐘，M=2為逆時鐘

N範圍為1~100之間 

C用%5d輸出

*/
#include <stdio.h>
int direction(int angle, int M)
{
    if (M == 1)
        return (angle - 90 + 360) % 360;
    else
        return (angle + 90 + 360) % 360;
}
int movei(int angle);
int movej(int angle);

int main()
{
    int N, M;
    int T;
    scanf("%d", &T); // input T
    for (int i = 0; i < T; i++)
    {
        scanf("%d%d", &N, &M); // input N and M
        int array[N][N];
        int angle;
        int next_i, next_j;
        // clear the array
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                array[i][j] = 0;
            }
        }
        if (M == 1)
        {
            angle = 0;
        }
        else
        {
            angle = 270;
        }
        int i = 0, j = 0;
        for (int count = 1; count <= N * N; count++)
        {
            array[i][j] = count;
            next_i = i + movei(angle);
            next_j = j + movej(angle);
            if (array[next_i][next_j] != 0 || next_i >= N || next_j >= N || next_i < 0 || next_j < 0)
            {
                angle = direction(angle, M);
                next_i = i + movei(angle);
                next_j = j + movej(angle);
            }
            i = next_i;
            j = next_j;
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

int movej(int angle)
{
    switch (angle)
    {
    case 0:
        return 1;
    case 90:
        return 0;
    case 180:
        return -1;
    case 270:
        return 0;
    default:
        return 0;
        break;
    }
}

int movei(int angle)
{
    switch (angle)
    {
    case 0:
        return 0;
    case 90:
        return -1;
    case 180:
        return 0;
    case 270:
        return 1;
    default:
        return 0;
        break;
    }
}
