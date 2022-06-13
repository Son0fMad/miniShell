/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:24:29 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 21:27:45 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <utilities.h>
#include <env.h>

static char	set_newenv(char *env)
{
	char	**new_env;
	int		i;

	i = 0;
	new_env = NULL;
	while (g_ourenv.env && g_ourenv.env[i])
	{
		if (!(!ft_strncmp(g_ourenv.env[i], env,
					ft_strchr(g_ourenv.env[i], '=') - g_ourenv.env[i])))
		{
			if (dstring_append(&new_env, g_ourenv.env[i]))
				return (1);
		}
		else
			free(g_ourenv.env[i]);
		i++;
	}
	free(g_ourenv.env);
	g_ourenv.env = new_env;
	return (0);
}

int	bt_unset(char **argv)
{
	int	i;

	if (darr_size(argv) >= 2)
	{
		i = 1;
		while (argv[i])
		{
			if (set_newenv(argv[i]))
				return (1);
			i++;
		}
	}
	return (0);
}
