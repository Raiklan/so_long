NAME = So_long
LIBFT = libft/libft.a
FLAGS = -Wall -Wextra -Werror
SRC =   src/main.c              \
        src/error.c            \
        src/draw.c              \
        src/texture_and_mlx.c   \
        src/key.c               \
        src/moves.c             \
        gnl/get_next_line.c     \
        gnl/get_next_line_utils.c  \

INC =   so_long.h               \
        gnl/get_next_line.h     \

LIB = -L ./libft -lft -L ./mlx -lmlx -lXext -lX11

all: $(NAME)

$(NAME):
	cd mlx/ && ./configure
	gcc -g3 -fsanitize=address $(FLAGS) -o $(NAME) $(SRC) $(LIB)

skiperror:
	gcc -o $(NAME) $(SRC) -g $(LIB)

clean:
	@rm -rf *.o
	@echo "cleaning .o files"

fclean: clean
	@rm -rf $(NAME)

re: fclean all
