/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 00:49:05 by mes-salh          #+#    #+#             */
/*   Updated: 2024/08/05 05:12:13 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	lens;
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	lens = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(lens + 1);
	if (!str)
		return (NULL);
	while (s1[j] != '\0')
		str[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

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
