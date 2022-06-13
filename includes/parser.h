/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:36:02 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 21:19:35 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <minishell.h>

# define REDIRECTIONS "<>"
# define ENDSTRING "\"\'$"
# define ENDCOMMAND "&|("
# define HEREDOCEND " |&"

t_cmds	*parse(char *str, t_cmds *cur, char *argv);

char	*check_input(char *str, int scope);
int		check_qoute(char **str, char **ret);
int		check_redirections(char **str, char **ret);
int		set_incorrect(char **str, char **ret);

int		parse_qoutes(char **str, char **strbuf);

int		parse_endcommands(char **str, char **strbuf, t_cmds **cur, char *argv);
int		parse_or(char **str, char **strbuf, t_cmds **cur);
int		add_redirect(t_redirect ***cur);

int		redirect_size(t_redirect **red);

int		parse_redirections(char **str, char **strbuf, t_cmds **cur);

int		parse_redirections_2(char **str, t_cmds **cur);

int		parse_arsterix(char **str, char **strbuf, t_cmds **cur);
#endif
