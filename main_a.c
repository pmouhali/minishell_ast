#include "minishell.h"

int		main(int ac, char **av, char **envp)
{
	environment = (char**)ft_tabdup((const void**)envp, (void*)&ft_strdup);

	char **args = (char**)ft_tabdup((const void**)&av[1], (void*)&ft_strdup);

	t_node *ast;

	ast = btree_node_new(COMMAND, args);

	int pc_r = process_container(ast);
	
	printf("process_container exit code = %d, %s\n", pc_r, strerror(pc_r));
	return (0);
}
