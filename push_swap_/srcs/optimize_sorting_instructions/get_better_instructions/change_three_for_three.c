/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_three_for_three.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 21:51:48 by vfries            #+#    #+#             */
/*   Updated: 2023/01/06 00:51:32 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"
#include "optimize_sorting_instructions.h"
#include <stdlib.h>

t_three_for_three	get_three_for_three_targets(int target_1, int target_2,
						int target_3)
{
	t_three_for_three	data;

	data.target_1 = target_1;
	data.target_2 = target_2;
	data.target_3 = target_3;
	return (data);
}

void	set_three_for_three_new(t_three_for_three *data, int new_1, int new_2,
			int new_3)
{
	data->new_1 = new_1;
	data->new_2 = new_2;
	data->new_3 = new_3;
}

static void	replace_three_for_three(t_list_i *instructions,
				t_three_for_three data)
{
	instructions->content = data.new_1;
	instructions->next->content = data.new_2;
	instructions->next->next->content = data.new_3;
}

void	change_three_for_three(t_list_i *instructions, t_three_for_three data,
			bool *changed_something)
{
	instructions = get_next_target(instructions, data.target_1);
	while (instructions != NULL && instructions->next != NULL
		&& instructions->next->next != NULL)
	{
		if (instructions->next->content == data.target_2
			&& instructions->next->next->content == data.target_3)
		{
			replace_three_for_three(instructions, data);
			*changed_something = true;
		}
		instructions = get_next_target(instructions->next, data.target_1);
	}
}
