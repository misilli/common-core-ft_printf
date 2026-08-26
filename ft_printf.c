/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumidill <mumidill@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 01:54:14 by mumidill          #+#    #+#             */
/*   Updated: 2026/08/26 20:03:26 by mumidill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_print(va_list *i, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*i, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*i, char *)));
	else if (c == 'p')
		return (ft_putaddr(va_arg(*i, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_base(va_arg(*i, int), "0123456789"));
	else if (c == 'u')
		return (ft_putnbr_base_unsigned(va_arg(*i, unsigned int),
				"0123456789"));
	else if (c == 'x')
		return (ft_putnbr_base_unsigned(va_arg(*i, unsigned int),
				"0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr_base_unsigned(va_arg(*i, unsigned int),
				"0123456789ABCDEF"));
	else if (c == '%')
		return (ft_putchar('%'));
	return (ft_putchar('%') + ft_putchar(c));
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
			len += ft_print(&values, str[i + 1]);
			i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(values);
	return (len);
}
