/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 10:37:13 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 21:38:26 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	count;
	char			*ret;

	if (!s || !f)
		return (0);
	ret = (char *)ft_strdup(s);
	if (!ret)
		return (0);
	count = 0;
	while (ret[count])
	{
		ret[count] = f(count, ret[count]);
		count++;
	}
	return (ret);
}
