/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:26:38 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 20:58:23 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <utilities.h>

int	check_qoute(char **str, char **ret)
{
	(*str)++;
	if (*(*str - 1) == '\'')
	{
		while (**str && **str != '\'')
			(*str)++;
		if (!**str)
			char_append(ret, '\'');
	}
	else if (*(*str - 1) == '\"')
	{
		while (**str && **str != '\"')
			(*str)++;
		if (!**str)
			char_append(ret, '\"');
	}
	if (*ret)
		return (1);
	return (0);
}

int	check_redirections(char **str, char **ret)
{
	(*str)++;
	if (**str == *(*str - 1))
		(*str)++;
	while (ft_isspace(**str))
		(*str)++;
	if (!**str)
	{
		*ret = ft_strdup("newline");
		return (1);
	}
	if (ft_strchr(ENDCOMMAND, **str) || ft_strchr(REDIRECTIONS, **str))
	{
		char_append(ret, **str);
		if ((**str == '&' || **str == '|') && *(*str + 1) == **str)
			char_append(ret, **str);
		return (1);
	}
	return (0);
}

static void	set_incorrect_2(char **str, char **ret)
{
	while (**str && !ft_strchr(ENDCOMMAND, **str)
		&& !(ft_strchr(ENDSTRING, **str) && **str != '$')
		&& **str != ')' && !ft_isspace(**str))
	{
		char_append(ret, **str);
		(*str)++;
	}
}

int	set_incorrect(char **str, char **ret)
{
	char	qt;

	(*str)++;
	while (ft_isspace(**str))
		(*str)++;
	if (ft_strchr(ENDCOMMAND, **str))
	{
		char_append(ret, **str);
		if (ft_strchr(ENDCOMMAND, *(*str + 1)))
			char_append(ret, **str);
	}
	else if (**str == '\"' || **str == '\'')
	{
		qt = **str;
		char_append(ret, **str);
		while (*(++(*str)) && **str != qt)
			char_append(ret, **str);
		char_append(ret, **str);
	}
	else
		set_incorrect_2(str, ret);
	(*str)--;
	return (1);
}
