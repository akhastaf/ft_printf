#include "ft_printf.h"
#include <stdint.h>
int     main()
{
	
	// unsigned int n;

	// n = 10;

	//ft_puthex(n, 0);
	// ft_printf("%",31);
    //printf("%d", ft_printf("test\n"));
    // printf("%d\n", ft_printf("%*.*d|", -9, 5, -100));
    // printf("%d\n", printf("%*.*d|", -9, 5, -100));
    //printf("%.5%\n");
	//T("%4.d", 100);
	//ft_printf("|%u|", 100);
	// ft_printf("%d\n", ft_printf("|%u|", 100)); // ("%u", 100)
	//printf("%d\n", printf("|%u|", 100));
	// printf("%d\n", ft_printf("|%x|", 0));  // ("%-2d", 100)
	// printf("%d\n", printf("|%x|", 0));
    //if (ft_printf("%4d", 100) ==
    //   printf("%4d", 100))
	//   printf("\n1");
	// printf("r: %d\n", ft_printf("%d|", INT32_MIN));
	// printf("or: %d\n", printf("%d|", INT32_MIN));
	// printf("r: %d\n", printf("%d|", INT32_MAX + 95));
	// printf("or: %d\n", ft_printf("%d|", INT32_MAX + 95));
	// printf("or: %d\n", printf("%d|", 0));
	// printf("r: %d\n", ft_printf("%d|", 0));
	// printf("r: %d\n", printf("a%da|", 100));
	// printf("or: %d\n", ft_printf("a%da|", 100));
	// printf("r: %d\n", printf("a%da|", INT32_MIN));
	// printf("or: %d\n", printf("a%da|", INT32_MIN));
	// printf("r: %d\n", ft_printf("a%da|", 0));
	// printf("or: %d\n", printf("a%da|", 0));
	// printf("ABC");
	// write(1, "123 ",3);
	// ft_printf("%s", NULL);
	//printf("%d\n", printf("%2s", "ABC"));
	printf("%d\n", ft_printf("|%p|", (void *)UINT64_MAX));
	printf("%d\n", printf("|%p|", (void *)UINT64_MAX));
    return 0;
}