/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slice.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:20:54 by abaudot           #+#    #+#             */
/*   Updated: 2021/07/04 18:30:49 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	indice(const t_stack *st, int *res)
{
	struct s_frame	*tmp_i;
	struct s_frame	*tmp_j;
	int				i;
	int				j;

	tmp_i = st->head;
	i = 0;
	while (i < st->size)
	{
		res[i] = 0;
		tmp_j = tmp_i->prev;
		j = i - 1;
		while (j >= 0)
		{
			if (tmp_j->item < tmp_i->item && res[j] + 1 > res[i])
				res[i] = res[j] + 1;
			tmp_j = tmp_j->prev;
			--j;
		}
		++i;
		tmp_i = tmp_i->next;
	}
	return (maxin(res, st->size));
}

static void	build_array(const t_stack *st, t_array *r)
{
	struct s_frame	*t;
	int				*keys;
	int				tmp;
	int				i;

	keys = (int *)malloc(sizeof(int) * st->size);
	tmp = indice(st, keys);
	t = st->tail;
	i = st->size - 1;
	r->size = 0;
	while (i >= 0)
	{
		if (tmp == keys[i] && (r->size == 0 || t->item < r->data[r->size - 1]))
		{
			r->data[r->size] = t->item;
			tmp -= 1;
			++r->size;
		}
		t = t->prev;
		i--;
	}
	free(keys);
}
//bug found by JO42 <3 much love. int --> int64_t // float --> double 
static char	interpolation_srch(const t_array *arr, const int64_t item)
{
	const int	*data = arr->data;
	int64_t		low;
	int64_t		high;
	int64_t		mid;

	low = 0;
	high = arr->size - 1;
	while (data[high] != data[low] && item <= data[low] && item >= data[high])
	{
		mid = low
			 + ((double)(high - low) / (data[high] - data[low]))
			 * (item - data[low]);
		if (data[mid] > item)
			low = mid + 1;
		else if (item > data[mid])
			high = mid - 1;
		else
			return (1);
	}
	if (item == data[low])
		return (1);
	return (0);
}

static t_array	sorted_seq(const int *data, const t_stack *st)
{
	t_stack	st_data;
	t_array	res;
	int		i;

	init_stack(&st_data, st->size, data);
	i = find_min(&st_data);
	while (i--)
		head_to_tail(&st_data);
	res.data = (int *)malloc(sizeof(int) * st->size);
	build_array(&st_data, &res);
	free_stack(&st_data);
	return (res);
}

void	slice(t_stack **st, const int *data)
{
	t_array	slice_id;

	slice_id = sorted_seq(data, st[0]);
	while (st[0]->size > slice_id.size)
	{
		if (!interpolation_srch(&slice_id, (st[0]->head)->item))
		{
			px(st, "pb\n");
		}
		else
			rx(st[0], "ra\n");
	}
	if (slice_id.size)
		free(slice_id.data);
}
