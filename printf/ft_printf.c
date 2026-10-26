/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarkoez <bsarkoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 13:27:34 by bsarkoez          #+#    #+#             */
/*   Updated: 2026/10/21 14:59:10 by bsarkoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	list;

	i = 0;
	va_start (list, s);
	while (s[i] != 0)
	{
		if ((s[i] == '%') && s[i + 1] == 'c')
		{
			ft_putchar(va_arg(list, int));
			i += 2;
		}
		write (1, &s[i], 1);
		i++;
	}
	va_end(list);
	return (i);
}

// int	main(void)
// {
// 	ft_printf("%c hello \n",  'X');
// 	printf("%c hello \n",  'X');
// 	return (0);
// }

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	list;

	count = 0;
	i = 0;
	va_start (list, s);
	if (!s)
		return (-1);
	while (s[i] != 0)
	{
		if ((s[i] == '%') && s[i + 1])
		{
			if (!va_arg(list, int))
				return (NULL);
			count = ft_count_words(*s);
			ft_next(s[i]);
			i += 2;
		}
		write (1, &s[i], 1);
		i++;
		count++;
	}
	va_end(list);
	return (count);
}

int	ft_count_words(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_numbase(int n)
{
	char	c;
	int		count;

	count = 0;
	if (n == -2147483648)
		write (1, "-2147483648", 11);
	return (11);
	if (n < 0)
	{
		write (1, "-", 1);
		count++;
		n = -n;
	}
	if (n / 10)
	{
		count += ft_numbase(n / 10);
		c = (n % 10) + '0';
		write (1, &c, 1);
		count++;
	}
	return (count);
}

int	ft_next (const char *str, va_list(list), int *counter)
{
	if (str == 'c')
		ft_putstr_fd(va_arg(list, int), counter);
	if (str == 's')
		ft_putstr_fd(va_arg(list, int), count);
	if (str == 'd')
		count = ft_numbase(va_arg(list, int));
	if (str == 'i')
		count = ft_numbase(va_arg(list, int));
	if (str == 'u')
		count = ft_numbase(va_arg(list, int));
	if (str == 'x')
		
	if (str == 'X')
	if (str == 'p')
	if (str == '%')
		count = ft_putstr_fd(va_arg(list, int));
	return (count);
}

int	ft_string (*str)
{
	int i;

	i = 0;
	if (!str)
		return ((nil));
		ft_putstr_fd (str, i);
}
