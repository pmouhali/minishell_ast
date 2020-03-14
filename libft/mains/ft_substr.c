#include "libft.h"
#include <stdio.h> 
void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}
void	ft_putendl(char *s)
{
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}

int		main(void)
{
	char *s;
	char *e;

ft_putstr("Start bigger than  strlen : ");
	e = ft_strdup("abcdefghijklmnop");
	s = ft_substr(e, 400, 10);
	if (strcmp("", s))
	{
		ft_putstr_fd("Expected empty string. Got : ", 1);
		ft_putendl_fd(s, 1);
	}
	else
		ft_putendl_fd("OK", 1);
	free(s);
	free(e);

ft_putstr("Length smaller than strlen : ");
	e = ft_strdup("abcdefghijklmnop");
	s = ft_substr(e, 3, 10);
	if (strcmp(s, "defghijklm"))
	{
		ft_putstr_fd("Expected defghijklm. Got : ", 1);
		ft_putendl_fd(s, 1);
	}
	else
		ft_putendl_fd("OK", 1);
	free(s);
	free(e);

ft_putstr("String of 1 char, len 1, start 0 : ");
	e = ft_strdup("a");
	s = ft_substr(e, 0, 1);
	if (strcmp(s, "a"))
	{
		ft_putstr_fd("Expected a Got : ", 1);
		ft_putendl_fd(s, 1);
	}
	else
		ft_putendl_fd("OK", 1);
	free(s);
	free(e);

ft_putstr("String of 1 char, len 1, start 1 : ");
	e = ft_strdup("a");
	s = ft_substr(e, 1, 1);
	if (strcmp(s, ""))
	{
		ft_putstr_fd("Expected  Got : ", 1);
		ft_putendl_fd(s, 1);
	}
	else
		ft_putendl_fd("OK", 1);
	free(s);
	free(e);

ft_putstr("String of 1 char, len 2, start 1 : ");
	e = ft_strdup("a");
	s = ft_substr(e, 1, 2);
	if (strcmp(s, ""))
	{
		ft_putstr_fd("Expected  Got : ", 1);
		ft_putendl_fd(s, 1);
	}
	else
		ft_putendl_fd("OK", 1);
	free(s);
	free(e);

ft_putstr("Length bigger than strlen : ");
	e = ft_strdup("abcdefg");
	s = ft_substr(e, 3, 10);
	if (strcmp(s, "defg"))
	{
		ft_putstr_fd("Expected defg. Got : ", 1);
		ft_putendl_fd(s, 1);
	}
	else
		ft_putendl_fd("OK", 1);
	free(s);
	free(e);

ft_putstr("Strlen shorter than length, index point to last char : ");
	e = ft_strdup("abcdef");
	s = ft_substr(e, 5, 10);
	if (strcmp(s, "f"))
	{
		ft_putstr_fd("Expected f. Got : ", 1);
		ft_putendl_fd(s, 1);
	}
	else
		ft_putendl_fd("OK", 1);
	free(s);
	free(e);

ft_putstr("Strlen shorter than length, index point to null char : ");
	e = ft_strdup("abcdef");
	s = ft_substr(e, 6, 10);
	if (strcmp(s, ""))
	{
		ft_putstr_fd("Expected empty string. Got : ", 1);
		ft_putendl_fd(s, 1);
	}
	else
		ft_putendl_fd("OK", 1);
	free(s);
	free(e);

ft_putstr("Empty string and index is null char : ");
	e = ft_strdup("");
	s = ft_substr(e, 0, 10);
	if (strcmp(s, ""))
	{
		ft_putstr_fd("Expected empty string. Got : ", 1);
		ft_putendl_fd(s, 1);
	}
	else
		ft_putendl_fd("OK", 1);
	free(s);
	free(e);

ft_putstr("Length of zero with random string and index correct : ");
	e = ft_strdup("abcdefghijklmnop");
	s = ft_substr(e, 3, 0);
	if (strcmp(s, ""))
	{
		ft_putstr_fd("Expected empty string. Got : ", 1);
		ft_putendl_fd(s, 1);
	}
	else
		ft_putendl_fd("OK", 1);
	free(s);
	free(e);
}

/* Be careful : do not allocate total lenght is str is too short ! */
