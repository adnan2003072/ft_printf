#include "include/ft_printf.h"
#include <stdio.h>

int main(void)
{
    int x = printf("%");
    int a = ft_printf("%");

    fprintf(stderr, "%d\n", x);
    fprintf(stderr, "%d\n", a);

    return 0;
}