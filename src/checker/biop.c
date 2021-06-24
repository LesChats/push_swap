/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <abaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 15:33:43 by abaudot           #+#    #+#             */
/*   Updated: 2021/06/24 20:10:25 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

char	biswap(t_stack **st)
{
	if (!st[0]->size || !st[1]->size)
		return (0);
	swap(st[0]);
	swap(st[1]);
	return (1);
}

char	bihtt(t_stack **st)
{
	if (!st[0]->size || !st[1]->size)
		return (0);
	head_to_tail(st[0]);
	head_to_tail(st[1]);
	return (1);
}

char	bitth(t_stack **st)
{
	if (!st[0]->size || !st[1]->size)
		return (0);
	tail_to_head(st[0]);
	tail_to_head(st[1]);
	return (1);
}
