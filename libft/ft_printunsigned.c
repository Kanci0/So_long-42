/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:27:23 by dtoszek           #+#    #+#             */
/*   Updated: 2024/05/25 12:14:16 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_number_size(unsigned int number)
{
	unsigned int	length;

	length = 0;
	if (number == 0)
		length++;
	while (number != 0)
	{
		number /= 10;
		length++;
	}
	return (length);
}

static char	*ft_uitoa(unsigned int n)
{
	char			*string;
	unsigned int	length;

	length = ft_number_size(n);
	string = (char *)malloc(sizeof(char) * (length + 1));
	if (string == NULL)
		return (NULL);
	if (n == 0)
		string[0] = '0';
	string[length] = '\0';
	while (n != 0)
	{
		string[length - 1] = (n % 10) + '0';
		n = n / 10;
		length--;
	}
	return (string);
}

int	ft_printunsigned(unsigned int n)
{
	int		len;
	char	*str;

	len = 0;
	str = ft_uitoa(n);
	len = ft_printstr(str);
	free(str);
	return (len);
}
