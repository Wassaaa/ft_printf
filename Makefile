NAME		=	libftprintf.a
OBJ_DIR		=	obj

SRCS		=	ft_printf.c \
				ft_putnbr_base_ul_fd.c \
				ft_putnbr_ul_fd.c \
				prf_print_c.c \
				prf_print_s.c \
				prf_print_p.c \
				prf_print_d.c \
				prf_print_u.c \
				prf_print_x.c \
				prf_parse_spec.c \
				prf_init_print.c \
				count_digits.c \

OBJECTS		=	$(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

B_OBJ		=	$(addprefix $(OBJ_DIR)/, $(B_SRCS:%.c=%.o))

CC			=	gcc

CFLAGS		+=	-Wall -Wextra -Werror -g

IFLAGS		=	-I. -Ilibft

LIBFT_NAME	=	./libft/libft.a

LIBFT_DIR	=	./libft

all: $(LIBFT_NAME) $(NAME)

$(LIBFT_NAME):
					make -C $(LIBFT_DIR)

$(NAME): $(OBJECTS)
					cp $(LIBFT_DIR)/libft.a .
					mv libft.a $(NAME)
					ar rcs $(NAME) $(OBJECTS)

$(OBJ_DIR)/%.o: %.c
					mkdir -p $(@D)
					$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
					rm -rf $(OBJ_DIR)
					make clean -C $(LIBFT_DIR)
					@rm -f .bonus

fclean: clean
					rm -f $(NAME)
					make -C libft fclean

re: fclean all

.PHONY: all re clean fclean bonus
