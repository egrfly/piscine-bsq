/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:11:05 by robsmith          #+#    #+#             */
/*   Updated: 2023/06/28 23:20:56 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

static char	**ft_get_map_lines(char *filepath)
{
	char	*map_content;
	char	**map_lines;

	map_content = ft_get_file_content(filepath);
	if (!map_content || !ft_count_splits(map_content, "\n"))
		return (false);
	map_lines = ft_split(map_content, "\n");
	free(map_content);
	return (map_lines);
}

static void	ft_fill_in_square_size(t_map *map,
				int **potential_square_sizes, int row, int col)
{
	if (map->rows[row][col] == map->obstacle_char)
		potential_square_sizes[row][col] = 0;
	else if (row == map->row_count - 1 || col == map->col_count - 1)
		potential_square_sizes[row][col] = 1;
	else
		potential_square_sizes[row][col] = ft_min(
				potential_square_sizes[row][col + 1],
				potential_square_sizes[row + 1][col],
				potential_square_sizes[row + 1][col + 1]) + 1;
}

static bool	ft_calculate_square_sizes(t_map *map)
{
	int	**square_sizes;
	int	row;
	int	col;

	square_sizes = ft_allocate_int_tab(map->row_count, map->col_count);
	if (!square_sizes)
		return (false);
	row = map->row_count;
	while (row-- > 0)
	{
		col = map->col_count;
		while (col-- > 0)
		{
			ft_fill_in_square_size(map, square_sizes, row, col);
			if (square_sizes[row][col] >= map->square_size)
			{
				map->square_size = square_sizes[row][col];
				map->square_top_left_row = row;
				map->square_top_left_col = col;
			}
		}
	}
	ft_free_int_tab(square_sizes, map->row_count);
	return (true);
}

static void	ft_fill_in_square(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->square_size)
	{
		j = 0;
		while (j < map->square_size)
		{
			map->rows[map->square_top_left_row + i][map->square_top_left_col
				+ j] = map->full_char;
			j++;
		}
		i++;
	}
}

bool	ft_solve_map(char *filepath)
{
	char	**map_lines;
	t_map	map;

	map_lines = ft_get_map_lines(filepath);
	if (!map_lines)
		return (false);
	if (!ft_parse_map(map_lines, &map))
	{
		ft_free_splits(map_lines);
		return (false);
	}
	map.rows = &map_lines[1];
	map.square_size = 0;
	if (!ft_calculate_square_sizes(&map))
	{
		ft_free_splits(map_lines);
		return (false);
	}
	ft_fill_in_square(&map);
	ft_print_filled_map(&map);
	ft_free_splits(map_lines);
	return (true);
}
