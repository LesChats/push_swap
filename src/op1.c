/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:23:07 by abaudot           #+#    #+#             */
/*   Updated: 2021/06/11 14:28:35 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sx(t_stack *st, const char *out)
{
	if (st->size == 0)
		return ;
	swap(st);
	write(1, out, 3);
}

void	rx(t_stack *st, const char *out)
{
	if (st->size == 0)
		return ;
	head_to_tail(st);
	write(1, out, 3);
}

void	rrx(t_stack *st, const char *out)
{
	if (st->size == 0)
		return ;
	tail_to_head(st);
	write(1, out, 4);
}
