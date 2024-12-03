NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I.

SRCS = helper.c\
        putnbr.c\
        ft_printf.c\

BONUS =

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS:.c=.o)

HEADERS = ft_printf.h

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
