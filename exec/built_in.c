/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 00:27:13 by mes-salh          #+#    #+#             */
/*   Updated: 2024/08/03 06:03:33 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	is_buit_in(char *temp, t_env **envp)
{
	char	*cmd;
	char	*arg;

	split_command(temp, &cmd, &arg);
	if (ft_strcmp(cmd, "env") == 0)
	{
		if (arg != NULL && strlen(arg) > 0)
			printf("%s: No such file or directory\n", arg);
		else
			printenv(*envp);
	}
	else if (ft_strcmp(cmd, "pwd") == 0)
		get_cwd();
	else if (ft_strcmp(cmd, "echo") == 0)
		echo(arg);
	else if (ft_strcmp(cmd, "export") == 0)
		export(envp, arg);
	else if (ft_strcmp(cmd, "unset") == 0)
		unset(envp, arg);
	else if (ft_strcmp(cmd, "cd") == 0)
		if (arg != NULL)
			change_dir(arg);
	free(cmd);
	free(arg);
}
