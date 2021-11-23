# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnaftana <jnaftana@student.42madrid.es>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 15:45:23 by jnaftana          #+#    #+#              #
#    Updated: 2021/11/23 17:58:49 by jnaftana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS		= ft_printf.c helper_types.c helper_types_2.c
LIB_SRCS	= ft_putchar_fd.c ft_putstr_fd.c ft_strlen.c ft_itoa.c ft_calloc.c \
				ft_strlcat.c ft_bzero.c ft_strlcpy.c ft_utoa.c ft_strupper.c \
				ft_toupper.c ft_hextoa.c

OBJS		= ${SRCS:.c=.o}
LIB_OBJS	= ${LIB_SRCS:.c=.o}

LIB_PATH	= libft
SRC_PATH	= src
INCLUDES_PATH = includes
INCLUDE_PF = ft_printf.h
INCLUDE_LFT = libft.h

LIB			= $(addprefix $(LIB_PATH)/, $(LIB_OBJS))
SRC			= $(addprefix $(SRC_PATH)/, $(OBJS))
PF_LIB		= $(addprefix $(INCLUDES_PATH)/, $(INCLUDE_PF))
LFT_LIB		= $(addprefix $(LIB_PATH)/, $(INCLUDE_LFT))

CC		= clang
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror
AR		= ar
RC		= rc
				
all:			${NAME}

${NAME}:		$(SRC) $(LFT) $(PF_LIB) $(LFT_LIB)
				${AR} ${RC} ${NAME} $(SRC) $(LFT)

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<

clean:
				${RM} ${OBJS} $(OBJS_B)

fclean:			clean
				${RM} ${NAME}

re:				fclean all