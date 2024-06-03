/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:34:27 by dtoszek           #+#    #+#             */
/*   Updated: 2024/05/25 13:12:37 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hexlen(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		num = num / 16;
		len++;
	}
	return (len);
}

static void	ft_prthex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_prthex(num / 16, format);
		ft_prthex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd(num + '0', 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd(num + 'a', 1);
			else if (format == 'X')
				ft_putchar_fd(num + 'A', 1);
		}
	}
}

int	ft_printhex(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_prthex(num, format);
	return (ft_hexlen(num));
}
