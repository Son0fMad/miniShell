/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_asterix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:30:07 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 20:59:12 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <minishell.h>
#include <utilities.h>

static int	includepath(char *path, char *key)
{
	char	*star;
	char	*old;

	star = ft_strchr(key, '*');
	if (ft_strncmp(path, key, star - key))
		return (0);
	path += star - key;
	star = ft_strchr(key, '*');
	old = star + 1;
	star = ft_strchr(old, '*');
	while (star)
	{
		*star = '\0';
		path = ft_strnstr(path, old, ft_strlen(path));
		*star = '*';
		if (!path)
			return (0);
		old = star + 1;
		star = ft_strchr(old, '*');
	}
	star = ft_strrchr(key, '*') + 1;
	if (ft_strncmp((path + ft_strlen(path)
				- ft_strlen(star)), star, ft_strlen(path)))
		return (0);
	return (1);
}

static int	do_directory(char *key, t_cmds **cur, int *amount)
{
	DIR				*dir;
	struct dirent	*dirent;

	dir = opendir("./");
	if (!dir)
		perror("minishell");
	if (!dir)
		return (1);
	dirent = readdir(dir);
	while (dirent)
	{
		if (ft_strncmp(dirent->d_name, ".", 1)
			&& includepath(dirent->d_name, key))
			if (++(*amount) && dstring_append(&(*cur)->cmd,
					ft_strdup(dirent->d_name)))
				return (1);
		dirent = readdir(dir);
	}
	closedir(dir);
	return (0);
}

int	parse_arsterix(char **str, char **strbuf, t_cmds **cur)
{
	int				amount;

	amount = 0;
	while (**str && !ft_strchr(ENDCOMMAND, **str) && **str != ' ')
	{
		if (ft_strchr(ENDSTRING, **str))
			parse_qoutes(str, strbuf);
		else if (char_append(strbuf, **str))
			return (1);
		(*str)++;
	}
	if (do_directory(*strbuf, cur, &amount))
		return (1);
	if (amount > 0)
	{
		free(*strbuf);
		*strbuf = NULL;
	}
	(*str)--;
	return (0);
}
