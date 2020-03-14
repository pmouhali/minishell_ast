#include "libft.h"
#include <stdio.h> 

int	main(void)
{
	ft_putnbr_fd(ft_abs(-1), 1);
	ft_putnbr_fd(ft_abs(1), 1);
	ft_putnbr_fd(ft_abs(2147483647), 1);
	printf("%d", ft_abs(-2147483648));
}
