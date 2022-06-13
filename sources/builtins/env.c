/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:22:01 by  dcloud           #+#    #+#             */
/*   Updated: 2022/04/16 21:26:04 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	bt_env(char **argv)
{
	int	i;

	i = 0;
	if (!g_ourenv.env)
	{
		ft_putstr_fd("minishell: env: env is empty\n", 2);
		return (1);
	}
	while (g_ourenv.env[i])
	{
		printf("%s\n", g_ourenv.env[i]);
		i++;
	}
	return (0);
	(void)argv;
}
