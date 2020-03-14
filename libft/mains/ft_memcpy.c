#include <string.h>
#include <stdio.h>

void	printab(char *desc, int *tab, int n)
{
	int i;
	
	printf("%s\n", desc);
	i = 0;
	while (i < n)
	{
		printf("%d | ", tab[i]);
		i++;
	}
	printf("\n");
}

void    *ft_memcpy(void *dest, const void *src, size_t n);

int		main(void)
{
	char str[10];
	char *src = "string";
	int tab[10];
	int i = 0;
//	char str2[10];
//	int tab2[10];

//	char - char | int - int | char - int | int - char | v - int | v - char

	memcpy(str, src, 7);
	printf("char to char, n < rsize === %s\n", str);

	memcpy(tab, &i, 8);
	printab("int to int, n < rsize", tab, 10);

	memcpy(str, &i, 7);
	printf("char to int, n < rsize === %s\n", str);

	memcpy(tab, src, 7);
	printab("int to char, n < rsize", tab, 10);

	src = "";
	memcpy(str, src, 9);
	printf("empy string on char, n < rsize === %s\n", str);


	char str2[10];
	int tab2[10];
	
	src = "string";
	printf("ft_ :\n");

	ft_memcpy(str2, src, 7);
	printf("char to char, n < rsize === %s\n", str2);

	printab("tab before :", tab2, 10);
	ft_memcpy(tab2, &i, 8);
	printab("int to int, n < rsize", tab2, 10);

	ft_memcpy(str2, &i, 7);
	printf("char to int, n < rsize === %s\n", str2);

	printab("tab before :", tab2, 10);
	ft_memcpy(tab2, src, 7);
	printab("int to char, n < rsize", tab2, 10);

	src = "";
	ft_memcpy(str2, src, 9);
	printf("empy string on char, n < rsize === %s\n", str2);

}
