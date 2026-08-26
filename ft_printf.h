/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumidill <mumidill@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 01:55:19 by mumidill          #+#    #+#             */
/*   Updated: 2026/08/26 19:59:59 by mumidill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);

int	ft_putstr(char *s);
int	ft_putchar(int c);
int	ft_putaddr(void *p);
int	ft_putnbr_base_unsigned(unsigned long nbr, const char *base);
int	ft_putnbr_base(long nbr, const char *base);

#endif