/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 12:54:43 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 21:38:03 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	count;
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	count = 0;
	if (n <= dstlen)
		return (srclen + n);
	while (count + dstlen + 1 < n && src[count])
	{
		dst[dstlen + count] = src[count];
		count++;
	}
	dst[dstlen + count] = '\0';
	return (dstlen + srclen);
}
