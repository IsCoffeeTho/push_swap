/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 10:35:51 by amenadue          #+#    #+#             */
/*   Updated: 2022/08/26 11:36:07 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	main(int c, char **v)
{
	t_stack	*a;
	t_stack	*b;

	if (c > 1)
	{
		a = init_stack(c - 1, v + 1);
		b = empty_stack();
		ps_begin(a, b);
	}
	else
	{
		ft_printf("\e[91mREQUIRES INPUTS\e[0m\n");
		exit (1);
	}
}
