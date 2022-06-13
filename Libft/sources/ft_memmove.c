/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 12:54:11 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 21:34:38 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			count;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!src && !dest)
		return (0);
	count = 0;
	if (src > dest)
	{
		while (++count && (count - 1) < n)
			*(d + (count - 1)) = *(s + (count - 1));
	}
	else
	{
		d += (n);
		s += (n);
		while (++count && count <= n)
			*(d - count) = *(s - count);
	}
	return (dest);
}
