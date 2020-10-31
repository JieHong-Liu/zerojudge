/* John是一個赫赫有名的藝術品投資專家，每個月都會計算藝術品投資的盈虧，以審視其獲利。
    John每個月月底，即開始計算其每一件藝術品的獲利狀況。由於藝術品的種類繁多，John每個月總是要花費許多時間，計算其獲利狀況，以決定是否要將藝術品出脫。
    因此，他想麻煩你撰寫一支程式，計算每一件藝術品的盈虧狀況。

    測試資料的第一行是一個整數 n，代表John總共投資了 n 件藝術品。以下 n 行，每一行有兩個整數 m 和 p，m 是該藝術品投資的金額、p 是該藝術品目前的價值。其中 1≤m,p≤100000，單位是仟元。

    每一件藝術品依據它的投資金額及目前價值，計算並輸出其獲利率 x。x為正，表示獲利；
    x為負表示虧損。若x≥10.00% 或 x≤-7.00%，即售出該藝術品，以「dispose」表示；否則，即保留該藝術品，以「keep」表示。輸出格式，請見輸出範例。
    */
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n); // 共有n行
    double invest_money, value;
    double profit;
    for (int i = 0; i < n; i++)
    {
        scanf("%lf%lf", &invest_money, &value);
        profit = value / invest_money;
        profit -= 1;           // caculate profit formula
        profit = profit * 100; // 100是100%

        if (profit >= 10.0 || profit <= -7.0)
        {
            if (profit >= 0)
            {
                profit += 0.0000001;

                printf("%.2lf%%", profit);
            }
            else if (profit < 0)
            {
                profit -= 0.0000001;

                printf("%.2lf%%", profit);
            }
            printf(" dispose\n");
        }
        else
        {
            if (profit >= 0)
            {
                profit += 0.0000001;
                printf("%.2lf%%", profit);
            }
            else if (profit < 0)
            {
                profit -= 0.0000001;

                printf("%.2lf%%", profit);
            }
            printf(" keep\n");
        }
    }

    return 0;
}
