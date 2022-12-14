/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:40:25 by amenadue          #+#    #+#             */
/*   Updated: 2022/09/27 22:36:09 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ps.h"

/** (rotate rotate a): shifts all elements in A down by one
 * 	last element of A becomes the first element of A
 */
void	rra(t_s_ab *stacks)
{
	t_lst	*first;
	t_lst	*penult;
	t_lst	*last;

	if (!ps_check(stacks))
		return ;
	if (!stacks->a->root)
		return ;
	if (!stacks->a->root->next)
		return ;
	first = stacks->a->root;
	last = first;
	while (last->next)
	{
		penult = last;
		last = last->next;
	}
	penult->next = NULL;
	last->next = first;
	stacks->a->root = last;
	ft_printf("rra\n");
}
