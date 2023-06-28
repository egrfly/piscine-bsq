/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 22:47:32 by emflynn           #+#    #+#             */
/*   Updated: 2023/06/28 23:21:38 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	ft_free_int_tab(int **tab, int row_count)
{
	int	i;

	i = 0;
	while (i < row_count && tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	**ft_allocate_int_tab(int row_count, int col_count)
{
	int	**tab;
	int	row;

	tab = (int **)malloc(sizeof(int *) * row_count);
	if (!tab)
		return (NULL);
	row = 0;
	while (row < row_count)
	{
		tab[row] = (int *)malloc(sizeof(int) * col_count);
		if (!tab[row])
		{
			ft_free_int_tab(tab, row_count);
			return (NULL);
		}
		row++;
	}
	return (tab);
}
