#include <stdio.h>
int main()
{
    char array[5];
    printf("    array = %25p\n&array[0] = %25p\n   &array = %25p\n", array, &array[0], &array);
    printf("hi\n"
           "abc\n");
}
