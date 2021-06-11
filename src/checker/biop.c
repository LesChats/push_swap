/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 17:05:31 by abaudot           #+#    #+#             */
/*   Updated: 2021/06/11 17:10:48 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	biswap(t_stack **st)
{
	swap(st[0]);
	swap(st[1]);
}

void	bihtt(t_stack **st)
{
		head_to_tail(st[0]);
		head_to_tail(st[1]);
}

void bitth(t_stack **st)
{
	tail_to_head(st[0]);
	tail_to_head(st[1]);
}


