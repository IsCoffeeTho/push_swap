/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 10:35:51 by amenadue          #+#    #+#             */
/*   Updated: 2022/10/03 22:29:04 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

/*
	To Do:
	optimize
*/

/* runs through the stack ands checks for duplicates */
void	check_set_dupe(t_s_ab *stacks)
{
	t_lst	*lastcheck;
	t_lst	*last;
	int		i;
	int		j;

	lastcheck = stacks->a->root;
	i = 0;
	while (lastcheck)
	{
		j = 0;
		last = stacks->a->root;
		while (j < i)
		{
			if (last->data == lastcheck->data)
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			last = last->next;
			j++;
		}
		lastcheck = lastcheck->next;
		i++;
	}
}

int	check_args(int c, char **v)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	while (i < c)
	{
		j = 1;
		k = ft_strlen(v[i]);
		if (!(v[i][0] == '-' || ft_isdigit(v[i][0])))
			return (0);
		while (j < k)
		{
			if (!ft_isdigit(v[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int c, char **v)
{
	t_s_ab	*sets;

	if (c > 1)
	{
		if (check_args(c, v))
		{
			sets = (t_s_ab *) ft_calloc(1, sizeof(t_s_ab));
			sets->a = init_stack(c - 1, v + 1);
			sets->b = empty_stack();
			check_set_dupe(sets);
			ps_choose(sets);
		}
		else
		{
			write(2, "Error\n", 6);
			return (1);
		}
	}
}
