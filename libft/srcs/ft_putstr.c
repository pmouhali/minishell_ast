// 42 HEADER

#include "libft.h"

void	ft_putstr(const char *str)
{
	write(1, str, ft_strlen(str));
}
