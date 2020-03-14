#include "libft.h"
#include <string.h> 

int		main(void)
{
	char *s;

	ft_putendl_fd("With two random strings : ", 1);
	s = ft_strjoin("Now is the winter", "of our disontent");
	if (strcmp(s, "Now is the winterof our disontent"))
	{
		ft_putstr_fd("Expected : Now is the winterof our disontent Got : ", 1);
		ft_putendl_fd(s, 1);
	}
	else
		ft_putendl_fd("OK", 1);
	free(s);

	ft_putendl_fd("With two random strings of 1 char : ", 1);
	s = ft_strjoin("N", "o");
	if (strcmp(s, "No"))
	{
		ft_putstr_fd("Expected : No Got : ", 1);
		ft_putendl_fd(s, 1);
	}
	else
		ft_putendl_fd("OK", 1);
	free(s);

	ft_putendl_fd("With the first string empty : ", 1);
	s = ft_strjoin("", "Made glorious");
	if (strcmp(s, "Made glorious"))
	{
		ft_putstr_fd("Expected : Made glorious Got : ", 1);
		ft_putendl_fd(s, 1);
	}
	else
		ft_putendl_fd("OK", 1);
	free(s);
	
	ft_putendl_fd("With the second string empty :", 1);
	s = ft_strjoin("summer by this Sun of York;", "");
	if (strcmp(s, "summer by this Sun of York;"))
	{
		ft_putstr_fd("Expected : summer by this Sun of York; Got : ", 1);
		ft_putendl_fd(s, 1);
	}
	else
		ft_putendl_fd("OK", 1);
	free(s);

	ft_putendl_fd("With the two strings empty :", 1);
	s = ft_strjoin("", "");
	if (strcmp(s, ""))
	{
		ft_putstr_fd("Expected : Got : ", 1);
		ft_putendl_fd(s, 1);
	}
	else
		ft_putendl_fd("OK", 1);
	free(s);
}
