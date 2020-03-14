#include <stdio.h>
#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n);

int		main(void)
{	
	char *s1;
	char *s2;
	char *s3;

	s1 = "string";
	s2 = "string";
	s3 = "strong";
	
	printf("o %d\n", memcmp(s1, s2, 7));
	printf("o %d\n", memcmp(s1, s3, 7));
	printf("o %d\n", memcmp(s1, s3, 0));
	printf("o %d\n", memcmp(s3, s1, 7));

	printf("f %d\n", ft_memcmp(s1, s2, 7));
	printf("f %d\n", ft_memcmp(s1, s3, 7));
	printf("f %d\n", ft_memcmp(s1, s3, 0));
	printf("f %d\n", ft_memcmp(s3, s1, 7));
}
