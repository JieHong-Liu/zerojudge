#include <stdio.h>
int main()
{
  char K = -7; // 解碼用
  char original[1000] = {};

  scanf("%s", original);

  for (int i = 0; original[i] != '\0'; i++)
  {
    original[i] = original[i] + K;
  }

  printf("%s", original);

  return 0;
}
