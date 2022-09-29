/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 10:35:51 by amenadue          #+#    #+#             */
/*   Updated: 2022/09/29 12:53:06 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

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
			ps_choose(sets);
		}
		else
		{
			write(2, "Error\n", 6);
			ft_printf("\e[91mMust be Numbers\e[0m\n");
			exit (1);
		}
	}
	else
	{
		write(2, "Error\n", 6);
		ft_printf("\e[91mREQUIRES INPUTS\e[0m\n");
		exit (1);
	}
}
