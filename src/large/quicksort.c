/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <abaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 16:44:02 by abaudot           #+#    #+#             */
/*   Updated: 2021/07/08 11:59:08 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Do to normalization the media is the mean !
*/
int	get_median(t_stack *st, int size)
{
	struct s_frame	*tmp;
	int				i;
	int				sum;

	tmp = st->head;
	sum = 0;
	i = 0;
	while (i < size)
	{
		sum += tmp->item;
		tmp = tmp->next;
		++i;
	}
	return (sum / size);
}

/*
**	interpolation seatch say safe because in your case we know
** that the value wy looking for is in the array
*/
static int	safe_inter_srch(const int *arr, const int item, const int size)
{
	int	low;
	int	high;
	int	mid;

	low = 0;
	high = size - 1;
	while (item >= arr[low] && item <= arr[high])
	{
		mid = low
			 + ((float)(high - low) / (arr[high] - arr[low]))
			 * (item - arr[low]);
		if (arr[mid] < item)
			low = mid + 1;
		else if (item < arr[mid])
			high = mid - 1;
		else
			return (mid);
	}
	if (item == arr[low])
		return (low);
	return (-1);
}

/*
** Partion for the Hoare quicksort
*/
static int	partition(int *arr, int lo, int hi)
{
	int	pivot;
	int	tmp;
	int	i;
	int	j;

	pivot = arr[lo];
	i = lo - 1;
	j = hi + 1;
	while (1)
	{
		while (arr[++i] < pivot)
			;
		while (arr[--j] > pivot)
			;
		if (i >= j)
			return (j);
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
}

/*
** Hoare partition scheme
*/

static void	quicksort(int *arr, int lo, int hi)
{
	int	p;

	if (lo < hi)
	{
		p = partition(arr, lo, hi);
		quicksort(arr, lo, p);
		quicksort(arr, p + 1, hi);
	}
}

/*
**	Normalization is the process to turn any array to is [0 -> n] 
** forme ex: {1 4 3 -1} -> {1 3 2 0}
*/
void	normalize(t_stack *st, int *arr)
{
	struct s_frame	*tmp;
	int				i;
	const int		size = st->size;

	quicksort(arr, 0, st->size - 1);
	tmp = st->head;
	i = 0;
	while (i < size)
	{
		tmp->item = safe_inter_srch(arr, tmp->item, size);
		tmp = tmp->next;
		++i;
	}
}
