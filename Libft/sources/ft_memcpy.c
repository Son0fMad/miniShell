/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 12:54:33 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 21:34:41 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	count;

	if (!dest && !src)
		return (0);
	count = 0;
	while (count < n)
	{
		*((unsigned char *)dest + count) = *((unsigned char *)src + count);
		count++;
	}
	return (dest);
}
