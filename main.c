#include "ft_printf.h"
#include <stdint.h>
int     main()
{
    //printf("%d", ft_printf("test\n"));
    // printf("%d\n", ft_printf("%*.*d|", -9, 5, -100));
    // printf("%d\n", printf("%*.*d|", -9, 5, -100));
    //printf("%.5%\n");
    // printf("r: %d\n", ft_printf("%d|", 100));
    // printf("or: %d\n", printf("%d|", 100));
	printf("r: %d\n", ft_printf("%d|", INT32_MIN));
	printf("or: %d\n", printf("%d|", INT32_MIN));
	// printf("r: %d\n", printf("%d|", INT32_MAX + 95));
	// printf("or: %d\n", ft_printf("%d|", INT32_MAX + 95));
	// printf("r: %d\n", printf("%d|", 0));
	// printf("or: %d\n", ft_printf("%d|", 0));
	// printf("r: %d\n", printf("a%da|", 100));
	// printf("or: %d\n", ft_printf("a%da|", 100));
	// printf("r: %d\n", printf("a%da|", INT32_MIN));
	// printf("or: %d\n", printf("a%da|", INT32_MIN));
	// printf("r: %d\n", ft_printf("a%da|", 0));
	// printf("or: %d\n", printf("a%da|", 0));
    return 0;
}