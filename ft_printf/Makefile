# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eulee <eulee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/26 16:46:10 by eulee             #+#    #+#              #
#    Updated: 2025/05/07 18:24:35 by eulee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

CC = cc

CFLAGS = -I$(LIBFT_DIR) -Wall -Werror -Wextra

SRCS = ft_printf.c ft_printf_utils.c main.c

OBJS = $(SRCS:.c=.o)

ARFLAGS = rsc

AR = ar $(ARFLAGS)

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	$(AR) $@ $(OBJS)

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR)
	
clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(LIBFT) libft.a

re: 
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
