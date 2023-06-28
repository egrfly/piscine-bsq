/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:05:35 by robsmith          #+#    #+#             */
/*   Updated: 2023/06/28 23:21:41 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1 && !ft_solve_map(NULL))
		ft_putstr_fd("map error\n", STDERR_FILENO);
	i = 1;
	while (i < argc)
	{
		if (!ft_solve_map(argv[i]))
			ft_putstr_fd("map error\n", STDERR_FILENO);
		if (i + 1 < argc)
			ft_putchar('\n');
		i++;
	}
	return (0);
}
