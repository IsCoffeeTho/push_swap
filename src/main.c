/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 10:35:51 by amenadue          #+#    #+#             */
/*   Updated: 2022/08/26 12:37:58 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	main(int c, char **v)
{
	t_s_ab	*sets;

	if (c > 1)
	{
		sets = (t_s_ab *) ft_calloc(1, sizeof(t_s_ab));
		sets->a = init_stack(c - 1, v + 1);
		sets->b = empty_stack();
		ps_begin(sets);
	}
	else
	{
		ft_printf("\e[91mREQUIRES INPUTS\e[0m\n");
		exit (1);
	}
}
