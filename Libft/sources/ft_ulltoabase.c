/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoabase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:49:19 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 21:39:29 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_ulltoabase(unsigned long long num, const char *set)
{
	size_t	set_size;
	size_t	pow;
	char	*ret;
	int		count;

	set_size = ft_strlen(set);
	pow = 1;
	while (num / pow >= set_size)
		pow *= set_size;
	ret = (char *)malloc(pow / set_size + 2);
	if (!ret)
		return (NULL);
	count = 0;
	while (++count && pow > 0)
	{
		ret[count - 1] = set[(num / pow) % set_size];
		pow /= set_size;
	}
	ret[count - 1] = '\0';
	return (ret);
}
