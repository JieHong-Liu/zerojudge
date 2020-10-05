#include <stdio.h>
int main()
{
    int N;
    int a, b, r;
    while (scanf("%d%d%d", &a, &b, &N) != EOF)
    {
        r = a % b;
        a = a / b;
        printf("%d.", a);
        for (int i = 0; i < N; i++)
        {
            r = r * 10;
            printf("%d", r / b);
            r = r % b;
        }
        printf("\n");
    }
    return 0;
}
