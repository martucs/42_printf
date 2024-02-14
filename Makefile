NAME = libftprintf.a

SRCS = ft_printf.c ft_utils.c

OBJS := $(SRCS:%.c=%.o)

CCFLAGS = -Wall -Werror -Wextra

LIB = ar rcs

CC  = gcc

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) Makefile ft_printf.h
	$(LIB) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
