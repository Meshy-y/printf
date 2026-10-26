/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarkoez <bsarkoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 16:36:19 by bsarkoez          #+#    #+#             */
/*   Updated: 2026/10/19 17:20:15 by bsarkoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_str(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		write (1, &c[i], 1);
		i++;
	}
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	list;

	i = 0;
	va_start (list, s);
	while (s[i] != 0)
	{
		if ((s[i] == '%') && s[i + 1] == 's')
		{
			ft_str(va_arg(list, char *));
			i += 2;
		}
		write (1, &s[i], 1);
		i++;
	}
	va_end(list);
	return (i);
}
#include "stdio.h"

int	main(void)
{
	ft_printf("%s world\n", "Hello");
	printf("%s world\n", "Hello");
}
