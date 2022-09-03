# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jahmimid <jahmimid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/02 16:09:25 by jahmimid          #+#    #+#              #
#    Updated: 2022/06/22 14:32:41 by jahmimid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_bzero.c ft_isalpha.c ft_isprint.c ft_memcmp.c ft_memset.c \
	ft_strlcat.c ft_strncmp.c ft_tolower.c ft_calloc.c ft_isascii.c \
	 ft_memcpy.c ft_strchr.c ft_strlcpy.c ft_strnstr.c \
	ft_toupper.c ft_atoi.c ft_isalnum.c ft_isdigit.c ft_memchr.c \
	ft_memmove.c ft_strdup.c ft_strlen.c ft_strrchr.c ft_putchar_fd.c \
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_striteri.c get_next_line.c get_next_line_utils.c ft_isspace.c \
	ft_strcmp.c

SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	     ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
	     ft_lstiter.c ft_lstmap.c

OBJS	= ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

NAME	= libft.a

RM	= rm -f

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror

.c.o:
	gcc -Wall -Werror -Wextra -c $< -o ${<:.c=.o}

all:	${NAME}

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}

bonus:	${OBJS_BONUS}
	ar rc ${NAME} ${OBJS_BONUS}

clean:
	${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
