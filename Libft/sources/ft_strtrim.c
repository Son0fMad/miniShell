/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:28:57 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 21:38:47 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	ft_ispartofset(const char c, const char *set)
{
	unsigned int	count;

	count = 0;
	while (set[count] != '\0')
	{
		if (set[count] == c)
			return (1);
		count++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		start;
	int		end;
	char	*ret;
	int		count;

	if (!s1 || !set)
		return (0);
	start = 0;
	while (s1[start] && ft_ispartofset(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && ft_ispartofset(s1[end], set))
		end--;
	ret = 0;
	ret = (char *)malloc(end - start + 2);
	if (!ret)
		return (ret);
	count = 0;
	while (count + start <= end && s1[count + start])
	{
		ret[count] = s1[count + start];
		count++;
	}
	ret[count] = '\0';
	return (ret);
}
