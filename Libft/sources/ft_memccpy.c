/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 12:53:35 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 21:34:48 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n)
	{
		*((unsigned char *)dest + count) = *((unsigned char *)src + count);
		if (*((unsigned char *)src + count) == (unsigned char)c)
		{
			return ((unsigned char *)dest + count + 1);
		}
		count++;
	}
	return (0);
}
