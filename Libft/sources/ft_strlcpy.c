/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 12:54:48 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 21:38:11 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	count;

	if (!dest)
		return (0);
	count = 0;
	while (count + 1 < n && src[count])
	{
		dest[count] = src[count];
		count++;
	}
	if (n)
		dest[count] = '\0';
	return (ft_strlen(src));
}
