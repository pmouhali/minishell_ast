#include "minishell.h"
#include "stdio.h"

int main(int argc, char **argv, char **envp)
{
    char s[PATH_MAX];
    char *arg[] = {"cd",
                    NULL};
    environment = (char**)ft_tabdup((const void**)envp, (void*)ft_strdup);
    printf("%s\n", getcwd(s, PATH_MAX));
    change_dir(arg);
    printf("%s\n", getcwd(s, PATH_MAX));
    // ft_tabprint((const void**)environment, (void*)ft_putstr);
    return (0);
}