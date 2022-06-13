/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 21:05:40 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 21:35:11 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_back(t_list **lst, t_list *toadd)
{
	t_list	*lstbuf;

	if (!lst || !toadd)
		return ;
	if (!(*lst))
	{
		*lst = toadd;
		return ;
	}
	lstbuf = *lst;
	while (lstbuf->next)
		lstbuf = lstbuf->next;
	lstbuf->next = toadd;
}
