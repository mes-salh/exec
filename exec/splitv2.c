/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitv2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:07:33 by mes-salh          #+#    #+#             */
/*   Updated: 2024/08/04 01:12:23 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_split2(char *s, char c)
{
	char	**result;
	char	*pos;

	if (!s)
		return (NULL);
	pos = ft_strchr(s, c);
	if (!pos)
		return (NULL);
	result = (char **)malloc(3 * sizeof(char *));
	if (!result)
		return (NULL);
	result[0] = ft_strndup(s, pos - s);
	result[1] = ft_strdup(pos + 1);
	result[2] = NULL;
	return (result);
}
