/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   siop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <abaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 15:04:10 by abaudot           #+#    #+#             */
/*   Updated: 2021/06/12 15:39:53 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

char	sswap(t_stack *st)
{
	if (st->size == 0)
		return (0);
	swap(st);
	return (1);
}

char	shtt(t_stack *st)
{
	if (st->size == 0)
		return (0);
	head_to_tail(st);
	return (1);
}

char	stth(t_stack *st)
{
	if (st->size == 0)
		return (0);
	tail_to_head(st);
	return (1);
}

char	spp(t_stack *dst, t_stack *src)
{
	if (src->size == 0)
		return (0);
	pop_push(dst, src);
	return (1);
}
