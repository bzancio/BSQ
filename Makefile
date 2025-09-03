SOURCES = bsq.c utils.c solver.c parser.c split_utils.c free_utils.c print.c algo.c empty_utils.c utils2.c
OBJECTS = $(SOURCES:.c=.o)
INCLUDES = -I .

CC = cc
NAME = bsq
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

%.o: %.c
	@$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJECTS) -o $(NAME)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean
