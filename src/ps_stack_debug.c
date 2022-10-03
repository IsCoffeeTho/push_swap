/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_debug.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:13:07 by amenadue          #+#    #+#             */
/*   Updated: 2022/10/03 22:37:10 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

/** Prints the stack contents into stdout
 *  will check if circular and empty
 * 	PURELY FOR DEBUGGING
*/
void	dump_stack(t_stack *stack)
{
	t_lst	*last;

	if (stack)
	{
		if (stack->root)
		{
			ft_printf("STACK:\n");
			last = stack->root;
			while (last)
			{
				ft_printf("- %d : %d\n", last->data, last->index);
				last = last->next;
				if (last == stack->root)
				{
					write(2, "STACK IS CIRCULAR\n", 39);
					break ;
				}
			}
		}
		else
			ft_printf("STACK:\n  Empty\n");
	}
}

/** Generates the standard [1-5] stack for tests */
static t_stack	*test_stack(void)
{
	char	buf[2];
	t_stack	*stack;
	int		i;

	stack = empty_stack();
	i = 0;
	buf[1] = 0;
	while (i++ < 4)
	{
		buf[0] = '0' + i;
		append_stack(stack, new_lst(buf));
	}
	return (stack);
}

/** This function runs through the different OPs.
 * As well as dumps the stacks to stdout*/
void	ps_test_seq(void)
{
	ps_stack_op_test(&pa);
	ps_stack_op_test(&pb);
	ps_stack_op_test(&ra);
	ps_stack_op_test(&rb);
	ps_stack_op_test(&rr);
	ps_stack_op_test(&rra);
	ps_stack_op_test(&rrb);
	ps_stack_op_test(&rrr);
	ps_stack_op_test(&sa);
	ps_stack_op_test(&sb);
	ps_stack_op_test(&ss);
}

/** function allows the testing of certain operations */
void	ps_stack_op_test(void (*f)(t_s_ab *))
{
	t_s_ab	*sets;

	sets = (t_s_ab *) ft_calloc(1, sizeof(t_s_ab));
	sets->a = test_stack();
	sets->b = test_stack();
	ft_printf("== ");
	f(sets);
	ft_printf("A ");
	dump_stack(sets->a);
	ft_printf("B ");
	dump_stack(sets->b);
	free_stacks(sets);
	ft_printf("\n");
}
