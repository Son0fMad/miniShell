/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:49:22 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 21:20:31 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <minishell.h>

typedef struct s_builtins
{
	char	*name;
	int		(*func)(char **argv);
}	t_builtins;

int	bt_echo(char **argv);
int	bt_cd(char **argv);
int	bt_env(char **argv);
int	bt_exit(char **argv);
int	bt_export(char **argv);
int	bt_unset(char **argv);
int	bt_pwd(char **argv);
int	bt_true(char **argv);
int	bt_false(char **argv);
#endif
