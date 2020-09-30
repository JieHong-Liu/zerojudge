//相信判斷一個數除以三的餘數是多少，對你來說應該沒有問題。那，如果一次請你判斷很多個數呢嘿嘿？給你n個數字，請你輸出3k、3k+1、3k+2的數各有幾個

#include <stdio.h>
int main()
{
    int number = 0;
    scanf("%d", &number);
    int ans[3] = {0, 0, 0};
    int quiz;
    for (int i = 0; i < number; i++)
    {
        scanf("%d", &quiz);
        ans[quiz % 3]++;
    }
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}
