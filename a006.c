//求一元二次方程式 ax2+bx+c=0 的根

#include <stdio.h>
#include <math.h>
int main()
{
  int a, b, c, D;
  int x1, x2;
  scanf("%d %d %d", &a, &b, &c);
  D = b * b - 4 * a * c;
  x1 = (-b + sqrt(b * b - 4 * a * c)) / 2 * a;
  x2 = (-b - sqrt(b * b - 4 * a * c)) / 2 * a;
  if (D > 0)
  {
    printf("Two different roots x1=%d , x2=%d", x1, x2);
  }
  else if (D == 0)
  {
    printf("Two same roots x=%d", x1);
  }
  else if (D < 0)
  {
    printf("No real root")
  }
  return 0;
}
