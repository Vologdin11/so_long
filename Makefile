NAME = so_long

SRCS = main.c secondary_functions.c ft_split.c read_map.c validator.c create_image.c work_clicks.c bonus.c

OBJS = $(SRCS:%c=%o)

HEADER = so_long.h

CC = gcc

FLAGS = -Wall -Werror -Wextra

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(FLAGS) $(MLXFLAGS) -o $(NAME) $(OBJS)

bonus: all

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus