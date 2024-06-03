/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:10:07 by dtoszek           #+#    #+#             */
/*   Updated: 2024/03/07 12:16:19 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_atoi(const char *nptr)
{
	int		i;
	int		neg;
	int		res;

	i = 0;
	neg = 1;
	res = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	return (res * neg);
}

/*
int	main()
{
	int i = ft_atoi("	  \n\f\t2147483647ab213");
	int j = ft_atoi("	  \n\f\t-2147483648ab213");
	int k = ft_atoi("	  \n\f\t0ab213");
	printf("%i", i);
	printf("%i", j);
	printf("%i", k);
}
*/