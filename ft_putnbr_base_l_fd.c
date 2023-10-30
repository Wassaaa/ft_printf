#include "ft_printf.h"

static size_t	print_base(long nbr, size_t len, char *base, int fd)
{
	static size_t	digits = 0;

	if (nbr >= len)
		print_base(nbr / len, len, base, fd);
	ft_putchar_fd(base[abs_val(nbr) % len], fd);
	digits++;
	return (digits);
}

int	ft_putnbr_base_l_fd(long nbr, char *base, int fd)
{
	size_t base_len;

	base_len = ft_strlen(base);
	return (print_base(nbr, base_len, base, fd));
}