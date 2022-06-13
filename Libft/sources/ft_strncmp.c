/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:17:17 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 21:38:41 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			count;

	count = 0;
	if (n == 0)
		return (0);
	while (count + 1 < n && str1[count] != '\0' && str1[count] == str2[count])
		count++;
	return (str1[count] - str2[count]);
}
