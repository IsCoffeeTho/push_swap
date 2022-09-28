/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:00:35 by amenadue          #+#    #+#             */
/*   Updated: 2022/09/28 18:16:28 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include "libft.h"

typedef struct s_lst {
	int				data;
	struct s_lst	*next;
}	t_lst;

typedef struct s_stack {
	t_lst	*root;
	size_t	size;
}	t_stack;

typedef struct s_s_ab {
	t_stack	*a;
	t_stack	*b;
}	t_s_ab;

t_lst	*new_lst(int data);

t_stack	*init_stack(int c, char **v);
t_stack	*empty_stack(void);
int		append_stack(t_stack *stack, t_lst *item);
void	free_stack(t_stack *stack);
void	free_stacks(t_s_ab *stacks);
void	stack_count(t_stack *stack);

void	ps_begin(t_s_ab *stacks);
int		ps_check(t_s_ab *stacks);

int		get_max_value(t_s_ab *stacks);
int		get_min_value(t_s_ab *stacks);

void	dump_stack(t_stack *stack);
void	ps_test_seq(void);
void	ps_stack_op_test(void (*f)(t_s_ab *));

void	pa(t_s_ab *stacks);
void	pb(t_s_ab *stacks);
void	ra(t_s_ab *stacks);
void	rb(t_s_ab *stacks);
void	rr(t_s_ab *stacks);
void	rra(t_s_ab *stacks);
void	rrb(t_s_ab *stacks);
void	rrr(t_s_ab *stacks);
void	sa(t_s_ab *stacks);
void	sb(t_s_ab *stacks);
void	ss(t_s_ab *stacks);

void	smrt_ra(t_s_ab *stacks);
void	smrt_rb(t_s_ab *stacks);
void	smrt_rr(t_s_ab *stacks);

#endif