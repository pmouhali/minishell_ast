#include "libft.h"

int		main(void)
{
	ft_putendl("0");
	ft_putnbr(0);
	ft_putendl("");
	ft_putendl("1");
	ft_putnbr(1);
	ft_putendl("");
	ft_putendl("-1");
	ft_putnbr(-1);
	ft_putendl("");
	ft_putendl("2147483647");
	ft_putnbr(2147483647);
	ft_putendl("");
	ft_putendl("-2147483648");
	ft_putnbr(-2147483648);
	ft_putendl("");
	ft_putendl("10");
	ft_putnbr(10);
	ft_putendl("");
	ft_putendl("45");
	ft_putnbr('-');
	ft_putendl("");

	ft_putendl("-57  2");
	ft_putnbr_fd(-57, 2);
	ft_putendl("");

	ft_putendl("164189");
	ft_putnbr_fd(164189, 1);
	ft_putendl("");

	ft_putendl("-987441  2");
	ft_putnbr_fd(-987441, 2);
	ft_putendl("");

	ft_putendl("2147483647");
	ft_putnbr_fd(2147483647, 1);
	ft_putendl("");

	ft_putendl("?  2");
	ft_putnbr_fd(-2147483648LL, 2);
	ft_putendl("");
}
