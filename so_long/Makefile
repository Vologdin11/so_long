NAME = so_long

SRCS = main.c secondary_functions.c ft_split.c

OBJS = $(SRCS:%c=%o)

CC = gcc

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) -lmlx -framework OpenGL -framework AppKit $(SRCS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(NAME)

re: fclean all