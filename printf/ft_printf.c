/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarkoez <bsarkoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 13:27:34 by bsarkoez          #+#    #+#             */
/*   Updated: 2026/10/27 14:38:22 by bsarkoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_next(char c, va_list list, int *count)
{
	if (c == 'c')
		ft_putchar(va_arg(list, int), count);
	if (c == 's')
		ft_putstr(va_arg(list, char *), count);
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(list, int), count);
	if (c == 'u')
		ft_putnbr(va_arg(list, unsigned int), count);
	if (c == 'x')
		ft_puthex(va_arg(list, unsigned int), HEX_LOW, count);
	if (c == 'X')
		ft_puthex(va_arg(list, unsigned int), HEX_UP, count);
	if (c == 'p')
		ft_putptr(va_arg(list, void *), count);
	if (c == '%')
		ft_putchar('%', count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	list;

	if (!format)
		return (-1);
	count = 0;
	i = 0;
	va_start (list, format);
	while (format[i])
	{
		if ((format[i] == '%') && format[i + 1])
		{
			ft_next(format[i + 1], list, &count);
			i += 2;
		}
		else
		{
			ft_putchar(format[i], &count);
			i++;
		}
	}
	va_end(list);
	return (count);
}

// #include <stdio.h>
// #include <assert.h>

// int	main(void)
// {
// 	assert(ft_printf("Hello %%\n", "") == printf("Hello %s\n", "hello"));
// 	// ft_printf("Hello %%\n", " World");
// 	// printf("Hello %%\n", " World");
// }