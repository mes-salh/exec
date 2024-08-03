/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 01:31:43 by mes-salh          #+#    #+#             */
/*   Updated: 2024/08/03 03:31:39 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo(char *arg)
{
	int	skip_newline;

	skip_newline = 0;
	while (ft_strncmp(arg, "-n", 2) == 0)
	{
		arg += 2;
		skip_newline = 1;
		while (*arg == ' ')
			arg++;
	}
	if (*arg != '\0')
		printf("%s", arg);
	if (!skip_newline)
		printf("\n");
}
