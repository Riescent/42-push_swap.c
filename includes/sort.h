/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:10:54 by vfries            #+#    #+#             */
/*   Updated: 2022/12/20 12:31:17 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "ft_linked_list.h"
# include <stdbool.h>

typedef enum e_order
{
	ASCENDING = 0,
	DESCENDING = 1,
}	t_order;

typedef struct s_orders
{
	t_order	current;
	t_order	start;
}	t_orders;

// convert_value_to_index.c
t_list_i	*convert_value_to_index(t_list_i *stack);

// divide_stack.c
t_list_i	*divide_stack(t_list_i **stack, int size, t_orders orders);
t_list_i	*divide_a(t_list_i **a, t_order order);

// is_sorted.c
bool		is_sorted(t_list_i *stack, t_order order);

// operate_on_stack.c
void		push_elem(t_list_i **src, t_list_i **dst, t_orders orders);
void		rotate_stack(t_list_i **stack, t_orders orders);
void		reverse_rotate_stack(t_list_i **stack, t_orders orders);

// reverse_order.c
t_order		reverse_order(t_order order);
t_orders	reverse_orders(t_orders orders);

// should_be_pushed.c
bool		should_be_pushed(int value, int median, t_order order);
bool		elems_left_to_push(t_list_i *stack, int size, int median,
				t_order order);

// sort_stack.c
void		sort_stack(t_list_i **a, t_orders order);

#endif
