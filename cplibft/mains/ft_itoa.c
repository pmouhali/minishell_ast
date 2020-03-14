#include "libft.h"
#include <string.h>

void	ft_putstr(char *s) { write(1, s, ft_strlen(s)); }
void	ft_putendl(char *s) { write(1, s, ft_strlen(s)); write(1, "\n", 1); }

int		main(void)
{
	char *expected;
	char *got;

ft_putstr_fd("test overflow negatif : ", 1);
	expected = "idk";
	got = ft_itoa(-92147483647);
	if (strcmp(got, expected))
	{
		ft_putstr_fd("KO : got : ", 1);
		ft_putstr_fd(got, 1);
		ft_putstr_fd(" expected : ", 1);
		ft_putendl_fd(expected, 1);
	}
	else
		ft_putendl_fd("OK", 1);
	free(got);

ft_putstr_fd("test overflow positif : ", 1);
	expected = "idk";
	got = ft_itoa(777777101010101010101010101010101092147483647);
	if (strcmp(got, expected))
	{
		ft_putstr_fd("KO : got : ", 1);
		ft_putstr_fd(got, 1);
		ft_putstr_fd(" expected : ", 1);
		ft_putendl_fd(expected, 1);
	}
	else
		ft_putendl_fd("OK", 1);
	free(got);

ft_putstr_fd("test 1076452501 : ", 1);
	expected = "1076452501";
	got = ft_itoa(1076452501);
	if (strcmp(got, expected))
	{
		ft_putstr_fd("KO : got : ", 1);
		ft_putstr_fd(got, 1);
		ft_putstr_fd(" expected : ", 1);
		ft_putendl_fd(expected, 1);
	}
	else
		ft_putendl_fd("OK", 1);
	free(got);

ft_putstr("   test zéro : ");
	expected = "0";
	got = ft_itoa(0);
	if (strcmp(got, expected))
	{
		ft_putstr("KO : got : ");
		ft_putstr(got);
		ft_putstr(" expected : ");
		ft_putendl(expected);
	}
	else
		ft_putendl("OK");
	free(got);

ft_putstr("test int min : ");
	expected = "-2147483648";
	got = ft_itoa(-2147483648);
	if (strcmp(got, expected))
	{
		ft_putstr("KO : got : ");
		ft_putstr(got);
		ft_putstr(" expected : ");
		ft_putendl(expected);
	}
	else
		ft_putendl("OK");
	free(got);

ft_putstr("test int max : ");
	expected = "2147483647";
	got = ft_itoa(2147483647);
	if (strcmp(got, expected))
	{
		ft_putstr("KO : got : ");
		ft_putstr(got);
		ft_putstr(" expected : ");
		ft_putendl(expected);
	}
	else
		ft_putendl("OK");
	free(got);

ft_putstr("      test 1 : ");
	expected = "1";
	got = ft_itoa(1);
	if (strcmp(got, expected))
	{
		ft_putstr("KO : got : ");
		ft_putstr(got);
		ft_putstr(" expected : ");
		ft_putendl(expected);
	}
	else
		ft_putendl("OK");
	free(got);

ft_putstr("     test -1 : ");
	expected = "-1";
	got = ft_itoa(-1);
	if (strcmp(got, expected))
	{
		ft_putstr("KO : got : ");
		ft_putstr(got);
		ft_putstr(" expected : ");
		ft_putendl(expected);
	}
	else
		ft_putendl("OK");
	free(got);

ft_putstr("     test 10 : ");
	expected = "10";
	got = ft_itoa(10);
	if (strcmp(got, expected))
	{
		ft_putstr("KO : got : ");
		ft_putstr(got);
		ft_putstr(" expected : ");
		ft_putendl(expected);
	}
	else
		ft_putendl("OK");
	free(got);

ft_putstr("    test 100 : ");
	expected = "100";
	got = ft_itoa(100);
	if (strcmp(got, expected))
	{
		ft_putstr("KO : got : ");
		ft_putstr(got);
		ft_putstr(" expected : ");
		ft_putendl(expected);
	}
	else
		ft_putendl("OK");
	free(got);

ft_putstr("  test 99999 : ");
	expected = "99999";
	got = ft_itoa(99999);
	if (strcmp(got, expected))
	{
		ft_putstr("KO : got : ");
		ft_putstr(got);
		ft_putstr(" expected : ");
		ft_putendl(expected);
	}
	else
		ft_putendl("OK");
	free(got);

ft_putstr("  test -8887 : ");
	expected = "-8887";
	got = ft_itoa(-8887);
	if (strcmp(got, expected))
	{
		ft_putstr("KO : got : ");
		ft_putstr(got);
		ft_putstr(" expected : ");
		ft_putendl(expected);
	}
	else
		ft_putendl("OK");
	free(got);

}
