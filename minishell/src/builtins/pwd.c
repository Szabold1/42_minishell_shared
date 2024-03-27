/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:10:57 by seckhard          #+#    #+#             */
/*   Updated: 2024/03/27 20:46:51 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// pwd = "print working directory"
int	get_pwd(t_data *data)
{
	char	*tmp;

	data->exit_status = 0;
	tmp = getcwd(NULL, 0);
	if (!tmp)
		exit(ERROR);
	printf("%s\n", tmp);
	free(tmp);
	return (OK);
}
