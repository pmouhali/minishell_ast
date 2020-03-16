#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
    environment = envp;
    change_dir(argv);
}