/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumidill <mumidill@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 20:00:03 by mumidill          #+#    #+#             */
/*   Updated: 2026/08/25 19:57:44 by mumidill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */





#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return(1);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr(char *s)
{
	int	i;
	int len;

	len = 0;
	i = 0;
	while (s[i] != '\0')
	{
		len += ft_putchar(s[i]);
		i++;
	}
	return(len);
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

int	ft_putnbr_base(long nbr, char *base)
{
	int	len;
	

	len = ft_strlen(base);
	if (len < 2)
		return (67);
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
	ft_putnbr_base(adres, "0123456789abcdef");0x7ffeb70cdedf
}

// va arg ile burda ilerlet
int	ft_print(va_list i, char c)
{
	if (c == 'c')
		return(ft_putchar(va_arg(i, int)));
	else if (c == 's')
		return(ft_putstr(va_arg(i, char *)));
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
	else if (c == '%')
		printf("%%", i);
	return(0);
}

int	ft_printf(const char *str, ...)
{
	va_list	values;
	int		i;
	int		len;
	
	len = 0;
	i = 0;
	va_start(values, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			len += ft_print(values, str[i + 1]);
			i++;
		}
		else

			len += ft_putchar(str[i]);
		i++;
	}
	va_end(values);
	return (len);
}

int	main(void)
{
	char *p;

	p =12;
	
	printf("!!%p" , (void *)p);
}