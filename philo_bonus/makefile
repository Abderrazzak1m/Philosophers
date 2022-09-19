CC= gcc
CFLAGS = -Wall -Werror -Wextra -g

NAME= philo

INCLUDE= ./include/philosophers.h


FILES = ./src/main \
		./src/init \
		./src/list_utils \
		./src/utils


OBJS= $(FILES:=.o)


all: $(NAME)

%.o: %.c $(INCLUDE)
	$(CC)  $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)



clean:
	rm -f $(OBJS)
	

fclean: clean
	rm -f $(NAME)
	

re: fclean all


.PHONY: all  clean fclean re 