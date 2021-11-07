#include "ft_printf.h"

int	main()
{
	char	c = 'A';
	int	i = -1000;
	char	*s = "RAMAZ";
	unsigned long p = 29;
	unsigned int  u = 1000;
	unsigned int  x = 29;
	ft_printf("%%c = %c, %%s = %s, %%p = %p, %%d = %d, %%i = %d, %%u = %u\n", c, s, p, i, i, u);

}
