#include <stdio.h>
int main()
{
    int a, b, c, d, e, f;
    float x, y;
    // ax+ by = c
    // dx+ ey = f
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
    int delta = a * e - b * d;
    float delta_x = c * e - b * f;
    float delta_y = a * f - c * d;
    x = delta_x / delta;
    y = delta_y / delta;
    if (delta == 0)
    {
        printf("No answer\n");
    }
    printf("x=%.2f\ny=%.2f\n", x, y);
    return 0;
}
