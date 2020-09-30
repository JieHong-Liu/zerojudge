#include <stdio.h>
//明明是一個愛數（ㄕㄨˇ）數（ㄕㄨˋ）的好學生，這天媽媽叫他從 n 開始數，下一個數字是 n+1，再下一個數字是 n+2，以此類推。媽媽想知道，明明數了幾個數字之後，他數過的這些數字的總和會超過 m。請幫助明明的媽媽吧。

//輸入以 EOF 結束。每一筆測試資料有兩個數字，分別為 n 和 m，其中 m-n 不會超過 10^5。

int main()
{
    int n, m;

    while (scanf("%d%d", &n, &m) != EOF)
    {
        int sum = 0;
        int count = 0;
        do
        {
            sum = sum + n + count;
            count++;
        } while (sum <= m);

        printf("%d\n", count);
    }

    return 0;
}
