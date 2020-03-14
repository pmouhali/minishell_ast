#include <stdio.h>
#include <string.h>

void    *ft_memccpy(void *dest, const void *src, int c, size_t n);

int		main(void)
{
	char str1[] = "xxxxxxxxx";
	char str2[] = "xxxxxxxxx";
	char *src = "damdamdeo";
	char *rv;

	rv = memccpy(str1, src, 'e', 8);
	printf("after    memccpy: %s\n", str1);
	printf("   memccpy ret val: %s\n", rv);

	rv = ft_memccpy(str2, src, 'e', 8);
	printf("after ft_memccpy: %s\n", str2);
	printf("ft_memccpy ret val: %s\n\n", rv);

	char str5[] = "xxxxxxxxx";
	char str6[] = "xxxxxxxxx";

	rv = memccpy(str5, src, 'e', 7);
	printf("after    memccpy: %s\n", str5);
	printf("   memccpy ret val: %s\n", rv);

	rv = ft_memccpy(str6, src, 'e', 7);
	printf("after ft_memccpy: %s\n", str6);
	printf("ft_memccpy ret val: %s\n\n", rv);

	char str3[] = "xxxxxxxxx";
	char str4[] = "xxxxxxxxx";

	rv = memccpy(str3, src, 'r', 10);
	printf("after    memccpy: %s\n", str3);
	printf("   memccpy ret val: %s\n", rv);

	rv = ft_memccpy(str4, src, 'r', 10);
	printf("after ft_memccpy: %s\n", str4);
	printf("ft_memccpy ret val: %s\n\n", rv);

}
