/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 00:27:38 by mes-salh          #+#    #+#             */
/*   Updated: 2024/08/04 23:09:22 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*envinit(char **env)
{
	t_env	*head;
	int		i;
	char	**splited;

	i = 0;
	head = NULL;
	if (!*env)
	{
		ft_lstadd_back(&head, ft_lstnew("PWD", "/"));
		ft_lstadd_back(&head, ft_lstnew("SHLVL", "1"));
		ft_lstadd_back(&head, ft_lstnew("_", "usr/bin/env"));
		return (head);
	}
	while (env[i])
	{
		splited = ft_split2(env[i], '=');
		ft_lstadd_back(&head, ft_lstnew(splited[0], splited[1]));
		ft_free(splited, 2);
		i++;
	}
	return (head);
}

void	printenv(t_env *envp)
{
	t_env	*temp;

	temp = envp;
	while (temp)
	{
		printf("%s=%s\n", temp->key, temp->value);
		temp = temp->next;
	}
}
