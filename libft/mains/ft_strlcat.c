#include "libft.h"
#include "string.h"

int	main(void)
{
	char *dest;
	char *dest2;

	if (!(dest = (char *)malloc(sizeof(*dest) * 15)))
		return (0);
	memset(dest, 0, 15);
	memset(dest, 'r', 6);

	memset(dest, 'r', 15);
	ft_putnbr_fd(strlcat(dest, "lorem ipsum dolor sit amet", 5), 1);
	ft_putendl_fd(dest, 1);

	if (!(dest2 = (char *)malloc(sizeof(*dest2) * 15)))
		return (0);
	memset(dest2, 0, 15);
	memset(dest2, 'r', 6);

	memset(dest2, 'r', 15);
	ft_putnbr_fd(ft_strlcat(dest2, "lorem ipsum dolor sit amet", 5), 1);
	ft_putendl_fd(dest2, 1);
}
