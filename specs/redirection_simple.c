#include "minishell.h"

int		main(int ac, char **av, char **envp)
{
	environment = (char**)ft_tabdup((const void**)envp, (void*)&ft_strdup); // sert à simuler l'environnment (on en a besoin pour execve principalement)

	char **args = (char**)ft_tabdup((const void**)&av[1], (void*)&ft_strdup);


	t_node *n = btree_node_new(COMMAND, args);


	int fd, fd2;
	int stdout_fd;

	fd = open("TEST.TXT", O_CREAT | O_APPEND | O_WRONLY);
	fd2 = open("CHICK.TXT", O_CREAT | O_TRUNC | O_WRONLY);

	printf("STDOUT at begining : %d\n", STDOUT_FILENO);

	stdout_fd = dup(STDOUT_FILENO);

	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(1);
	}
	if (dup2(fd2, STDOUT_FILENO) == -1)
	{
		perror("dup2-2");
		exit(1);
	}


	run_process(n, NULL);

	close(fd);
	close(fd2);
	dup2(stdout_fd, STDOUT_FILENO);
	close(stdout_fd);

	write(STDOUT_FILENO, "Can u see me ?\n", strlen("can u see me ?\n"));

	printf("STDOUT at the end : %d\n", STDOUT_FILENO);

	ft_tabfree((void**)environment);	
	btree_delete(n);
	return (0);
}





