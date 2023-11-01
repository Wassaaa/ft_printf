NAME =		libftprintf.a
OBJ_D =		obj

SRCS =		ft_printf.c \
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



B_SRCS=		prf_init_flags_bonus.c\
			prf_parse_flags_bonus.c\
			prf_print_d_bonus.c\
			prf_printf_bonus.c\
			prf_width_perc_bonus.c\



OBJECTS =	$(addprefix $(OBJ_D)/, $(SRCS:%.c=%.o))

B_OBJ	=	$(addprefix $(OBJ_D)/, $(B_SRCS:%.c=%.o))

CFLAGS +=	-Wall -Wextra -Werror

IFLAGS =	-I. -Ilibft/

LIBFT_N =	./libft/libft.a

LIBFT_D =	./libft --no-print-directory


all: $(LIBFT_N) $(NAME)

$(LIBFT_N):
	make -C $(LIBFT_D)
	cp libft/libft.a .
	mv libft.a $(NAME)

$(NAME): $(OBJECTS)
		ar -rcs $@ $^

$(OBJ_D)/%.o: %.c
		mkdir -p $(@D)
		clang $(CFLAGS) $(IFLAGS) -c $< -o $@

bonus: .bonus

.bonus: all $(B_OBJ)
		cc -o $@ $^
		@touch .bonus

clean:
		rm -rf $(OBJ_D)
		make clean -C $(LIBFT_D)
		@rm -f .bonus

fclean: clean
		rm -f $(NAME)
		make -C libft fclean

re: fclean all

.PHONY: all re clean fclean bonus libftall
