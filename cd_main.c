#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
    char 
    environment = (char**)ft_tabdup((const void**)envp, (void*)ft_strdup);
    change_dir(argv);
    // ft_tabprint((const void**)environment, (void*)ft_putstr);
    return (0);
}