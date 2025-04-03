NAME = libft.a

INCLUDE = libft.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

# command for removing files.
# The -f flag forces the deletion without asking for confirmation.
RM = rm -f

#This specifies the ar command for creating and managing archive files (static libraries).
#r- replace, s- add index to archive, c- create archive if it doesnt exist
AR = ar -rsc

SRC =	ft_atoi.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_itoa.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_putchar_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c\
		ft_split.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strmapi.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strtrim.c\
		ft_substr.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_lstnew_bonus.c\
		ft_lstadd_front_bonus.c\
		ft_lstsize_bonus.c\
		ft_lstlast_bonus.c\
		ft_lstadd_back_bonus.c\
		ft_lstdelone_bonus.c\
		ft_lstclear_bonus.c\
		ft_lstiter_bonus.c\
		ft_lstmap_bonus.c\
		ft_convert.c\
		ft_itoa_printf.c\
		ft_print.c\
		ft_printf.c\
		get_next_line.c
		

OBJS = $(SRC:.c=.o)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

# $@ -> becomes .o
# $^ -> becomes .c, input files
# cc -c -Wall -Wextra -Werror -o ft_strlen.o ft_strlen.c
# Compile (-c) and name the output (-o)
%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $^

# removes the object files
clean: 
	$(RM) $(OBJS)

# calls clean and also removes the library file(libft.a)
fclean: clean
	$(RM) $(NAME)

# calls fclean to remove all files and then all to recompile everything
re: fclean all

# label for a set of commands
# ensures that certain targets are always executed as commands
.PHONY: all clean fclean re
