/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 12:54:39 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 21:36:57 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(char *str, int chr)
{
	while (*str != '\0')
	{
		if (*str == (char) chr)
			return (str);
		str++;
	}
	if (*str == (char) chr)
		return (str);
	else
		return (0);
}
