/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 20:13:43 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 21:34:53 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = 0;
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	(*new).content = content;
	(*new).next = 0;
	return (new);
}
