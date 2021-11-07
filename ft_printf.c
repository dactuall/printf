#include "ft_printf.h"

int	ft_printf(const char	*s, ...)
{
	int	i;
	int	len;
	va_list	ap;

	if (!s)
		return (0);
	i = 0;
	len = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] != '\0')
		{
			len += parse_mod(s[i + 1], ap);
			i++;
		}
		else
		{
			write(1, &s[i], 1);
			len++;
		}
		i++;
	}
	va_end(ap);
	return (len);
}

int	parse_mod(char	c, va_list ap)
{
	if (c == 'c')
		return (ft_putchr(va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == 'p')
		return (ft_putpointer(va_arg(ap, unsigned long)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_putnbr_u(va_arg(ap, unsigned int)));
	else if (c == 'x')
		return (ft_putupper_hex(va_arg(ap, unsigned int)));
	else if (c == 'X')
		return (ft_putlower_hex(va_arg(ap, unsigned int)));
	else
		return (ft_putprocent());
}

int	ft_putprocent()
{
	write(1, "%", 1);
	return (1);
}

int	ft_putchr(int	c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char	*s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
