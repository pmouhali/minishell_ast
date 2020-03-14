#include "libft.h"
#include <string.h> 

void	ft_putstr(char *s) { write(1, s, ft_strlen(s)); }
void	ft_putendl(char *s) { write(1, s, ft_strlen(s)); write(1, "\n", 1);}

char	ftest(unsigned int i, char c)
{
	i = 1;
	return (c + i);
}

int		main(void)
{
	char *exp;
	char *got;

ft_putstr("Random printable chars : ");
	got = ft_strmapi("abc + 123 ;", &ftest);
	exp = "bcd!,!234!<";
	if (strcmp(got, exp))
	{
		ft_putstr("KO : got : ");
		ft_putstr(got);
		ft_putstr(" expected : ");
		ft_putendl(exp);
	}
	else
		ft_putendl("OK");
	free(got);

ft_putstr("          Empty string : ");
	got = ft_strmapi("", &ftest);
	if (got)
	{
		ft_putstr("KO : got : ");
		ft_putstr(got);
		ft_putstr(" expected : NULL");

		free(got);
	}
	else
		ft_putendl("OK");
}
