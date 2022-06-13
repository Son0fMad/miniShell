/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:30:57 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 21:01:32 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utilities.h>

int	strrlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

int	darr_size(char **str)
{
	int	cnt;

	cnt = 0;
	while (str && str[cnt])
		cnt++;
	return (cnt);
}

int	char_append(char **str, char c)
{
	char	*buf;
	int		cnt;

	buf = (char *)malloc(strrlen(*str) + 2);
	if (!buf)
		return (1);
	cnt = 0;
	while (*str && (*str)[cnt])
	{
		buf[cnt] = (*str)[cnt];
		cnt++;
	}
	buf[cnt] = c;
	buf[cnt + 1] = '\0';
	if (*str)
		free(*str);
	*str = buf;
	return (0);
}

int	dstring_append(char ***org, char *str)
{
	char	**buf;
	int		cnt;

	buf = (char **)malloc((darr_size(*org) + 2) * sizeof(char *));
	if (!buf)
		return (1);
	cnt = 0;
	while (*org && (*org)[cnt])
	{
		buf[cnt] = (*org)[cnt];
		cnt++;
	}
	buf[cnt] = str;
	buf[cnt + 1] = NULL;
	if (*org)
		free(*org);
	*org = buf;
	return (0);
}

int	string_append(char **org, char *str)
{
	char	*buf;
	int		cnt;
	int		cnt2;

	buf = (char *)ft_calloc(1, strrlen(*org) + strrlen(str) + 2);
	if (!buf)
		return (1);
	cnt = 0;
	cnt2 = 0;
	while (*org && (*org)[cnt])
	{
		buf[cnt] = (*org)[cnt];
		cnt++;
	}
	cnt2 = cnt;
	while (str && str[cnt - cnt2])
	{
		buf[cnt] = str[cnt - cnt2];
		cnt++;
	}
	if (*org)
		free(*org);
	*org = buf;
	return (0);
}
