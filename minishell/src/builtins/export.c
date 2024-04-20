/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:13:47 by bszabo            #+#    #+#             */
/*   Updated: 2024/04/20 14:53:07 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// get the name of the environment variable
static char	*get_var_name(char *env_var)
{
	int		i;
	char	*name;

	i = 0;
	while (env_var[i] && env_var[i] != '=')
		i++;
	name = ft_substr(env_var, 0, i);
	if (name == NULL)
		err_msg("ft_substr failed");
	return (name);
}

// check if the environment variable is valid
// (only letters and underscores are allowed, cannot start with a digit)
static int	check_env_var(char *env_var, t_data *data)
{
	int	i;

	i = 0;
	while (env_var[i] && env_var[i] != '=')
	{
		if (i == 0 && ft_isdigit(env_var[i]))
		{
			data->exit_status = 1;
			return (err_msg3("export", env_var, "not a valid identifier"),
				ERROR);
		}
		else if (!ft_isalnum(env_var[i]) && env_var[i] != '_')
		{
			data->exit_status = 1;
			return (err_msg3("export", env_var, "not a valid identifier"),
				ERROR);
		}
		i++;
	}
	if (env_var[i] == '\0')
		return (ERROR);
	return (OK);
}

// check if there is a flag after the export command
// (our minishell does not support flags for the export command)
static int	check_flag(char *env_var, int j, t_data *data)
{
	char	*substr;

	substr = NULL;
	if (j == 1 && env_var[0] == '-' && env_var[1])
	{
		substr = ft_substr(env_var, 0, 2);
		if (substr == NULL)
			err_msg("ft_substr failed");
		err_msg3("export", substr, "invalid option");
		data->exit_status = 2;
		free(substr);
		return (ERROR);
	}
	return (OK);
}

// handle the export command
// if the environment variable is valid, add it to the env or update it
static void	handle_export(t_data *data, int j, char *env_var)
{
	char	*name;
	char	*value;

	env_var = remove_quotes(env_var);
	if (check_flag(env_var, j, data) == ERROR)
		return ;
	if (check_env_var(env_var, data) == ERROR)
		return ;
	name = get_var_name(env_var);
	value = ft_strchr(env_var, '=') + 1;
	if (ms_getenv_index(data, name) == ERROR)
		ms_addenv(name, value, data);
	else
		ms_setenv(name, value, data);
	free(name);
}

// export the environment variable to the data structure env
// example: export VAR_NAME=VAR_VALUE will add VAR_NAME=VAR_VALUE to the env
void	ms_export(t_data *data, int i)
{
	char	**export_arg;
	int		j;

	data->exit_status = 0;
	export_arg = data->cmds[i]->cmd_array;
	j = 1;
	if (i == 0 && data->cmd_count == 1)
	{
		while (export_arg[j])
		{
			handle_export(data, j, export_arg[j]);
			j++;
		}
	}
}
