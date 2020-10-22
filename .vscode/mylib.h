#include <math.h>
// 把數字倒過來
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

// 判斷是否為質數，若是質數return 1，否則return 0;
int determinePrime(int x)
{
    int k = 0;
    if (x == 1 || x == 0)
    {
        return 0;
    }
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            k++;
        }
    }
    if (k == 0)
    {
        return 1; // this is a prime;
    }
    else
    {
        return 0;
    }
}

// 判斷位數

int determineDigit(int n)
{
    int digit = log10(n);
    return digit;
}
