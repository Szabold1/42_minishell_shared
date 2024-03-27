/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 22:02:33 by seckhard          #+#    #+#             */
/*   Updated: 2024/03/27 23:11:48 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	flag_check(char *input)
{
	if (!input || *input != '-')
		return (ERROR);
	input++;
	while (*input)
	{
		if (*input != 'n')
			return (ERROR);
		input++;
	}
	return (OK);
}

void	echo(t_data *data, t_cmd *cmd)
{
	int i;
	int nl;

	i = 1;
	nl = flag_check(cmd->cmd_array[1]);
	while (flag_check(cmd->cmd_array[i]) == 0)
		i++;
	while (i < cmd->argc)
	{
		printf("%s", cmd->cmd_array[i]);
		if (i != cmd->argc)
			printf(" ");
		i++;
	}
	if (nl)
		printf("\n");
	data->exit_status = 0;
}
