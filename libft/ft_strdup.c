/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:44:34 by dtoszek           #+#    #+#             */
/*   Updated: 2024/03/07 15:52:05 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(s) + 1;
	dup = malloc(sizeof(char) * len);
	if (!dup)
		return (0);
	dup = ft_memcpy(dup, s, len);
	return (dup);
}

/*
int	main()
{
	printf("%s", ft_strdup("sentens"));	
}
*/