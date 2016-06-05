

SRC = geometry.c main.c minitools.c utils.c exit_on_error.c

LIBS = .

NAME = fdf

all: $(NAME)

FLAGS = -Werror -Wall -Wextra

$(NAME):
	make -C libft/ clean fclean all
	gcc $(SRC) $(FLAGS) -o $(NAME) -L$(LIBS) -L libft/ -l ft -lmlx -framework OpenGL -framework AppKit

clean:
	make -C libft/ clean
	rm -f $(NAME)

fclean:
	make -C libft/ fclean
