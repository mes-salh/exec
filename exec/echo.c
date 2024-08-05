/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 01:31:43 by mes-salh          #+#    #+#             */
/*   Updated: 2024/08/03 23:15:09 by mes-salh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include "minishell.h"

static int	is_n_flag(const char *str)
{
	if (*str != '-')
		return (0);
	str++;
	while (*str == 'n')
		str++;
	return (*str == '\0' || *str == ' ');
}

void	echo(char *arg)
{
	int	skip_newline;

	skip_newline = 0;
	if (!arg)
	{
		printf("\n");
		return ;
	}
	while (*arg == ' ')
		arg++;
	while (is_n_flag(arg))
	{
		skip_newline = 1;
		while (*arg != ' ' && *arg != '\0')
			arg++;
		while (*arg == ' ')
			arg++;
	}
	if (*arg != '\0')
		printf("%s", arg);
	if (!skip_newline)
		printf("\n");
}
