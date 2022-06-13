/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:09:19 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 21:37:12 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *str)
{
	char	*copy;
	int		c;

	c = 0;
	while (str[c] != '\0')
		c++;
	copy = 0;
	copy = (char *)malloc(c + 1);
	if (!copy)
		return (0);
	c = 0;
	while (str[c] != '\0')
	{
		copy[c] = str[c];
		c++;
	}
	copy[c] = str[c];
	return (copy);
}
