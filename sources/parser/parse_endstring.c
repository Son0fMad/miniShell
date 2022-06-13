/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_endstring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 00:51:31 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 20:59:57 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <utilities.h>

static int	parse_variable2(char **str,
		char **strbuf, char **var_name, char **variable)
{
	if (!*var_name && *(*str + 1) == '?')
	{
		(*str)++;
		*variable = ft_itoa(g_ourenv.exit_status);
		if (!(*variable))
			return (1);
		if (string_append(strbuf, *variable))
			return (1);
	}
	else if (*var_name)
	{
		if (get_env_value(*var_name))
			*variable = ft_strdup(get_env_value(*var_name));
		else
			char_append(variable, '\0');
		free(*var_name);
		if (!(*variable))
			return (1);
		if (string_append(strbuf, *variable))
			return (1);
	}
	free(*variable);
	return (0);
}

static int	parse_variable(char **str, char **strbuf)
{
	char	*var_name;
	char	*variable;

	var_name = NULL;
	variable = NULL;
	(*str)++;
	if (**str && ft_strchr("\'\"", **str) && (*str)--)
		return (0);
	while ((**str == '_' || ft_isalnum(**str)) && **str)
	{
		if (char_append(&var_name, **str))
			return (1);
		(*str)++;
	}
	--(*str);
	return (parse_variable2(str, strbuf, &var_name, &variable));
}

static int	parse_double(char **str, char **strbuf)
{
	(*str)++;
	if (char_append(strbuf, '\0'))
		return (1);
	while (**str != '\"')
	{
		if (**str == '\0')
			return (1);
		else if (**str != '$' && char_append(strbuf, **str))
			return (1);
		else if (**str == '$' && parse_variable(str, strbuf))
			return (1);
		(*str)++;
	}
	return (0);
}

static int	parse_single(char **str, char **strbuf)
{
	(*str)++;
	if (char_append(strbuf, '\0'))
		return (1);
	while (**str != '\'')
	{
		if (**str == '\0')
			return (1);
		else if (char_append(strbuf, **str))
			return (1);
		(*str)++;
	}
	return (0);
}

int	parse_qoutes(char **str, char **strbuf)
{
	if (**str == '\'')
		return (parse_single(str, strbuf));
	else if (**str == '\"')
		return (parse_double(str, strbuf));
	else
		return (parse_variable(str, strbuf));
}
