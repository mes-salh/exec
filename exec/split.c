/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:36:07 by mes-salh          #+#    #+#             */
/*   Updated: 2024/08/02 02:43:33 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	wcount(char *s, char c)
{
	int	count;

	count = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && (*s != c))
				s++;
		}
		else
			s++;
	}
	return (count);
}

char	*ft_strndup(char *src, int n)
{
	int		i;
	char	*r;

	r = (char *)malloc(n + 1);
	if (!r)
		return (NULL);
	i = 0;
	while (src[i] && i < n)
	{
		r[i] = src[i];
		i++;
	}
	r[i] = '\0';
	return (r);
}

void	ft_free(char **ptr, int i)
{
	while (i >= 0)
	{
		free(ptr[i]);
		i--;
	}
	free(ptr);
}

char	**ft_helper(char *s, char c, int lenght, char **last)
{
	char	*st;
	int		i;

	lenght = wcount(s, c);
	last = (char **)malloc((lenght + 1) * sizeof(char *));
	if (!last)
		return (NULL);
	i = 0;
	while (i < lenght)
	{
		while (*s == c)
			s++;
		st = (char *)s;
		while (*s && *s != c)
			s++;
		last[i] = ft_strndup(st, s - st);
		if (!last[i])
		{
			ft_free(last, i);
			return (NULL);
		}
		i++;
	}
	last[i] = NULL;
	return (last);
}

char	**ft_split(char *s, char c)
{
	int		lenght;
	char	**last;

	last = NULL;
	lenght = 0;
	return (ft_helper(s, c, lenght, last));
}
