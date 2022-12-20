/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:05:14 by vfries            #+#    #+#             */
/*   Updated: 2022/12/20 14:52:16 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include <stdlib.h>

void	error(void)
{
	ft_putstr_fd("Error\n", STDERR_FD);
	exit(1);
}
