NAME		= push_swap
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS		= push_swap.c \
			array_util.c \
			array.c \
			introduction_rr.c \
			introduction_rrr.c \
			introduction_sspa.c \
			sort_rotate.c \
			sort_rotate_util.c \
			sort_util.c \
			sort.c

OBJS		= $(SRCS:%.c=%.o)

LIBC		= ar rc

FLAGS		= -Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		make all -C $(LIBFT)/
		gcc -o $(NAME) $(OBJS) -Llibft -lft

%.o			:	%.c
		gcc $(FLAGS) -c $^ -I./ -o $@


clean		:
		rm -f $(OBJS)
		make clean -C $(LIBFT)

fclean		:	clean
		rm -f $(NAME)
		rm -f $(LIBFT_LIB)
		make fclean -C $(LIBFT)

re			:	fclean all

.PHONY		:	all clean fclean re bonus
