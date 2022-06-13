/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 20:05:32 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 21:20:01 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include <libft.h>
# include <minishell.h>
# include <signal.h>

# define PIPE_ERR 2
# define MALLOC_ERR 3
# define FORK_ERR 4

typedef struct s_execute
{
	t_list		*lst;
	int			s_fd;
	int			fd[2];
	int			exit;
	int			s_in;
	int			s_out;
}	t_execute;

typedef struct s_pid
{
	int	pid;
	int	exit;
}	t_pid;

unsigned char	execute(t_cmds *data);
int				find_command(char *arg, char **str, char **env);
void			ft_wait(void *pid);
int				check_builtin(t_cmds *cmd, t_execute *exec);
void			collect_garbage(t_execute *exec);
int				execute_errors(int ret, t_execute *exec);
void			check_operators(t_cmds **data, t_execute *exec);
int				execute_child_erros(int ret, t_execute *exec, t_cmds *data);
int				redirect(t_cmds *data, t_execute *exec);
void			update_env(t_cmds *cmds);
int				check_builtin_main(t_cmds *cmd, t_execute *exec);
int				exec_in_main(t_execute *exec, t_cmds *cmd);
int				create_childs(t_cmds *data, t_execute *exec);
int				is_builtin(char *cmd);
int				has_heredoc(t_cmds *data);
void			wait_for_real(t_list *lst, t_execute *exec);
#endif
