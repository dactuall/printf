#include "ft_printf.h"

int	ft_putnbr(int	n)
{
	int	nbr;
	int	len;

	nbr = n;
	len = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		len += ft_putnbr(nbr * -1);
	}
	else if (nbr >= 10)
	{
		len += ft_putnbr(nbr / 10);
		len += ft_putnbr(nbr % 10);
	}
	else
		len += ft_putchr(nbr + '0');
	return (len);
}

int	ft_putnbr_u(unsigned int	n)
{
	int	len;

	len = 0;
	if (n >= 10)
	{
		len += ft_putnbr_u(n / 10);
		len += ft_putnbr_u(n % 10);
	}
	else
		len += ft_putchr(n + '0');
	return (len);
}

int	ft_putpointer(unsigned	long	n)
{
	char	hex[] = "0123456789abcdef";
	char	tmp[17];
	int	len;
	int	i;

	if (!n)
	{
		write(1, "0x0", 3);
		return (3);
	}
	i = 0;
	while (n)
	{
		tmp[i++] = hex[n % 16];
		n /= 16;
	}
	tmp[i] = '\0';
	len = i + 2;
	i--;
	write(1, "0x", 2);
	while (i >= 0)
		write(1, &tmp[i--], 1);
	return (len);
}

int	ft_putupper_hex(unsigned int	n)
{
	static char	hex[] = "0123456789ABCDEF";
	char		tmp[9];
	int		len;
	int		i;
	if (!n)
	{
		write(1, "0", 1);
		return (1);
	}
	i = 0;
	while (n)
	{
		tmp[i++] = hex[n % 16];
		n /= 16;
	}
	tmp[i] = '\0';
	len = i;
	i--;
	while (i >= 0)
		write(1, &tmp[i++], 1);
	return (len);
}

int	ft_putlower_hex(unsigned int	n)
{
	static char	hex[] = "0123456789abcdef";
	char		tmp[9];
	int		len;
	int		i;
	if (!n)
	{
		write(1, "0", 1);
		return (1);
	}
	i = 0;
	while (n)
	{
		tmp[i++] = hex[n % 16];
		n /= 16;
	}
	tmp[i] = '\0';
	len = i;
	i--;
	while (i >= 0)
		write(1, &tmp[i++], 1);
	return (len);
}

