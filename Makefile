CC = cc
CFLAGS = -Wall -Werror -Wextra

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

NAME = push_swap

RM = rm -f

SRC =	push_swap.c\
		input_error_check.c\
		sorting.c\
		sort_small_stacks.c\
		sort_big_stacks.c\
		find_val.c\
		ft_free.c\
		push.c\
		swap.c\
		rotate.c\
		rev_rotate.c\
		prepare_a.c\
		prepare_b.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
		make -C libft
	
$(NAME): $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
			$(CC) -c $(CFLAGS) -o $@ $^



clean:
		$(RM) $(OBJS)
		make -C $(LIBFT_DIR) clean
fclean: clean
		$(RM) $(NAME)
		make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
