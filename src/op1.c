/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <abaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 18:15:58 by abaudot           #+#    #+#             */
/*   Updated: 2021/06/23 18:16:00 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sx(t_stack *st, const char *out)
{
	swap(st);
	write(1, out, 3);
}

void	rx(t_stack *st, const char *out)
{
	head_to_tail(st);
	write(1, out, 3);
}

void	rrx(t_stack *st, const char *out)
{
	tail_to_head(st);
	write(1, out, 4);
}
