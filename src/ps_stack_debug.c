/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_debug.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:13:07 by amenadue          #+#    #+#             */
/*   Updated: 2022/08/26 11:34:54 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	dump_stack(t_stack *stack)
{
	t_lst	*last;

	if (stack)
	{
		if (stack->size)
		{
			ft_printf("STACK:\n");
			last = stack->root;
			while (last)
			{
				ft_printf("- %d\n", last->data);
				last = last->next;
			}
		}
		else
		{
			ft_printf("Empty Stack\n");
		}
	}
}