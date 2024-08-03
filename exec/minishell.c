/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:56:08 by mes-salh          #+#    #+#             */
/*   Updated: 2024/08/03 04:48:10 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec(char *temp, char **env)
{
	static t_env	*envp = NULL;

	if (!envp)
		envp = envinit(env);
	is_buit_in(temp, &envp);
}

int	main(int ac, char **av, char **env)
{
	char	*temp;

	(void)av;
	if (ac > 1)
		return (1);
	while (1)
	{
		temp = readline("PLAYZA: ");
		if (!temp)
			exit(EXIT_FAILURE);
		add_history(temp);
		exec(temp, env);
		free(temp);
	}
}
