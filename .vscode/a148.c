#include <stdio.h>
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int grade;
        float sum = 0;
        float average;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &grade);
            sum += grade;
        }
        average = sum / (n);
        // printf("average = %f\n", average);
        if (average > 59.0)
        {
            printf("no\n");
        }
        else
        {
            printf("yes\n");
        }
    }
    return 0;
}
