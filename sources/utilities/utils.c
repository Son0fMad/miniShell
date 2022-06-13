/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 00:15:31 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 21:43:21 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*get_env_val(char **env, char *str)
{
	char	*chr;
	int		c;
	int		l;

	l = ft_strlen(str);
	c = 0;
	while (env[c])
	{
		chr = ft_strchr(env[c], '=');
		if (!strncmp(env[c], str, l) && env[c][l] == '=')
		{
			return (chr + 1);
		}
		c++;
	}
	return ("");
}
