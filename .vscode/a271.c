/*

在一個神奇的國度裡，有一種兔子，它只吃蘿蔔，且每天只吃一個，蘿蔔有四種顏色，分別為：紅蘿蔔，白蘿蔔，黃蘿蔔，發霉的蘿蔔（黑色），兔子吃了蘿蔔之後，體重會有不同的變化，紅蘿蔔吃了胖xg，白蘿蔔吃了胖yg，黃蘿蔔吃了瘦zg(醃黃蘿蔔真難吃...)，發霉的蘿蔔吃了瘦wg(附加狀態：中毒...)，現在給你x,y,z,w問你幾天後，兔子的體重！

p.s.中毒會使兔子每天瘦ng(中毒當天不算),且中毒狀態可累加，m是兔子初始的體重。早上先中毒，晚上才吃東西。

上面的敘述很重要，要仔細看！

第一行是測資的筆數，每筆測資第一行是x,y,z,w,n,m，第二行是一串數字，1代表紅蘿蔔，2代表白蘿蔔，3代表黃蘿蔔，4代表黑蘿蔔，0代表沒吃。這一行中的數字為兔子這段時間內所吃的食物。

請輸出兔子在那段時間後所剩的體重，如果體重有在任意時刻少於等於0請輸出："bye~Rabbit"(不含引號)，不然請印出結束時的體重。（詳情參照範例輸入輸出）

有可能問你第一天的體重歐！(就是問初始體重，也就是那行根本沒輸入)
例如如：
13 312 43 432 567
//空一行

輸出為：567
*/

#include <stdio.h>
#include <string.h>
int main()
{
    int numbers;
    // printf("how many q: ");
    scanf("%d", &numbers);
    long long int red, white, yellow, black;
    long long int poisson, Initial_KG;
    int doo = 0; // 中毒的變數
    for (int i = 0; i < numbers; i++)
    {
        doo = 0;
        int die = 0;
        char buf[1000];
        // printf("input kg:\n");
        scanf("%lld%lld%lld%lld%lld%lld", &red, &white, &yellow, &black, &poisson, &Initial_KG);
        char c = getchar(); // 拿來擋換行
        // printf("input radish : ");
        gets(buf);
        // puts(buf);
        for (int i = 0; i < strlen(buf); i++)
        {
            if (die == 0)
                switch (buf[i])
                {
                case '0': // 沒吃東西靠北忘記加= =

                    Initial_KG -= (doo * poisson);
                    if (Initial_KG <= 0)
                    {
                        die = 1;
                        printf("bye~Rabbit\n");
                        break;
                    }
                    break;
                case '1':

                    Initial_KG -= (doo * poisson);

                    if (Initial_KG <= 0)
                    {
                        die = 1;
                        printf("bye~Rabbit\n");
                        break;
                    }
                    Initial_KG += red;
                    break;
                case '2':

                    Initial_KG -= (doo * poisson);

                    if (Initial_KG <= 0)
                    {
                        die = 1;
                        printf("bye~Rabbit\n");
                        break;
                    }
                    Initial_KG += white;

                    break;
                case '3':

                    Initial_KG -= (doo * poisson);
                    Initial_KG -= yellow;

                    if (Initial_KG <= 0)
                    {
                        die = 1;
                        printf("bye~Rabbit\n");
                        break;
                    }
                    break;
                case '4':

                    Initial_KG -= (doo * poisson);

                    Initial_KG -= black;
                    if (Initial_KG <= 0)
                    {
                        die = 1;
                        printf("bye~Rabbit\n");
                        break;
                    }
                    doo++;

                    break;

                default:
                    break;
                }
        }
        if (Initial_KG > 0)
            printf("%lldg\n", Initial_KG);
    }

    return 0;
}
