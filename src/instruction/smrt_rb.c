/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smrt_rb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:40:25 by amenadue          #+#    #+#             */
/*   Updated: 2022/09/28 08:13:45 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ps.h"

/** will only run rb if it can */
void	smrt_rb(t_s_ab *stacks)
{
	if (stacks->b->size >= 2)
		rb(stacks);
}
