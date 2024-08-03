/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 05:21:15 by mes-salh          #+#    #+#             */
/*   Updated: 2024/08/03 06:07:18 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset(t_env **envp, char *arg)
{
	t_env	*curr;
	t_env	*prev;

	if (!envp || !*envp || !arg)
		return ;
	curr = *envp;
	prev = NULL;
	if (ft_strcmp(arg, "_") == 0)
		return ;
	while (curr)
	{
		if (ft_strcmp(curr->key, arg) == 0)
		{
			if (prev)
				prev->next = curr->next;
			else
				*envp = curr->next;
			ft_lstdelone(curr, free);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}
