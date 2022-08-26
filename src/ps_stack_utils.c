/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:13:07 by amenadue          #+#    #+#             */
/*   Updated: 2022/08/26 11:37:01 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_stack	*init_stack(int c, char **v)
{
	t_stack	*stack;
	int		i;

	stack = (t_stack *) ft_calloc(1, sizeof(t_stack));
	i = 0;
	if (!stack)
		return (NULL);
	if (c > 0)
	{
		while (i < c)
		{
			if (!append_stack(stack, new_lst(ft_atoi(v[i]))))
			{
				write(2, "Couldn't append a value to the stack.\n", 39);
				return (NULL);
			}
			i++;
		}
	}
	return (stack);
}

t_stack	*empty_stack(void)
{
	return ((t_stack *) ft_calloc(1, sizeof(t_stack)));
}

int	append_stack(t_stack *stack, t_lst *item)
{
	t_lst	*last;

	if (stack && item)
	{
		if (!stack->size)
		{
			stack->root = item;
			return (1);
		}
		else
		{
			last = stack->root;
			while (last->next != NULL)
				last = last->next;
			last->next = item;
			return (1);
		}
	}
	return (0);
}

t_lst	*new_lst(int data)
{
	t_lst *item;

	item = (t_lst *) ft_calloc(1, sizeof(t_lst));
	if (!item)
		return (NULL);
	item->data = data;
	return (item);
}
