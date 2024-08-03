/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 04:09:55 by mes-salh          #+#    #+#             */
/*   Updated: 2024/08/03 06:18:30 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export(t_env **envp, char *arg)
{
	char	**new;
	t_env	*existing;
	t_env	*temp;

	new = ft_split(arg, '=');
	if (!new || !new[0] || !new[1])
	{
		if (new)
			ft_free(new, -1);
		return ;
	}
	existing = *envp;
	while (existing)
	{
		if (ft_strcmp(existing->key, new[0]) == 0)
		{
			(free(existing->value), existing->value = ft_strdup(new[1])
				, ft_free(new, -1));
			return ;
		}
		existing = existing->next;
	}
	ft_lstadd_back(envp, ft_lstnew(ft_strdup(new[0]), ft_strdup(new[1])));
	ft_free(new, -1);
	temp = *envp;
}
