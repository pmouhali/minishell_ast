// 42 HEADER

#ifndef MINISHELL_H
# define MINISHELL_H

#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

char **environment;

int             change_dir(char **arg);
char    		*get_key_value(char **tab, char *key);
int  			keycmp(char *str, char *key);
#endif
