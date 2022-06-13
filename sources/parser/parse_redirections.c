/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 00:51:35 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 21:42:13 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <utilities.h>

static int	parse_heredoc(char **str, t_cmds **cur)
{
	int	last;

	last = redirect_size((*cur)->in_dir) - 1;
	(*cur)->in_dir[last]->type = true;
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
		if (char_append(&(*cur)->in_dir[last]->path, **str))
			return (1);
		(*str)++;
	}
	(*str)--;
	return (0);
}

static int	parse_leftfile(char **str, t_cmds **cur)
{
	int	last;

	last = redirect_size((*cur)->in_dir) - 1;
	(*cur)->in_dir[last]->type = false;
	(*str) += 1;
	while (**str == ' ')
		(*str)++;
	while (**str && !ft_strchr(HEREDOCEND, **str))
	{
		if (**str == '\'' || **str == '\"')
		{
			(*str)++;
			continue ;
		}
		if (char_append(&((*cur)->in_dir[last]->path), **str))
			return (1);
		(*str)++;
	}
	(*str)--;
	return (0);
}

int	redirect_size(t_redirect **red)
{
	int	size;

	size = 0;
	while ((red) && (red)[size])
		size++;
	return (size);
}

int	add_redirect(t_redirect ***cur)
{
	int			size;
	t_redirect	**buf;

	buf = (t_redirect **)ft_calloc(redirect_size(*cur) + 2,
			sizeof(t_redirect *));
	if (!buf)
		return (1);
	size = 0;
	while (++size && (*cur) && (*cur)[size - 1])
		buf[size - 1] = (*cur)[size - 1];
	buf[size - 1] = (t_redirect *)ft_calloc(1, sizeof(t_redirect));
	if (!buf[size - 1])
		return (1);
	if (*cur)
		free(*cur);
	*cur = buf;
	return (0);
}

int	parse_redirections(char **str, char **strbuf, t_cmds **cur)
{
	if (*strbuf)
	{
		if (dstring_append(&(*cur)->cmd, *strbuf))
			return (1);
		*strbuf = NULL;
	}
	if (**str == '<')
	{
		if (add_redirect(&(*cur)->in_dir))
			return (1);
		if (*((*str) + 1) == '<')
			return (parse_heredoc(str, cur));
		else
			return (parse_leftfile(str, cur));
	}
	else
		return (parse_redirections_2(str, cur));
	return (0);
}
