/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:58:54 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 21:36:03 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*buf;
	size_t	count;

	count = 0;
	buf = 0;
	buf = malloc(num * size);
	if (!buf)
		return (0);
	while (count < num * size)
	{
		*((unsigned char *)buf + count) = 0;
		count++;
	}
	return (buf);
}
