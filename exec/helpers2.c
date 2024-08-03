/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 00:49:05 by mes-salh          #+#    #+#             */
/*   Updated: 2024/08/03 05:44:26 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*trim_spaces(const char *str)
{
	const char	*end;
	size_t		len;
	char		*trimmed;

	while (ft_isspace((unsigned char)*str))
		str++;
	if (*str == '\0')
		return (strdup(""));
	end = str + strlen(str) - 1;
	while (end > str && ft_isspace((unsigned char)*end))
		end--;
	len = end - str + 1;
	trimmed = (char *)malloc(len + 1);
	if (!trimmed)
		return (NULL);
	strncpy(trimmed, str, len);
	trimmed[len] = '\0';
	return (trimmed);
}

void	split_command(char *input, char **cmd, char **arg)
{
	char	*trim;
	char	*sp;

	trim = trim_spaces(input);
	sp = strchr(trim, ' ');
	if (sp)
	{
		*sp = '\0';
		*cmd = strdup(trim);
		*arg = strdup(sp + 1);
	}
	else
	{
		*cmd = strdup(trim);
		*arg = NULL;
	}
	free(trim);
}

void	ft_lstdelone(t_env *lst, void (*del)(void*))
{
	if (lst && del)
	{
		del(lst->key);
		del(lst->value);
		free(lst);
	}
}
