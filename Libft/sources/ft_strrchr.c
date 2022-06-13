/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 12:54:56 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 21:26:37 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *str, int chr)
{
	char	*found;
	int		count;

	count = 0;
	found = 0;
	while (str[count] != '\0')
	{
		if (str[count] == (char) chr)
			found = (char *)&str[count];
		count++;
	}
	if (str[count] == (char) chr)
		found = (char *)&str[count];
	return (found);
}
