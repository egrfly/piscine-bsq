/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 22:21:04 by emflynn           #+#    #+#             */
/*   Updated: 2023/06/28 23:21:20 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	ft_min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	return (c);
}

bool	ft_value_larger_than_int(char *str)
{
	bool	starts_with_zero;
	int		i;

	starts_with_zero = false;
	while (*str == '0')
	{
		starts_with_zero = true;
		str++;
	}
	i = 0;
	while ('0' <= str[i] && str[i] <= '9')
		i++;
	if ((!starts_with_zero && i < 1) || i > 10
		|| (i == 10 && ft_strncmp(str, "2147483647", 10) > 0))
		return (true);
	return (false);
}
