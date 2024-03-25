/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:29:53 by seckhard          #+#    #+#             */
/*   Updated: 2024/03/25 22:42:26 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env(t_data *data)
{
	int i;

	data->exit_status = 0;
	i = 0;
	while (data->env[i])
	{
		ft_putendl_fd(data->env[i], STDOUT_FILENO);
		i++;
	}
}
