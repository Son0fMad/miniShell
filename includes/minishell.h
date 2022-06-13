/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:35:59 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 21:45:14 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <libft.h>
# include <termios.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <dirent.h>

# define OPERATORS_NONE 0
# define OPERATORS_OR 1
# define OPERATORS_AND 2

typedef struct s_redirect
{
	bool	type;
	char	*path;
}	t_redirect;

typedef struct s_cmds
{
	char			**cmd;
	bool			read;
	bool			write;
	int				scope;
	int				operators;
	int				exit_status;
	t_redirect		**in_dir;
	t_redirect		**out_dir;
	struct s_cmds	*previous;
	struct s_cmds	*next;
	char			*str;
}	t_cmds;

typedef struct s_variables
{
	char			**env;
	unsigned char	exit_status;
}	t_variables;

t_variables	g_ourenv;

void	exit_free(t_cmds *cmd, char *str, bool status);

#endif
