CC =	gcc
NAME =	abstractvm
CFLAGS = -W -Wall -Werror -Wextra
SRC =	my_lib1.c\
		my_lib2.c\
        my_funcs.c\
		main.c\


OBJ = 	$(SRC:%.c=%.o)

RM =	rm -f

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:			clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: re fclean clean all
