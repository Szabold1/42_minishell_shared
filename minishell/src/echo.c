/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 22:02:33 by seckhard          #+#    #+#             */
/*   Updated: 2024/03/26 22:30:37 by seckhard         ###   ########.fr       */
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
		if (input != 'n')
			return (ERROR);
		input++;
	}
	return (OK);
}

void	echo(t_data *data, t_cmd *command)
{
	
}
