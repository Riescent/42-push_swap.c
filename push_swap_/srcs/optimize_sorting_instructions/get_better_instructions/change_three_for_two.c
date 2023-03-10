/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_three_for_two.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 21:51:48 by vfries            #+#    #+#             */
/*   Updated: 2023/01/06 00:52:57 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"
#include "optimize_sorting_instructions.h"
#include <stdlib.h>

t_three_for_two	get_three_for_two_targets(int target_1, int target_2,
					int target_3)
{
	t_three_for_two	data;

	data.target_1 = target_1;
	data.target_2 = target_2;
	data.target_3 = target_3;
	return (data);
}

void	set_three_for_two_new(t_three_for_two *data, int new_1, int new_2)
{
	data->new_1 = new_1;
	data->new_2 = new_2;
}

static void	replace_three_for_two(t_list_i *instructions, t_three_for_two data)
{
	t_list_i	*tmp;

	instructions->content = data.new_1;
	instructions->next->content = data.new_2;
	tmp = instructions->next->next->next;
	free(instructions->next->next);
	instructions->next->next = tmp;
}

void	change_three_for_two(t_list_i *instructions, t_three_for_two data,
			bool *changed_something)
{
	instructions = get_next_target(instructions, data.target_1);
	while (instructions != NULL && instructions->next != NULL
		&& instructions->next->next != NULL)
	{
		if (instructions->next->content == data.target_2
			&& instructions->next->next->content == data.target_3)
		{
			replace_three_for_two(instructions, data);
			*changed_something = true;
		}
		instructions = get_next_target(instructions->next, data.target_1);
	}
}
