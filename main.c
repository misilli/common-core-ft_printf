/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumidill <mumidill@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 20:00:03 by mumidill          #+#    #+#             */
/*   Updated: 2026/08/24 19:36:57 by mumidill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	ft_putnbr(long n)
{
	if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-(unsigned long)n);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

void	ft_putnbr_base(long nbr, char *base)
{
	size_t	len;

	len = ft_strlen(base);
	if (len < 2)
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= len)
		ft_putnbr_base(nbr / len, base);
	ft_putchar(base[nbr % len]);
}

void	adresyazmafonksiyonu(void *p)
{
	if(!p)
		return;
	unsigned long	adres;

	adres = (unsigned long)p;
	ft_putstr("0x");
	ft_putnbr_base(adres, "0123456789abcdef");
}

// va arg ile burda ilerlet
void	ft_print(va_list i, int a, char c)
{
	if (c == 'c')
		ft_putchar(va_arg(i, int));
	else if (c == 's')
		ft_putstr(va_arg(i, char *));
	else if (c == 'p')
		adresyazmafonksiyonu(va_arg(i, void *));
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(i, int));
	else if (c == 'u')
		ft_putnbr(va_arg(i, unsigned int));
	else if (c == 'x')
		ft_putnbr_base(va_arg(i, int), "0123456789abcdef");
	else if (c == 'X')
		ft_putnbr_base(va_arg(i, int), "0123456789ABCDEF");
	/*else if (c == '%')
		printf("%%", i);*/
}

int	ft_printf(const char *str, ...)
{
	va_list	values;
	int		i;
	int		val;

	va_start(values, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_print(values, 0, str[i + 1]);
			i++;
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	return (0);
}

int	main(void)
{
	char a = '2';
	char b[] = "abc";
	unsigned int c = 3000000;
	char *pa = &a;
	//printf("%p", (void *)pa);
	ft_printf("%p", (void *)pa);
}