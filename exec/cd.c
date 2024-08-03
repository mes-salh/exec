/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 23:43:08 by mes-salh          #+#    #+#             */
/*   Updated: 2024/08/03 01:01:08 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_dir(char *temp)
{
	char	*path;

	if (ft_strncmp(temp, "cd ", 3) == 0)
		temp += 3;
	if (strcmp(temp, "~") == 0)
		path = getenv("HOME");
	else if (strcmp(temp, "-") == 0)
		path = getenv("OLDPWD");
	else
		path = ft_strdup(temp);
	if (!path || *path == '\0')
	{
		if (path)
			free(path);
		fprintf(stderr, "cd: Invalid directory\n");
		return ;
	}
	if (chdir(path) != 0)
		fprintf(stderr, "cd: %s: No such file or directory\n", path);
	if (path != getenv("HOME") && path != getenv("OLDPWD"))
		free(path);
}
