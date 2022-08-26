/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:00:35 by amenadue          #+#    #+#             */
/*   Updated: 2022/08/26 12:45:54 by amenadue         ###   ########.fr       */
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
	t_stack *a;
	t_stack *b;
}	t_s_ab;

t_lst	*new_lst(int data);

t_stack	*init_stack(int c, char **v);
t_stack	*empty_stack(void);
int		append_stack(t_stack *stack, t_lst *item);

void	ps_begin(t_s_ab *stacks);

void	dump_stack(t_stack *stack);

void	pa(t_s_ab *stacks);

#endif