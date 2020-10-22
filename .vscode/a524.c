#include <stdio.h>
#include <math.h>
int reverse(int n);

int main()
{
    int n;
    scanf("%d", &n);
    int start = 0;
    for (int i = 3; i >= 1; i--)
    {
        start += pow(10, i - 1) * i;
    }
    int end = reverse(start);
    printf("start is %d\n", start);
    printf("end is %d\n", end);
    for (int i = start; i >= end; i--)
    {
        if ()
        {
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
