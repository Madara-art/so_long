SRC =	get_next_line.c help_fun_3.c\
		get_next_line_utils.c help_fun_4.c\
		help_fun_1.c help_fun_5.c\
		help_fun_2.c main.c

OBJ = $(SRC:%.c=%.o)

CFLAGS = -Wall -Werror -Wextra

NAME = so_long

all:$(NAME)

$(NAME):$(OBJ)
	cc $(CFLAGS) $(OBJ) -o $(NAME) -lmlx -framework OpenGL -framework AppKit

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f $(NAME)
