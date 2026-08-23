/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumidill <mumidill@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 20:00:03 by mumidill          #+#    #+#             */
/*   Updated: 2026/08/23 20:00:03 by mumidill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>

void ft_putchar(int c)
{
    write(1,&c,1);
}
//va arg ile burda ilerlet
void ft_print(va_list i,int a, char c)
{
    va_arg(i,char):
    if (c == 'c')
        ft_putchar(va_arg);
    else if (c == 's')
        printf("%s", i);
    else if (c == 'p')
        printf("%p", i);
    else if (c == 'd')
        va_arg(i,int):
        printf("%d", i);
    else if (c == 'i')
        printf("%i", i);
    else if (c == 'u')
        printf("%u", i);
    else if (c == 'x')
        printf("%x", i);
    else if (c == 'X')
        printf("%X", i);
    else if (c == '%')
        printf("%%", i);
}

int	ft_printf(const char *str, ...)
{
    va_list values;
    int i;
    int val;
    va_start(values, str);

    while (str[i])
    {
        if (str[i] == '%')
        {
            ft_print(values,0,str[i + 1]);
            printf("%d", val);
        }
        else
            ft_putchar(str[i]);
            length++;
        i++;
    }
    

    return(0);

}

int main()
{
    int a = 123;
    int b = 124;
    int c = 125;
    ft_printf("wqd%d\nfds%d\nfdsa%d",a,b,c );
}