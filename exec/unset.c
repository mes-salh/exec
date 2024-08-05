/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 05:21:15 by mes-salh          #+#    #+#             */
/*   Updated: 2024/08/04 23:38:47 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	search_and_delet(t_env *curr, t_env *prev, t_env **envp, char *word)
{
	while (curr)
	{
		if (ft_strcmp(curr->key, word) == 0)
		{
			if (prev)
				prev->next = curr->next;
			else
				*envp = curr->next;
			ft_lstdelone(curr, free);
			break ;
		}
		prev = curr;
		curr = curr->next;
	}
}

void	unset(t_env **envp, char *arg)
{
	t_env	*curr;
	t_env	*prev;
	char	**words;
	int		i;

	if (!envp || !*envp || !arg)
		return ;
	i = 0;
	words = ft_split(arg, ' ');
	while (words[i])
	{
		if (ft_strcmp(words[i], "_") == 0)
			continue ;
		curr = *envp;
		prev = NULL;
		search_and_delet(curr, prev, envp, words[i]);
		i++;
	}
}
