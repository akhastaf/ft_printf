C = gcc
FLAG = -Wall -Wextra -Werror
NAME = libftprintf.a

SRC = 

OBJ = $(SRC:.c=.o)

all: $(NAME)

bonus: all

$(NAME):
	$(C) $(FLAG) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ) $(OBJ_B)

fclean: clean
	rm -f $(NAME)

re: clean fclean all