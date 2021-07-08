/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <abaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 18:36:05 by abaudot           #+#    #+#             */
/*   Updated: 2021/07/08 12:00:48 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LARGE_H
# define LARGE_H

# define HALF_SPIT 	20
# define EMPTY_STACK 10

void	normalize(t_stack *st, int *arr);
int		get_median(t_stack *st, int size);
void	stack_quicksort(t_stack **st);
void	split_b(t_stack **st, int pivot);
void	split_a(t_stack **st, int pivot);
void	half_split(t_stack **st, int pivot, int limit);
void	check_split(t_stack **st, int limit);
#endif
