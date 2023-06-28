/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:45:04 by emflynn           #+#    #+#             */
/*   Updated: 2023/06/28 23:21:29 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	ft_count_splits(char *str, char *charset)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] && !ft_strchr(charset, str[i + j]))
			j++;
		count += (j > 0);
		i += j;
		while (str[i] && ft_strchr(charset, str[i]))
			i++;
	}
	return (count);
}

char	**ft_free_splits(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		j;
	int		count;

	tab = (char **)malloc(sizeof(char *) * (ft_count_splits(str, charset) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	count = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] && !ft_strchr(charset, str[i + j]))
			j++;
		tab[count] = ft_strndup(str + i, j);
		if (!tab[count])
			return (ft_free_splits(tab));
		count += (j > 0);
		i += j;
		while (str[i] && ft_strchr(charset, str[i]))
			i++;
	}
	tab[count] = NULL;
	return (tab);
}
