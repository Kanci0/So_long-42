/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:56:12 by dtoszek           #+#    #+#             */
/*   Updated: 2024/03/07 12:14:55 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char	*cpy;

	cpy = (char *)s;
	while (n > 0)
	{
		cpy[n - 1] = c;
		n--;
	}
	return (s);
}

/*
int	main()
{
	char c[] = "simple test";
	ft_memset(c, 78, 3);
	printf("%s", c);
}
*/