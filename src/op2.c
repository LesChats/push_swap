/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:11:31 by abaudot           #+#    #+#             */
/*   Updated: 2021/06/24 19:52:16 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	px(t_stack **sts, const char *out)
{
	const int	dst = out[1] - 'a';
	const int	src = (dst + 1) & 1;

	pop_push(sts[dst], sts[src]);
	write(1, out, 3);
}

void	rr(t_stack **sts)
{
	head_to_tail(sts[0]);
	head_to_tail(sts[1]);
	write(1, "rr\n", 3);
}

void	rrr(t_stack **sts)
{
	tail_to_head(sts[0]);
	tail_to_head(sts[1]);
	write(1, "rrr\n", 4);
}

void	ss(t_stack **sts)
{
	swap(sts[0]);
	swap(sts[1]);
	write(1, "ss\n", 3);
}
