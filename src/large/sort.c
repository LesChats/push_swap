/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <abaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 16:29:44 by abaudot           #+#    #+#             */
/*   Updated: 2021/07/08 11:58:44 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** the max ellement indicate where whe sould stop ours actions
*/
static int	get_limit(t_stack *st, int max)
{
	struct s_frame	*tmp;
	int				i;

	tmp = st->head;
	i = 0;
	while (tmp->item <= max && tmp->item != 0)
	{
		tmp = tmp->next;
		++i;
	}
	return (i);
}

static inline void	reorder_a(t_stack *st)
{
	while (st->head->item == (st->tail->item + 1)
		|| st->head->item == 0)
	{
		if (is_sorted(st))
			break ;
		rx(st, "ra\n");
	}
}

/*
** just empty stack B in a wise maner:
** max element at the top of the stack A, min element a the botom 
of stack A
*/
static void	empty_b(t_stack **st)
{
	while (st[1]->size)
	{
		if (find_max(st[1]) == 0)
			px(st, "pa\n");
		else if (st[1]->head->item == (st[0]->tail->item + 1)
			|| st[1]->head->item == 0)
		{
			px(st, "pa\n");
			rx(st[0], "ra\n");
		}
		else if (find_max(st[0]) <= st[0]->size / 2)
			rrx(st[1], "rrb\n");
		else
			rx(st[1], "rb\n");
	}
	reorder_a(st[0]);
}

/*
** A partition type sorting for stacks
** the stack arrive there already half partionned
*/
void	stack_quicksort(t_stack **st)
{
	const int	max = get_max(st[1]);
	int			limit;

	if (st[1]->size == 0)
		return ;
	if (st[1]->size < EMPTY_STACK)
		return (empty_b(st));
	split_b(st, get_median(st[1], st[1]->size));
	reorder_a(st[0]);
	stack_quicksort(st);
	limit = get_limit(st[0], max);
	if (limit > HALF_SPIT)
		half_split(st, get_median(st[0], limit), max);
	check_split(st, max);
}

void	large_sort(t_stack **st, int *data)
{
	int	limit;
	int	max_a;

	normalize(st[0], data);
	split_a(st, get_median(st[0], st[0]->size));
	stack_quicksort(st);
	max_a = get_max(st[0]);
	limit = get_limit(st[0], max_a);
	if (limit > HALF_SPIT)
	{
		half_split(st, get_median(st[0], limit), max_a);
		max_a = get_max(st[0]);
		half_split(st, get_median(st[0], (limit >> 1) + 1), max_a);
	}
	max_a = get_max(st[0]);
	check_split(st, max_a);
}
