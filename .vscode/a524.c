#include <stdio.h>
void dfs(int layer, int n, int *number, int *ans, int *used);

int main()
{
    int n;
    // printf("input n: ");
    while (scanf("%d", &n) != EOF)
    {
        int used[n]; //初始化為０
        int number[n];
        int ans[n];
        int layer = 0;
        for (int i = 0; i < n; i++)
        {
            used[i] = 0;       // 先初始化為0
            number[i] = n - i; // number[]={3,2,1}
        }
        dfs(layer, n, number, ans, used);
    }
    return 0;
}

void dfs(int layer, int n, int *number, int *ans, int *used)
{
    if (layer == n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d", ans[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (used[i] == 0)
        {
            used[i] = 1; // 用過了
            ans[layer] = number[i];
            dfs(layer + 1, n, number, ans, used);
            used[i] = 0;
        }
    }
}
