#include "libft.h"
#include <string.h> 

void	ft_putstr(char *s) { write(1, s, ft_strlen(s)); }
void	ft_putendl(char *s) { write(1, s, ft_strlen(s)); write(1, "\n", 1); }

int		main(void)
{
	char *s;
	char *e;
	char *set;
	
	set = ft_strdup("");
ft_putstr("          with backslash zero as set included character : ");
	e = ft_strdup("LOL");
	s = ft_strtrim(e, set);
	if (strcmp(s, "LOL"))
	{
		ft_putstr("KO : ");
		ft_putendl(s);
	}
	else
		ft_putendl("OK");
	free(s);
	free(e);
	free(set);

	set = ft_strdup(" x6");

ft_putstr("with set included characters at start and end of string : ");
	e = ft_strdup(" x6HELL666HELL6x ");
	s = ft_strtrim(e, set);
	if (strcmp(s, "HELL666HELL"))
	{
		ft_putstr("KO : ");
		ft_putendl(s);
	}
	else
		ft_putendl("OK");
	free(s);
	free(e);

ft_putstr("   with set included characters only at start of string : ");
	e = ft_strdup(" x6HELL666HELL");
	s = ft_strtrim(e, set);
	if (strcmp(s, "HELL666HELL"))
	{
		ft_putstr("KO : ");
		ft_putendl(s);
	}
	else
		ft_putendl("OK");
	free(s);
	free(e);

ft_putstr("     with set included characters only at end of string : ");
	e = ft_strdup("HELL666HELL6x ");
	s = ft_strtrim(e, set);
	if (strcmp(s, "HELL666HELL"))
	{
		ft_putstr("KO : ");
		ft_putendl(s);
	}
	else
		ft_putendl("OK");
	free(s);
	free(e);

ft_putstr("        with set included characters only in the middle : ");
	e = ft_strdup("HELL6 xx6 xx6xxx HELL");
	s = ft_strtrim(e, set);
	if (strcmp(s, "HELL6 xx6 xx6xxx HELL"))
	{
		ft_putstr("KO : ");
		ft_putendl(s);
	}
	else
		ft_putendl("OK");
	free(s);
	free(e);

ft_putstr("     with a string only made of set included characters : ");
	e = ft_strdup(" 666x xx xxx6");
	s = ft_strtrim(e, set);
	if (strcmp(s, ""))
		ft_putendl("KO : does not return an empty string");
	else
		ft_putendl("OK");
	free(s);
	free(e);

	free(set);
ft_putstr("                           with an empty characters set : ");
	e = ft_strdup(" x6HELL666HELL6x ");
	set = ft_strdup("");
	s = ft_strtrim(e, set);
	if (strcmp(s, " x6HELL666HELL6x "))
	{
		ft_putstr("KO : ");
		ft_putendl(s);
	}
	else
		ft_putendl("OK");
	free(s);
	free(e);
	
	free(set);

ft_putstr("                                   with an empty string : ");
	e = ft_strdup("");
	set = ft_strdup("6x ");
	s = ft_strtrim(e, "");
	if (strcmp(s, ""))
		ft_putendl("KO : does not return an empty string");
	else
		ft_putendl("OK");
	free(s);

	free(set);
}

/* Be careful to allocate only the required space ! */
/* Be careful to what happens when a NULL parameters is sent ! */
