NAME		= libftprintf.a
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS		= main.c

OBJS		= $(SRCS:%.c=%.o)

LIBC		= ar rc

FLAGS		= -Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		make all -C $(LIBFT)/
		cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
		$(LIBC) $(NAME) $(OBJS)
		gcc -o push_swap -C $(NAME) $(OBJS)

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
