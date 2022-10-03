/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:13:07 by amenadue          #+#    #+#             */
/*   Updated: 2022/10/03 17:14:03 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_stack	*init_stack(int c, char **v)
{
	t_stack	*stack;
	int		i;
	int		j;

	stack = (t_stack *) ft_calloc(1, sizeof(t_stack));
	i = 0;
	if (!stack)
		return (NULL);
	if (c > 0)
	{
		while (i < c)
		{
			j = ft_atoi(v[i]);
			if ((v[i][0] == '-' && j > 0) || (v[i][0] != '-' && j < 0))
			{
				write(1, "Error\n", 6);
				exit(1);
			}
			if (!append_stack(stack, new_lst(j)))
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			i++;
		}
	}
	return (stack);
}

t_stack	*empty_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *) ft_calloc(1, sizeof(t_stack));
	stack->root = NULL;
	return (stack);
}

int	ps_check(t_s_ab *stacks)
{
	if (!stacks)
		return (0);
	if (!stacks->a || !stacks->a)
		return (0);
	return (1);
}

int	append_stack(t_stack *stack, t_lst *item)
{
	t_lst	*last;

	if (stack && item)
	{
		if (!stack->root)
		{
			stack->root = item;
			stack->size = 1;
			return (1);
		}
		else
		{
			last = stack->root;
			while (last->next)
				last = last->next;
			last->next = item;
			stack->size++;
			return (1);
		}
	}
	write(2, "Bad Append to stack\n", 21);
	return (0);
}

t_lst	*new_lst(int data)
{
	t_lst	*item;

	item = (t_lst *) ft_calloc(1, sizeof(t_lst));
	if (!item)
		return (NULL);
	item->data = data;
	return (item);
}
