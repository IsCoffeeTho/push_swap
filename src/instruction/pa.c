/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:40:25 by amenadue          #+#    #+#             */
/*   Updated: 2022/09/26 18:38:25 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ps.h"

/** (push a): Take the first element at the top of b and put it at the top of a.
 * Do nothing if b is empty. */
void	pa(t_s_ab *stacks)
{
	t_lst	*tmp;

	if (!ps_check(stacks))
		return ;
	if (!stacks->b->root)
		return ;
	tmp = stacks->b->root->next;
	stacks->b->root->next = stacks->a->root;
	stacks->a->root = stacks->b->root;
	stacks->b->root = tmp;
	stacks->a->size++;
	stacks->b->size--;
	ft_printf("pa\n");
}
