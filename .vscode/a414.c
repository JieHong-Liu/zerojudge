#include <stdio.h>
// 二進位轉換
// N+1會進位幾次
// 從第0位開始判斷，遇到0就停

int main()
{
    int number;
    scanf("%d", &number);
    while (number != 0)
    {
        int count = 0; // 拿來判斷有幾位
        int remainder;
        int all_one = 1;
        // 因為while的關係，所以只能判斷到MSB的前一位，所以如果全部都是1，那就要再加1，EX: 3
        // 3 in binary: 11, 3+1 = 4 , 4 in binary: 100 , hence:output = 2;
        do
        {
            if (number == 1)
            {
                count = -1; // 1要特別處理
            }
            remainder = number % 2;
            number /= 2;
            // 遇到0就break
            if (remainder == 0)
            {
                all_one = 0;
                break;
            }
            // 否則count就++
            else
            {
                count++;
            }
        } while (number >= 2);
        if (all_one == 1)
        {
            printf("%d\n", count + 1);
        }
        else
        {
            printf("%d\n", count);
        }

        scanf("%d", &number);
    }

    return 0;
}
