// 旋轉矩陣

#include <stdio.h>
int main()
{
    int m, n;
    while (scanf("%d%d", &m, &n) != EOF)
    {
        int array1[m][n];
        int array2[n][m];
        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                scanf("%d", &array1[row][col]); // 輸入
            }
        }

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                printf("%d ", array1[col][row]); // 輸出
            }
            printf("\n");
        }
    }
    return 0;
}
