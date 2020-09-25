//a024: 最大公因數(GCD)

//給定兩個整數，請求出它們的最大公因數

// 本題利用輾轉相除法
// 計算gcd(48,18)時，先將48除以18得到商2、餘數12，
// 然後再將18除以12得到商1、餘數6，
// 再將12除以6得到商2、餘數0，即得到最大公因數6。
// 我們只關心每次除法的餘數是否為0，為0即表示得到答案。

#include <stdio.h>
int gcd(int a, int b)
{
    int remainder = a % b;
    if (remainder == 0)
    {
        return b;
    }
    else
    {
        return gcd(b, remainder);
    }
}
int main()
{
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);

    if (b > a)
    {
        int temp;
        temp = a;
        a = b;
        b = temp;
    }
    int ans = gcd(a, b);
    // 大的放a，小的放b
    printf("%d\n", ans);
    return 0;
}
