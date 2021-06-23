/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 14:38:26 by abaudot           #+#    #+#             */
/*   Updated: 2021/06/23 18:09:05 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include <stdint.h>

/*
**	Magic number for fast read
*/
# define HIMAGIC    0x8080808080808080UL
# define LOMAGIC    0x0101010101010101UL
# define NL         0xa0a0a0a0a0a0a0aUL
# define READ_BUFFSZ	10000

typedef struct s_string
{
	char			*s;
	uint32_t		len;
	uint32_t		size;
}					t_string;

int					getnextline(int fd, t_string *my_line);

uint8_t				initilize_string(t_string *string, uint32_t n);
uint8_t				update_string(t_string *str, const char *src, int32_t n);

void				ft_memcpy(void *dest, const void *src, uint32_t n);

char				sswap(t_stack *st);
char				shtt(t_stack *st);
char				stth(t_stack *st);
char				spp(t_stack *dst, t_stack *src);
char				bihtt(t_stack **st);
char				biswap(t_stack **st);
char				bitth(t_stack **st);

#endif
