/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:32:13 by dtoszek           #+#    #+#             */
/*   Updated: 2024/03/07 10:32:09 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*con;

	i = 0;
	j = 0;
	con = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (con == 0)
		return (NULL);
	while (s1[i] != '\0')
	{
		con[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		con[i + j] = s2[j];
		j++;
	}
	con[i + j] = '\0';
	return (con);
}
/*
int	main(void)
{
	printf("%s", ft_strjoin("zdanie","tako"));
}
*/