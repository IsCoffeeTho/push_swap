/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smrt_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:40:25 by amenadue          #+#    #+#             */
/*   Updated: 2022/09/28 08:13:43 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ps.h"

/** will only run either ra or rb if it can */
void	smrt_rr(t_s_ab *stacks)
{
	if (stacks->a->size >= 2 && stacks->b->size >= 2)
		rr(stacks);
	else if (stacks->a->size >= 2)
		rb(stacks);
	else if (stacks->b->size >= 2)
		rb(stacks);
}
