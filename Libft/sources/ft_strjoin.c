/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:54:15 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 21:37:24 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	unsigned int	s1len;
	unsigned int	s2len;
	char			*new;
	unsigned int	count;

	if (!s1 || !s2)
		return (0);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	new = 0;
	new = (char *)malloc(s2len + s1len + 1);
	if (new == 0)
		return (new);
	count = 0;
	while (++count && (count - 1) < s1len)
		new[count - 1] = s1[count - 1];
	while ((count - 1) < s2len + s1len)
	{
		new[count - 1] = s2[count - 1 - s1len];
		count++;
	}
	new[count - 1] = '\0';
	return (new);
}
