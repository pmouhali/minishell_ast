#include "libft.h"
#include <stdio.h>

void	lstdelone_f(void *a)
{
	free(a);
}
int	main(void)
{
/* PUSHBACK NULL STRUCT TEST 
	t_list *l2 = ft_lstnew(strdup("OK"));
	t_list *n2 = NULL;

	ft_lstadd_back(&l2, n2);
	if (l2->content)
		ft_putendl_fd("TEST_SUCCESS", 1);
	else
		ft_putendl_fd("TEST_FAILED", 1);
*/
/* DELONE TEST */
	
	t_list *l = ft_lstnew(strdup("test"));

	ft_lstdelone(l, lstdelone_f);
	if (l == NULL)
		ft_putendl_fd("TEST_SUCCESS", 1);
	else
	{
		ft_putendl_fd("TEST_FAILED : ", 1);
		printf("%s\n", l->content);	
	}

/* ADD FRONT & BACK TEST
	t_list *l = NULL;
	t_list *n = ft_lstnew(strdup("OK"));

	ft_lstadd_front(&l, n);
	if (l == n && !strcmp(l->content, "OK"))
	{
		ft_putendl_fd("TEST_SUCCESS", 1);
	}
	else
		ft_putendl_fd("TEST_FAILED", 1);

	t_list *l2 = NULL;
	t_list *n2 = ft_lstnew(strdup("OK"));

	ft_lstadd_back(&l2, n2);
	if (l2 == n2 && !strcmp(l2->content, "OK"))
	{
		ft_putendl_fd("TEST_SUCCESS", 1);
	}
	else
		ft_putendl_fd("TEST_FAILED", 1);
*/
}
