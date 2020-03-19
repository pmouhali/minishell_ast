#include <stdio.h>
#include "../minishell.h"

int	main(int ac, char **av, char **envp)
{
    environment = (char**)ft_tabdup((const void**)envp, (void*)&ft_strdup);
    char path[PATH_MAX];
    printf("tests for cd:\n");

    // char *tab[] = {"CD", NULL};
    // printf("PATH BEFORE= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);
	// printf("expected 0 got %d\n", change_dir(tab));
    // printf("PATH AFTER= %s\n", getcwd(path, PATH_MAX));
    // // ft_tabprint((const void **)environment, (void*)ft_putstr);

    // char *tab2[] = {"CD", "1", "2", NULL};
    // printf("PATH BEFORE= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);
	// printf("expected 1 got %d\n", change_dir(tab2));
    // printf("PATH AFTER= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);

    // char *tab3[] = {"CD", "libft", "libft", NULL};
    // printf("PATH BEFORE= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);
	// printf("expected 1 got %d\n", change_dir(tab3));
    // printf("PATH AFTER= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);

    // char *tab4[] = {"CD", "libft", NULL};
    // printf("PATH BEFORE= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);
	// printf("expected 0 got %d\n", change_dir(tab4));
    // printf("PATH AFTER= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);

    // char *tab5[] = {"CD", "..", NULL};
    // printf("PATH BEFORE= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);
	// printf("expected 0 got %d\n", change_dir(tab5));
    // printf("PATH AFTER= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);

    // char *tab6[] = {"CD", "1", NULL};
    // printf("PATH BEFORE= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);
	// printf("expected 1 got %d\n", change_dir(tab6));
    // printf("PATH AFTER= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);

    // char *tab7[] = {"CD", ".", NULL};
    // printf("PATH BEFORE= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);
	// printf("expected 0 got %d\n", change_dir(tab7));
    // printf("PATH AFTER= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);

    // char *tab8[] = {"CD", "~caca", NULL}; //change with username
    // printf("PATH BEFORE= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);
	// printf("expected 0 got %d\n", change_dir(tab8));
    // printf("PATH AFTER= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);

    // char *tab9[] = {"CD", "dir", NULL};
    // printf("PATH BEFORE= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);
	// printf("expected 0 got %d\n", change_dir(tab));
    // printf("PATH AFTER= %s\n", getcwd(path, PATH_MAX));
    // // ft_tabprint((const void **)environment, (void*)ft_putstr);

    // char *tab10[] = {"CD", "-", NULL};
    // printf("PATH BEFORE= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);
	// printf("expected 0 got %d\n", change_dir(tab));
    // printf("PATH AFTER= %s\n", getcwd(path, PATH_MAX));
    // // ft_tabprint((const void **)environment, (void*)ft_putstr);

    // char *tab11[] = {"CD", "~", NULL};
    // printf("PATH BEFORE= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);
	// printf("expected 0 got %d\n", change_dir(tab));
    // printf("PATH AFTER= %s\n", getcwd(path, PATH_MAX));
    // // ft_tabprint((const void **)environment, (void*)ft_putstr);

    // char *tab12[] = {"CD", "Makefile", NULL};
    // printf("PATH BEFORE= %s\n", getcwd(path, PATH_MAX));
    // ft_tabprint((const void **)environment, (void*)ft_putstr);
	// printf("expected 1 got %d\n", change_dir(tab));
    // printf("PATH AFTER= %s\n", getcwd(path, PATH_MAX));
    // // ft_tabprint((const void **)environment, (void*)ft_putstr);

    ft_tabfree((void**)environment);
}