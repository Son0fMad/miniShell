/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:38:38 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 21:34:22 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_freemem(char **org, char *str)
{
	int	count;

	count = 0;
	while (org[count])
		free(org[count++]);
	free(org);
	if (str)
		free(str);
	return (1);
}

static char	**ft_dstrappend(char **org, char *app)
{
	char	**buf;
	int		org_size;
	int		count;

	org_size = 0;
	while (org[org_size])
		org_size++;
	buf = (char **)malloc((org_size + 2) * sizeof(char *));
	if (!buf)
		return (NULL);
	count = 0;
	while (org[count])
	{
		buf[count] = org[count];
		count++;
	}
	free(org);
	buf[count] = app;
	buf[count + 1] = NULL;
	return (buf);
}

char	**ft_split(const char *s, char c)
{
	char	**ret;
	char	*new;
	int		count;

	if (!s)
		return (0);
	ret = (char **)ft_calloc(1, sizeof(char *));
	count = 0;
	while (s[count] != '\0')
	{
		if (s[count] != c)
		{
			new = (char *)&s[count];
			while (s[count] != '\0' && s[count] != c)
				count++;
			new = ft_substr(s, new - &s[0], &s[count--] - new);
			if (!new && ft_freemem(ret, NULL))
				return (NULL);
			ret = ft_dstrappend(ret, new);
			if (!ret && ft_freemem(ret, new))
				return (NULL);
		}
		count++;
	}
	return (ret);
}
