/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:10:22 by abaudot           #+#    #+#             */
/*   Updated: 2021/06/24 20:31:04 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"
# include "medium.h"
# include <unistd.h>

int		ft_strlen(char *str);
int		parse_multi_arg(int **array, char **av, const int size);
int		parse_string(int **array, char *av);

void	sx(t_stack *st, const char *out);
void	rrx(t_stack *st, const char *out);
void	rx(t_stack *st, const char *out);

void	px(t_stack **sts, const char *out);
void	rrr(t_stack **sts);
void	rr(t_stack **sts);
void	ss(t_stack **sts);

int		maxin(const int *array, unsigned long len);
int		abs(const int a);
int		max(const int a, const int b);
int		min(const int a, const int b);
int		count_op(int a, int b);

void	small_sort(t_stack **st);
void	medium_sort(t_stack **st, const int *data);
#endif
