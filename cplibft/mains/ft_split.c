#include "libft.h"
#include <string.h> 

int		split_cmp_array(char **exp, char **got)
{
	while (*exp)
	{
		if (*got == NULL || strcmp(*exp, *got))
			return (-1);
		exp++;
		got++;
	}
	return (0);
}

void	ft_free_str_array(char **a)
{
	int i = 0;
	while (a[i])
	{
		free(a[i]);
		i++;
	}
	free(a[i]);
}

void	ft_putstr_array(char **a)
{
	int i = 0;
	while (a[i])
	{
		ft_putendl_fd(a[i], 1);
		i++;
	}
}

int		main(void)
{
	char **got;
	char *e;

ft_putstr_fd("            With backslash zero as delimiter : ", 1);
	char **exp10 = (char*[1]){NULL};
	e = ft_strdup("");
	got = ft_split(e, '\0');
	if (split_cmp_array(exp10, got))
	{
		ft_putendl_fd("KO", 1);
		ft_putstr_array(got);
		ft_putendl_fd("instead of expected :", 1);
		ft_putstr_array(exp10);
	}
	else
		ft_putendl_fd("OK", 1);
	free(e);
	ft_free_str_array(got);

ft_putstr_fd("With delimiters at the start, middle and end : ", 1);
	char **exp1 = (char*[6]){"Now", "is", "the", "winter", "of", NULL};
	e = ft_strdup(" Now is the  winter   of ");
	got = ft_split(e, ' ');
	if (split_cmp_array(exp1, got))
	{
		ft_putendl_fd("KO", 1);
		ft_putstr_array(got);
		ft_putendl_fd("instead of expected :", 1);
		ft_putstr_array(exp1);
	}
	else
		ft_putendl_fd("OK", 1);
	free(e);
	ft_free_str_array(got);

ft_putstr_fd("With delimiters at the start, middle and end : ", 1);
	char **expc2 = (char*[3]){"N", "o", NULL};
	e = ft_strdup(" N o");
	got = ft_split(e, ' ');
	if (split_cmp_array(expc2, got))
	{
		ft_putendl_fd("KO", 1);
		ft_putstr_array(got);
		ft_putendl_fd("instead of expected :", 1);
		ft_putstr_array(expc2);
	}
	else
		ft_putendl_fd("OK", 1);
	free(e);
	ft_free_str_array(got);

ft_putstr_fd("With delimiters at the start, middle and end : ", 1);
	char **expc1 = (char*[2]){"a", NULL};
	e = ft_strdup("a");
	got = ft_split(e, ' ');
	if (split_cmp_array(expc1, got))
	{
		ft_putendl_fd("KO", 1);
		ft_putstr_array(got);
		ft_putendl_fd("instead of expected :", 1);
		ft_putstr_array(expc1);
	}
	else
		ft_putendl_fd("OK", 1);
	free(e);
	ft_free_str_array(got);

ft_putstr_fd("           With delimiters at the start only : ", 1);
	char **exp2 = (char*[2]){"our", NULL};
	e = ft_strdup("        our");
	got = ft_split(e, ' ');
	if (split_cmp_array(exp2, got))
	{
		ft_putendl_fd("KO", 1);
		ft_putstr_array(got);
		ft_putendl_fd("instead of expected :", 1);
		ft_putstr_array(exp2);
	}
	else
		ft_putendl_fd("OK", 1);
	free(e);
	ft_free_str_array(got);

ft_putstr_fd("          With delimiters in the middle only : ", 1);
	char **exp3 = (char*[5]){"discontent,", "made", "glorious", "summer", NULL};
	e = ft_strdup("discontent, made glorious summer");
	got = ft_split(e, ' ');
	if (split_cmp_array(exp3, got))
	{
		ft_putendl_fd("KO", 1);
		ft_putstr_array(got);
		ft_putendl_fd("instead of expected :", 1);
		ft_putstr_array(exp3);
	}
	else
		ft_putendl_fd("OK", 1);
	free(e);
	ft_free_str_array(got);

ft_putstr_fd("             With delimiters at the end only : ", 1);
	char **exp4 = (char*[2]){"by", NULL};
	e = ft_strdup("by       ");
	got = ft_split(e, ' ');
	if (split_cmp_array(exp4, got))
	{
		ft_putendl_fd("KO", 1);
		ft_putstr_array(got);
		ft_putendl_fd("instead of expected :", 1);
		ft_putstr_array(exp4);
	}
	else
		ft_putendl_fd("OK", 1);
	free(e);
	ft_free_str_array(got);

ft_putstr_fd("                        With delimiters only : ", 1);
	char **exp5 = (char*[1]){NULL};
	e = ft_strdup("        ");
	got = ft_split(e, ' ');
	if (split_cmp_array(exp5, got))
	{
		ft_putendl_fd("KO", 1);
		ft_putstr_array(got);
		ft_putendl_fd("instead of expected :", 1);
		ft_putstr_array(exp5);
	}
	else
		ft_putendl_fd("OK", 1);
	free(e);
	ft_free_str_array(got);

ft_putstr_fd("                           With empty string : ", 1);
	char **exp6 = (char*[1]){NULL};
	e = ft_strdup("");
	got = ft_split(e, ' ');
	if (split_cmp_array(exp6, got))
	{
		ft_putendl_fd("KO", 1);
		ft_putstr_array(got);
		ft_putendl_fd("instead of expected :", 1);
		ft_putstr_array(exp6);
	}
	else
		ft_putendl_fd("OK", 1);
	free(e);
	ft_free_str_array(got);

ft_putstr_fd("            With no delimiters in the string : ", 1);
	char **exp7 = (char*[2]){"by this sun", NULL};
	e = ft_strdup("by this sun");
	got = ft_split(e, 0);
	if (split_cmp_array(exp7, got))
	{
		ft_putendl_fd("KO", 1);
		ft_putstr_array(got);
		ft_putendl_fd("instead of expected :", 1);
		ft_putstr_array(exp7);
	}
	else
		ft_putendl_fd("OK", 1);
	free(e);
	ft_free_str_array(got);
}

/* Be careful : allocate only the required space */
/* free the array if an issue occurs before end of process */
