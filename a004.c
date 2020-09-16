#include <stdio.h>
/*----------------------------------------------------------------
    文文為即將出國的珊珊送行，由於珊珊不喜歡別人給文文的那個綽號，意思就是嘲笑文文不夠 聰明，但珊珊沒把握那個綽號是不是事實，所以珊珊決定考驗文文，於是告訴文文說，如果你能在 我回國之前回答我生日那年是不是閏年，則等她回國後就答應他的求婚。文文抓抓腦袋想不出來， 於是決定讓最擅長做運算的電腦來幫忙。

*/
int main()
{
  int leave;
  while (scanf("%d", &leave) != EOF)
  {
    int year = leave;
    if (year % 4 == 0 && year % 100 != 0)
    {
      printf("閏年\n");
    }
    else if (year % 400 == 0)
    {
      printf("閏年\n");
    }
    else
    {
      printf("平年\n");
    }
  }
  return 0;
}
