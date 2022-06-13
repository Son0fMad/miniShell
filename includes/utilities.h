/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:36:04 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 21:45:04 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H

# include <minishell.h>

/*
** list functions
*/

int		clear_list(t_cmds *node, int ret);
int		append_list(t_cmds **node);
t_cmds	*delete_node(t_cmds *node);
t_cmds	*find_listhead(t_cmds *node);
t_cmds	*find_last(t_cmds *node);

/*
** string functions
*/

int		char_append(char **str, char c);
int		dstring_append(char ***org, char *str);
int		string_append(char **org, char *str);
int		strrlen(char *str);
int		darr_size(char **str);

/*
** env suff
*/

char	*get_env_value(char *str);
int		free_env(void);

#endif
