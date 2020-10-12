#include <stdio.h>
int main()
{
    int a, b, c, d, e, f;
    float x, y;
    // ax+ by = c
    // dx+ ey = f
    // 當∆≠0 時，方程組恰有一解(x,y)
    // 當∆=∆x=∆y=0，方程組有無限多解。[兩直線重合]
    // 當∆=0，而∆x、∆y有一不為 0 時，方程組無解。[兩直線平行]
    while (scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f) != EOF)
    {
        int delta = a * e - b * d;
        float delta_x = c * e - b * f;
        float delta_y = a * f - c * d;

        if (delta == 0 && delta_x == 0 && delta_y == 0)
        {
            printf("Too many\n");
            break;
        }
        else if (delta == 0)
        {
            if (delta_x != 0 || delta_y != 0)
            {
                printf("No answer");
                break;
            }
        }

        x = delta_x / delta;
        y = delta_y / delta;

        printf("x=%.2f\ny=%.2f\n", x, y);
    }
    return 0;
}
