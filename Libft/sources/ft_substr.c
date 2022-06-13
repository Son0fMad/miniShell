/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:54:27 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 21:38:55 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	count;
	size_t	str_len;

	count = 0;
	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_strdup(""));
	if (str_len - start <= len)
		substr = (char *)malloc(str_len - start + 1);
	else
		substr = (char *)malloc(len + 1);
	if (!substr)
		return (substr);
	while (count < len && s[start + count] != '\0')
	{
		substr[count] = s[start + count];
		count++;
	}
	substr[count] = '\0';
	return (substr);
}
