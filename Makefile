NAME			=	so_long



SRCS			=	main.c              \
					error.c            \
					draw.c              \
					texture_and_mlx.c   \
					key.c               \
					moves.c             \
					get_next_line.c     \
					get_next_line_utils.c  \

OBJS			=	${addprefix src/,${SRCS:.c=.o}}

LD_FLAGS		=	-L libft -L mlx

MLX_FLAGS		=	-lmlx -lXext -lX11

HEAD			=	-I includes -I libft -I mlx

CC				=	gcc

CFLAGS			=	-Wall -Werror -Wextra -g #-fsanitize=address

all				:	${NAME}

c.o			:
					${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}

$(NAME)		:	${OBJS}
					@make -C libft
					@make -C mlx
					${CC} ${CFLAGS} ${LD_FLAGS} ${OBJS} -o ${NAME} -lft $(MLX_FLAGS)

clean			:
					make clean -C libft
					make clean -C mlx
					@rm -rf ${OBJS}

fclean			:	clean
					make fclean -C libft
					@rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re
