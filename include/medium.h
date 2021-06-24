/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 12:29:22 by abaudot           #+#    #+#             */
/*   Updated: 2021/06/24 20:31:47 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEDIUM_H
# define MEDIUM_H

# include "stack.h"

typedef struct s_array
{
	int	*data;
	int	size;
}				t_array;

typedef int		t_tuple[2];

typedef void	(*t_opxx)(t_stack**);
typedef void	(*t_op)(t_stack*, const char*);

void			slice(t_stack **st, const int *data);
void			find_bestm(t_stack **st, t_tuple move);

#endif
