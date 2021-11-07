#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char	*s, ...);
int	parse_mod(char	c, va_list	ap);
int	ft_putprocent(void);
int	ft_putchr(int	c);
int	ft_putstr(char	*s);
int	ft_putnbr(int	n);
int	ft_putnbr_u(unsigned int	n);
int	ft_putpointer(unsigned long	n);
int	ft_putupper_hex(unsigned int	n);
int	ft_putlower_hex(unsigned int	n);

#endif
