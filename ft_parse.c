/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:08:08 by robsmith          #+#    #+#             */
/*   Updated: 2023/06/28 23:21:26 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

static bool	ft_all_distinct_and_printable(char a, char b, char c)
{
	if (a == b || a == c || b == c)
		return (false);
	else if (a < ' ' || a > '~' || b < ' ' || b > '~' || c < ' ' || c > '~')
		return (false);
	else
		return (true);
}

static bool	ft_parse_first_line(char *map_line, t_map *map)
{
	int	line_length;

	line_length = ft_strlen(map_line);
	if (line_length < 4)
		return (false);
	map->row_count = ft_strntoi(map_line, line_length - 3);
	if (!map->row_count)
		return (false);
	if (!ft_all_distinct_and_printable(map_line[line_length - 3],
			map_line[line_length - 2],
			map_line[line_length - 1]))
		return (false);
	map->empty_char = map_line[line_length - 3];
	map->obstacle_char = map_line[line_length - 2];
	map->full_char = map_line[line_length - 1];
	return (true);
}

static bool	ft_parse_line(char *map_line, t_map *map)
{
	int	i;

	i = 0;
	while (map_line[i] == map->empty_char || map_line[i] == map->obstacle_char)
		i++;
	if (map_line[i] || i != map->col_count)
		return (false);
	return (true);
}

bool	ft_parse_map(char **map_lines, t_map *map)
{
	int	i;

	if (!map_lines[0] || !map_lines[1]
		|| !ft_parse_first_line(map_lines[0], map)
		|| !ft_strlen(map_lines[1]))
		return (false);
	map->col_count = ft_strlen(map_lines[1]);
	i = 1;
	while (map_lines[i])
	{
		if (!ft_parse_line(map_lines[i], map))
			return (false);
		i++;
	}
	if (i != map->row_count + 1)
		return (false);
	return (true);
}
