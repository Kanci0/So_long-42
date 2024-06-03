/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:02:00 by dtoszek           #+#    #+#             */
/*   Updated: 2024/03/07 16:15:19 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static void	ft_freemem(char *res)
{
	int	i;

	i = 0;
	while (res[i] != '\0')
	{
		free(res);
		i++;
	}
	free(res);
}

static int	ft_wordsamount(char *s, char c)
{
	int	i;
	int	wordam;

	i = 0;
	wordam = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			wordam++;
			while (s[i] != c && s[i] != '\0')
				i++;
			if (s[i] == '\0')
				return (wordam);
		}
		i++;
	}
	return (wordam);
}

static void	ft_strcpy(char *wrd, char *s, char c, int j)
{
	int	i;

	i = 0;
	while (s[j] != '\0' && s[j] == c)
		j++;
	while (s[j + i] != c && s[j + i] != '\0')
	{
		wrd[i] = s[j + i];
		i++;
	}
	wrd[i] = '\0';
}

static char	*ft_alloc(char *s, char c, int *l)
{
	char	*wrd;
	int		i;

	i = *l;
	wrd = NULL;
	while (s[*l] != '\0')
	{
		if (s[*l] != c)
		{
			while (s[*l] != '\0' && s[*l] != c)
				*l += 1;
			wrd = (char *)malloc(sizeof(char) * (*l + 1));
			if (wrd == NULL)
				return (NULL);
			break ;
		}
		*l += 1;
	}
	ft_strcpy(wrd, s, c, i);
	return (wrd);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		k;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = ft_wordsamount((char *)s, c);
	k = 0;
	res = (char **)malloc(sizeof(char *) * (j + 1));
	if (res == NULL)
		return (NULL);
	res[j] = NULL;
	while (i < j)
	{
		res[i] = ft_alloc(((char *)s), c, &k);
		if (res[i] == NULL)
		{
			ft_freemem(res[i]);
		}
		i++;
	}
	return (res);
}

/*
int	main(void)
{
	const char	*str = "My name is Slim Shady krra";
	char		**result = ft_split(str, ' ');
	int i = 0;
	if(!result)
	{
		printf("Memory allocation failed\n");
		return (1);
	}
	
	printf("Split strings:\n");
	while (result[i] != NULL)
	{
		printf("%s\n", result[i]);
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}
*/