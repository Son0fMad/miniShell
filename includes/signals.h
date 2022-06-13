/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 20:09:40 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 21:19:06 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include <minishell.h>

void	gsignal_ctlc(int sigtype);
void	fsignal_ctlc(int sigtype);
void	heredoc_ctlc(int sigtype);
int		changetermios(bool toggle);
#endif
