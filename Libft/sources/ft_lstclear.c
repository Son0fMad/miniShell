/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 21:05:50 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 21:35:06 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lstbuf;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		lstbuf = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = lstbuf;
	}
	lst = 0;
}
