# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/28 23:21:49 by emflynn           #+#    #+#              #
#    Updated: 2023/06/28 23:24:12 by emflynn          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=		bsq
SRCS :=		ft_bsq.c \
			ft_input.c \
			ft_nbr_utils.c \
			ft_output.c \
			ft_parse.c \
			ft_split.c \
			ft_str_utils.c \
			ft_strn_utils.c \
			ft_tab_utils.c \
			main.c
OBJS :=		$(SRCS:.c=.o)

CC :=		cc
CFLAGS :=	-Wall -Wextra -Werror

RM :=		rm -f

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $^ -o $@

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
