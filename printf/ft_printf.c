/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesh <mesh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 13:27:34 by bsarkoez          #+#    #+#             */
/*   Updated: 2026/10/26 21:42:19 by mesh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	list;

	if (!s)
		return (-1);
	count = 0;
	i = 0;
	va_start (list, s);
	while (s[i])
	{
		if ((s[i] == '%') && s[i + 1])
		{
			ft_next(s[i + 1], list, &count);
			i += 2;
		}
		else 
		{	
			ft_putchar(s[i], &count);
			i++;
		}
	}
	va_end(list);
	return (count);
}

void	ft_next(char *c, va_list(list), int *count)
{
	if (c == 'c')
		ft_putchar(va_arg(list, int), count);
	if (c == 's')
		ft_putstr(va_arg(list, int), count);
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(list, int), count);
	if (c == 'u')
		ft_putnbr(va_arg(list, unsigned int), count);
	if (c == 'x')
		ft_putnbr(va_arg(list, unsigned int), count);
	if (c == 'X')
		ft_putnbr(va_arg(list, unsigned int), count);
	if (c == 'p')
		ft_putptr(va_arg(list, void *), count);
	if (c == '%')
		ft_putchar('%', count);
}
