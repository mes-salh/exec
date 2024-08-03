/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 00:27:38 by mes-salh          #+#    #+#             */
/*   Updated: 2024/08/03 06:02:27 by mes-salh         ###   ########.fr       */
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
	while (env[i])
	{
		splited = ft_split2(env[i], '=');
		ft_lstadd_back(&head, ft_lstnew(splited[0], splited[1]));
		i++;
	}
	return (head);
}

void	printenv(t_env *envp)
{
	int		count;
	t_env	*temp;

	temp = envp;
	count = 0;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	temp = envp;
	while (temp)
	{
		printf("%s=%s\n", temp->key, temp->value);
		temp = temp->next;
	}
}
