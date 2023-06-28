/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:15:52 by robsmith          #+#    #+#             */
/*   Updated: 2023/06/28 23:21:15 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

static char	*ft_combine_strs(char *str1, char *str2, int n)
{
	char	*combined_str;

	if (!str1)
		return (ft_strndup(str2, n));
	combined_str = malloc(sizeof(char) * (ft_strlen(str1) + n + 1));
	if (!combined_str)
	{
		free(str1);
		return (NULL);
	}
	ft_strcpy(combined_str, str1);
	free(str1);
	ft_strncat(combined_str, str2, n);
	return (combined_str);
}

static char	*ft_read_content_from_file_descriptor(int fd)
{
	char	*file_content;
	int		chars_read;
	char	buffer[BUFFER_SIZE];

	file_content = NULL;
	while (true)
	{
		chars_read = read(fd, buffer, BUFFER_SIZE);
		if (chars_read < 0)
		{
			free(file_content);
			return (NULL);
		}
		else if (chars_read > 0)
		{
			file_content = ft_combine_strs(file_content, buffer, chars_read);
			if (!file_content)
				return (NULL);
		}
		else
			break ;
	}
	return (file_content);
}

char	*ft_get_file_content(char *file)
{
	int		fd;
	char	*file_content;

	if (file)
		fd = open(file, O_RDONLY);
	else
		fd = STDIN_FILENO;
	if (fd < 0)
		return (NULL);
	file_content = ft_read_content_from_file_descriptor(fd);
	if (fd != STDIN_FILENO)
		close(fd);
	return (file_content);
}
