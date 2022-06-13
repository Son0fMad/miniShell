/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:22:45 by jsiller           #+#    #+#             */
/*   Updated: 2022/04/16 21:40:47 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <utilities.h>
#include <libft.h>

static void	ft_check_if_int(char **argv, int *ret)
{
	int	c;

	c = 0;
	*ret = 0;
	while (darr_size(argv) >= 2 && argv[1][c])
	{
		if (!ft_isdigit(argv[1][c]) && argv[1][c] != '-' && argv[1][c] != '+')
		{
			*ret = 255;
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd("exit: ", 2);
			ft_putstr_fd(argv[1], 2);
			ft_putstr_fd(": numeric arguement required\n", 2);
			break ;
		}
		c++;
	}
}

int	bt_exit(char **argv)
{
	int	ret;

	ft_check_if_int(argv, &ret);
	if (darr_size(argv) > 2 && ret != 255)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd("exit: too many arguements\n", 2);
		return (1);
	}
	clear_history();
	if (darr_size(argv) == 2 && ret != 255)
		ret = ft_atoi(argv[1]);
	ft_putstr_fd("exit\n", 2);
	exit(ret);
	return (0);
}
