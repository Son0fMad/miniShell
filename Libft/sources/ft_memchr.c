/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 12:54:16 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 21:34:46 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(void *ptr, int value, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n)
	{
		if (*((unsigned char *)ptr + count) == (unsigned char)value)
			return ((unsigned char *)ptr + count);
		count++;
	}
	return (0);
}
