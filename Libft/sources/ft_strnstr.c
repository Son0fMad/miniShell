/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:07:41 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 21:38:35 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	char	*found;
	size_t	count;
	size_t	count2;

	count = 0;
	found = 0;
	if (ft_strlen(str2) == 0)
		return ((char *)str1);
	while (count < n && str1[count] != '\0')
	{
		if (str1[count] == str2[0])
		{
			count2 = 0;
			while (count + count2 < n && str1[count + count2] == str2[count2])
			{
				count2++;
				if (str2[count2] == '\0')
					return ((char *)&str1[count]);
			}
		}
		count++;
	}
	return (0);
}
