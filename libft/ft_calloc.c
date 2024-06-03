/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:27:11 by dtoszek           #+#    #+#             */
/*   Updated: 2024/03/07 15:44:15 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmeb, size_t size)
{
	void	*p;

	if (nmeb == 0 || size == 0)
	{
		nmeb = 1;
		size = 1;
	}
	if (2147483647 / nmeb < size)
		return (NULL);
	p = malloc(nmeb * size);
	if (p == NULL)
		return (NULL);
	else
		ft_bzero(p, (nmeb * size));
	return (p);
}
