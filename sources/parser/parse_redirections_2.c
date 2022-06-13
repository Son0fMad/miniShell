/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirections_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 22:26:08 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 21:00:08 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <utilities.h>

static int	parse_rightheredoc(char **str, t_cmds **cur)
{
	int	last;

	last = redirect_size((*cur)->out_dir) - 1;
	(*cur)->out_dir[last]->type = true;
	(*str) += 2;
	while (**str == ' ')
		(*str)++;
	while (!ft_strchr(HEREDOCEND, **str))
	{
		if (**str == '\'' || **str == '\"')
		{
			(*str)++;
			continue ;
		}
		if (char_append(&(*cur)->out_dir[last]->path, **str))
			return (1);
		(*str)++;
	}
	(*str)--;
	return (0);
}

static int	parse_rightfile(char **str, t_cmds **cur)
{
	int	last;

	last = redirect_size((*cur)->out_dir) - 1;
	(*cur)->out_dir[last]->type = false;
	(*str) += 1;
	while (**str == ' ')
		(*str)++;
	while (!ft_strchr(HEREDOCEND, **str))
	{
		if (**str == '\'' || **str == '\"')
		{
			(*str)++;
			continue ;
		}
		if (char_append(&(*cur)->out_dir[last]->path, **str))
			return (1);
		(*str)++;
	}
	(*str)--;
	return (0);
}

int	parse_redirections_2(char **str, t_cmds **cur)
{
	if (add_redirect(&(*cur)->out_dir))
		return (1);
	if (*((*str) + 1) == '>')
		return (parse_rightheredoc(str, cur));
	else
		return (parse_rightfile(str, cur));
}
