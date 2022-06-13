/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 12:53:16 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 21:34:36 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n)
	{
		*((unsigned char *)str + count) = (unsigned char)c;
		count++;
	}
	return (str);
}
