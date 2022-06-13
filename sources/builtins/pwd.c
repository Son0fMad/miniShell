/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:26:42 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 21:27:14 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	bt_pwd(char **argv)
{
	char	str[4096];

	if (!getcwd(str, 4096))
	{
		perror("minishell");
		return (1);
	}
	printf("%s\n", str);
	return (0);
	(void)argv;
}
