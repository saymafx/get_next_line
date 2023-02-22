NAME = libft.a

GCC = gcc

FLAGS = -Wall -Wextra -Werror

AR = ar

RC = -rc

SRC = 

OBJ = ${SRC:.c=.o}

$(NAME): $(OBJ)
	$(AR) ${RC} $(NAME) $(OBJ) 

all: $(NAME)

%.o: %.c
	$(GCC) $(FLAGS) -c $< -o $@

clean:
	rm -rf ${OBJ}

fclean:clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus