/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:52:23 by seckhard          #+#    #+#             */
/*   Updated: 2024/03/25 22:46:49 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int change_dir(t_data *data, char *path, char *pwd)
{
	if (chdir(path) == -1)
	{
		
	}
}

int	cd(t_data *data, t_cmd commands)
{
	
}
