#include "include/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf("%p is %x years old.\n", NULL, 'a');
	ft_printf("%p is %x years old.\n", NULL, 'a');
	return 0;
}
