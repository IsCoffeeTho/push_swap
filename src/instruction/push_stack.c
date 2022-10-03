/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:40:25 by amenadue          #+#    #+#             */
/*   Updated: 2022/09/29 14:44:03 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ps.h"

void	push_stack(t_stack *from, t_stack *to)
{
	t_lst	*tmp;

	if (!from || !to)
		return ;
	if (!from->root)
		return ;
	tmp = from->root->next;
	from->root->next = to->root;
	to->root = from->root;
	from->root = tmp;
	from->size--;
	to->size++;
}
