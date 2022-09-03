SRCS =	srcs/main.c \
		srcs/utils/error.c \
		srcs/parsing/checks.c \
		srcs/parsing/init_map.c \
		srcs/parsing/parsing.c \
		srcs/parsing/get_texture.c \
		srcs/parsing/get_texture2.c \
		srcs/parsing/get_map.c \
		srcs/utils/walls.c \
		srcs/utils/printer.c \
		srcs/raycasting/rayinitialisation.c \
		srcs/mlx/mlx.c \
		srcs/raycasting/raycasting.c \
		srcs/raycasting/raycasting_utils.c \
		srcs/mlx/textures.c \
		srcs/utils/free.c \
		
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS = -lm -lmlx -lXext -lX11
IFLAGS = -I includes -I libft -I mlx
LFLAGS = -L libft -L mlx
RM = rm -rf
NAME = cub3D


.c.o:
			${CC} ${CFLAGS} ${IFLAGS} -c $< -o ${<:.c=.o}

all:	$(NAME)

$(NAME):	${OBJS}
			make -C libft
			make -C mlx
			${CC} ${CFLAGS} ${LFLAGS} ${OBJS} -o ${NAME} -lft ${MLX_FLAGS}

clean:
			make clean -C libft
			make clean -C mlx
			rm -rf ${OBJS}

fclean:	clean
			make fclean -C libft
			rm -rf ${NAME}

debug:		CFLAGS += -g3
debug:		fclean
debug:		all

re:			fclean all

.PHONY:	all clean fclean re