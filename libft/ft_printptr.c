/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:23:40 by dtoszek           #+#    #+#             */
/*   Updated: 2024/05/25 12:14:08 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ptrlen(unsigned long long int ptr)
{
	int	len;

	len = 0;
	while (ptr != 0)
	{
		ptr = ptr / 16;
		len++;
	}
	return (len);
}

static void	ft_prtptr(unsigned long long int ptr)
{
	if (ptr >= 16)
	{
		ft_prtptr(ptr / 16);
		ft_prtptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd(ptr + '0', 1);
		else
			ft_putchar_fd(ptr - 10 + 'a', 1);
	}
}

int	ft_printptr(unsigned long long int ptr)
{
	int		len;

	len = 0;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	len += write(1, "0x", 2);
	if (ptr == 0)
		len += write(1, "0", 1);
	else
	{
		ft_prtptr(ptr);
		len += ft_ptrlen(ptr);
	}
	return (len);
}
