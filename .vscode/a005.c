#include <stdio.h>
//　　Eva的家庭作業裏有很多數列填空練習。填空練習的要求是：已知數列的前四項，填出第五項。因 為已經知道這些數列只可能是等差或等比數列，她決定寫一個程式來完成這些練習。

int main()
{
  int row = 0;
  scanf("%d", &row);
  int d, r;
  for (int i = 0; i < row; i++)
  {
    int a[5] = {};

    for (int j = 0; j < 4; j++)
    {
      scanf("%d", &a[j]);
    }
    d = a[3] - a[2];
    r = a[3] / a[2];
    if (d == a[1] - a[0])
    {
      a[4] = a[3] + d;
    }
    else if (r == a[1] / a[0])
    {
      a[4] = a[3] * r;
    }
    for (int j = 0; j < 5; j++)
    {
      printf("%d ", a[j]);
    }
    printf("\n");
  }
  return 0;
}
