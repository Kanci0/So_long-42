/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:03:54 by dtoszek           #+#    #+#             */
/*   Updated: 2024/05/25 12:13:54 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	formats_ft(va_list args, const char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_printchar(va_arg(args, int));
	else if (format == 's')
		count += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		count += ft_printptr(va_arg(args, unsigned long long int));
	else if (format == 'd' || format == 'i')
		count += ft_printint(va_arg(args, int));
	else if (format == 'u')
		count += ft_printunsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		count += ft_printhex(va_arg(args, unsigned int), format);
	else if (format == '%')
		count += ft_printprecent();
	return (count);
}

int	ft_printf(const char *str, ...)
{
	unsigned int	i;
	va_list			args;
	unsigned int	count;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			count += formats_ft(args, str[i + 1]);
			i++;
		}
		else
		{
			count += 1;
			write(1, &str[i], 1);
		}
		i++;
	}
	return (count);
}
