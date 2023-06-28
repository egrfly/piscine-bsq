/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:10:23 by emflynn           #+#    #+#             */
/*   Updated: 2023/06/28 23:21:10 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>

# define BUFFER_SIZE 1024

typedef struct s_map
{
	char	**rows;
	int		row_count;
	int		col_count;
	char	empty_char;
	char	obstacle_char;
	char	full_char;
	int		square_size;
	int		square_top_left_row;
	int		square_top_left_col;
}	t_map;

// ft_bsq.c
bool			ft_solve_map(char *filepath);

// ft_input.c
char			*ft_get_file_content(char *file);

// ft_nbr_utils.c
int				ft_min(int a, int b, int c);
bool			ft_value_larger_than_int(char *str);

// ft_output.c
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr(char *str);
void			ft_putstr_fd(char *str, int fd);
void			ft_print_filled_map(t_map *map);

// ft_parse.c
bool			ft_parse_map(char **map_lines, t_map *map);

// ft_split.c
int				ft_count_splits(char *str, char *charset);
char			**ft_free_splits(char **tab);
char			**ft_split(char *str, char *charset);

// ft_str_utils.c
int				ft_strlen(char *str);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strchr(char *str, char c);

// ft_strn_utils.c
int				ft_strncmp(char *s1, char *s2, unsigned int n);
char			*ft_strncpy(char *dest, char *src, int n);
char			*ft_strncat(char *dest, char *src, int n);
char			*ft_strndup(char *str, int n);
int				ft_strntoi(char *str, int n);

// ft_tab_utils.c
void			ft_free_int_tab(int **tab, int row_count);
int				**ft_allocate_int_tab(int row_count, int col_count);

#endif
