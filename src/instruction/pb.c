/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:40:25 by amenadue          #+#    #+#             */
/*   Updated: 2022/09/26 18:38:42 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ps.h"

/** (push b): Take the first element at the top of a and put it at the top of b.
 * Do nothing if a is empty. */
void	pb(t_s_ab *stacks)
{
	t_lst	*tmp;

	if (!ps_check(stacks))
		return ;
	if (!stacks->a->root)
		return ;
	tmp = stacks->a->root->next;
	stacks->a->root->next = stacks->b->root;
	stacks->b->root = stacks->a->root;
	stacks->a->root = tmp;
	stacks->a->size--;
	stacks->b->size++;
	ft_printf("pb\n");
}
