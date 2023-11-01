NAME = libftprintf.a

SRCS =	ft_printf.c \
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
		ft_abs.c \
		count_digits.c \



B_SRCS= prf_init_flags_bonus.c\
		prf_parse_flags_bonus.c\
		prf_print_d_bonus.c\
		prf_printf_bonus.c\
		prf_width_perc_bonus.c\



OBJECTS = $(SRCS:.c=.o)

B_OBJ	= $(B_SRCS:.c=.o)

CFLAGS += -Wall -Wextra -Werror -g

LIBFT	= libft/libft.a

all: libftall $(NAME)

libftall:
	make -C libft

$(NAME): $(OBJECTS)
		ar -rcs $@ $^

$./%.o: $./%.c
		cc -I . -c $< -o $@

bonus: .bonus

.bonus: all $(B_OBJ)
		cc -o $@ $^ $(LIBFT)
		@touch .bonus

clean:
		rm -f $(OBJECTS) $(B_OBJ)
		make -C libft clean
		@rm -f .bonus

fclean: clean
		rm -f $(NAME)
		make -C libft fclean

re: fclean all

.PHONY: all re clean fclean bonus libftall
