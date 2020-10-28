#include <stdio.h>
#include <math.h>
int reverse(int n);
int caculate_sum(int n);

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int start = 0;
        int array[n];
        int digit;
        for (int i = 0; i < n; i++)
        {
            array[i] = 0; // 歸0
        }

        // printf("sum is %d\n", caculate_sum(n));
        // 發現3位數的總和一定是6,4位數一定是10

        for (int i = n; i >= 1; i--)
        {
            start += pow(10, i - 1) * i;
        }

        int end = reverse(start);
        // printf("start is %d\n", start);
        // printf("end is %d\n", end);

        for (int i = start; i >= end; i--)
        {
            int sum = 0;
            int success = 1; // 成功
            int num = i;     // 建一個變數來除
            digit = log10(i);
            // printf("digit is %d\n", digit);
            for (int j = 0; j <= digit; j++)
            {
                // i = 321, remainder = 1, num = 321;
                int remainder = num % 10;
                num /= 10;
                sum += remainder;
                if (remainder >= 1 && remainder <= 3)
                    array[remainder - 1]++;
            }

            // printf("i here is %d, sum is %d\n", i, sum);

            for (int j = 0; j <= digit; j++)
            {
                if (array[j] == 1)
                {
                    success = 1;
                }
                else
                {
                    success = 0;
                    break;
                }
            }

            for (int i = 0; i < n; i++)
            {
                array[i] = 0; // 歸0
            }

            if (success == 1 && sum == caculate_sum(n))
            {
                printf("%d\n", i);
            }
        }
    }
    return 0;
}

int reverse(int n)
{
    int temp = 0;
    int digit = log10(n);
    // 123 -> 321
    for (int i = 0; i <= digit; i++) // 要做digit+1次，因為位數是digit+1位
    {
        temp += (n % 10) * pow(10, digit - i);
        n /= 10;
    }
    return temp;
}

// 計算1~n的總和為多少
int caculate_sum(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}
