/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 04:09:55 by mes-salh          #+#    #+#             */
/*   Updated: 2024/08/05 22:50:22 by mes-salh         ###   ########.fr       */
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

void	export_notargs(t_env **envp)
{
	t_env	*temp;

	temp = *envp;
	export_sort_alpha(&temp);
	while (temp)
	{
		if (temp->value)
			printf("declare -x %s=\"%s\"\n", temp->key, temp->value);
		else
			printf("declare -x %s\n", temp->key);
		temp = temp->next;
	}
}

void	export_sort_alpha(t_env **envp)
{
	t_env	*temp;
	t_env	*temp2;
	char	*key;
	char	*value;

	temp = *envp;
	while (temp)
	{
		temp2 = temp->next;
		while (temp2)
		{
			if (ft_strcmp(temp->key, temp2->key) > 0)
			{
				key = temp->key;
				value = temp->value;
				temp->key = temp2->key;
				temp->value = temp2->value;
				temp2->key = key;
				temp2->value = value;
			}
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
}
