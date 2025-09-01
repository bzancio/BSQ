SOURCES = bsq.c utils.c solver.c parser.c
OBJECTS = $(SOURCES:.c=.o)
INCLUDES = -I .

CC = cc
NAME = bsq
CFLAGS = -Wall -Wextra -Werror

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
