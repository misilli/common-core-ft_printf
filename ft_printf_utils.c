/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumidill <mumidill@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 01:57:32 by mumidill          #+#    #+#             */
/*   Updated: 2026/08/26 19:53:28 by mumidill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i] != '\0')
	{
		len += ft_putchar(s[i]);
		i++;
	}
	return (len);
}

int	ft_putnbr_base_unsigned(unsigned long nbr, const char *base)
{
	int	len;
	int	count;

	count = 0;
	len = 0;
	while (base[len])
		len++;
	if (nbr >= (unsigned long)len)
		count += ft_putnbr_base_unsigned(nbr / len, base);
	count += ft_putchar(base[nbr % len]);
	return (count);
}

int	ft_putnbr_base(long nbr, const char *base)
{
	int	len;
	int	count;

	count = 0;
	len = 0;
	while (base[len])
		len++;
	if (nbr < 0)
	{
		count += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= len)
		count += ft_putnbr_base(nbr / len, base);
	count += ft_putchar(base[nbr % len]);
	return (count);
}

int	ft_putaddr(void *p)
{
	unsigned long	addr;

	if (p == NULL)
		return (ft_putstr("(nil)"));
	addr = (unsigned long)p;
	ft_putstr("0x");
	return (2 + ft_putnbr_base_unsigned(addr, "0123456789abcdef"));
}
