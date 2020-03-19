#include <stdio.h>
#include "../minishell.h"

int	main(int ac, char **av, char **envp)
{
    environment = (char**)ft_tabdup((const void**)envp, (void*)&ft_strdup);
    char path[PATH_MAX];
    printf("tests for cd:\n");

    // char *tab[] = {"CD", "dontexist", NULL};
    // printf("PATH BEFORE= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);
	// printf("expected 1 got %d\n", change_dir(tab));
    // printf("PATH AFTER= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);

    // char *tab2[] = {"CD", "/root", NULL};
    // printf("PATH BEFORE= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);
	// printf("expected 1 got %d\n", change_dir(tab2));
    // printf("PATH AFTER= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);

    // char *tab3[] = {"CD", "libft", NULL};
    // printf("PATH BEFORE= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);
	// printf("expected 0 got %d\n", change_dir(tab3));
    // printf("PATH AFTER= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);

    // char *tab4[] = {"CD", NULL};
    // printf("PATH BEFORE= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);
	// printf("expected 0 got %d\n", change_dir(tab4));
    // printf("PATH AFTER= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);

    // char *tab5[] = {"CD", "~", NULL};
    // printf("PATH BEFORE= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);
	// printf("expected 0 got %d\n", change_dir(tab5));
    // printf("PATH AFTER= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);

    // char *tab6[] = {"CD", ".", NULL};
    // printf("PATH BEFORE= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);
	// printf("expected 0 got %d\n", change_dir(tab6));
    // printf("PATH AFTER= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);

    // char *tab7[] = {"CD", "~usernamedontexist", NULL};
    // printf("PATH BEFORE= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);
	// printf("expected 1 got %d\n", change_dir(tab7));
    // printf("PATH AFTER= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);

    // char *tab8[] = {"CD", "~test", NULL}; //change with username exist
    // printf("PATH BEFORE= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);
	// printf("expected 0 got %d\n", change_dir(tab8));
    // printf("PATH AFTER= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);

    // char *tab9[] = {"CD", "Makefile", NULL};
    // printf("PATH BEFORE= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);
	// printf("expected 1 got %d\n", change_dir(tab9));
    // printf("PATH AFTER= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);

    // char *tab10[] = {"CD", "~root", NULL};
    // char **tab11;
    // tab11 = (char**)ft_tabdup((const void**)tab10, (void*)&ft_strdup);
    // printf("PATH BEFORE= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);
	// printf("expected 1 got %d\n", change_dir(tab11));
    // printf("PATH AFTER= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);
    // ft_tabfree((void**)tab11);

    // char *tab12[] = {"CD", "..", NULL};
    // printf("PATH BEFORE= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);
	// printf("expected 0 got %d\n", change_dir(tab12));
    // printf("PATH AFTER= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);

    // char *tab13[] = {"CD", "-", NULL}; //try also with OLPWD desactivate then expect 1
    // printf("PATH BEFORE= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);
	// printf("expected 0 got %d\n", change_dir(tab13));
    // printf("PATH AFTER= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);

    // char *tab13[] = {"CD", "caca", "bite", NULL};
    // printf("PATH BEFORE= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);
	// printf("expected 1 got %d\n", change_dir(tab13));
    // printf("PATH AFTER= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);

    ft_tabfree((void**)environment);
}