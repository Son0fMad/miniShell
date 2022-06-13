/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_endcommand_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 20:44:21 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 20:59:27 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <utilities.h>

int	parse_or(char **str, char **strbuf, t_cmds **cur)
{
	if (*strbuf)
	{
		if (dstring_append(&(*cur)->cmd, *strbuf))
			return (1);
		*strbuf = NULL;
	}
	if ((*cur)->cmd)
		(*cur)->operators = OPERATORS_OR;
	if ((*cur)->cmd && append_list(cur))
		return (1);
	if ((*cur)->previous)
		(*cur)->previous->operators = OPERATORS_OR;
	*str += 1;
	return (0);
}
