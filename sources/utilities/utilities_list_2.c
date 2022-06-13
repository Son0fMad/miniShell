/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_list_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:30:47 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 21:01:01 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utilities.h>

t_cmds	*find_last(t_cmds *node)
{
	while (node->next != NULL)
		node = node->next;
	return (node);
}

t_cmds	*find_listhead(t_cmds *node)
{
	while (node && node->previous)
		node = node->previous;
	return (node);
}
