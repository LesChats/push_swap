/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:55:08 by abaudot           #+#    #+#             */
/*   Updated: 2021/07/05 02:49:50 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include <stdio.h>

struct s_frame
{
	struct s_frame	*next;
	struct s_frame	*prev;
	int				item;
};

typedef struct s_stack
{
	struct s_frame	*head;
	struct s_frame	*tail;
	int				size;
}				t_stack;

/*
**	stack init & destructor
*/
char			init_stack(t_stack *st, const int size, const int *tab);
char			free_stack(t_stack *st);
void			print_stack(t_stack *st);
int				is_sorted(t_stack *st);

/*
** stack opperations
*/
void			swap(t_stack *st);
void			pop_push(t_stack *dst, t_stack *src);
void			tail_to_head(t_stack *st);
void			head_to_tail(t_stack *st);

/*
** stack utils
*/
int				find_min(const t_stack *st);
int				find_max(const t_stack *st);
int				get_max(const t_stack *st);
int				get_min(const t_stack *st);

#endif
