// 42 HEADER

#ifndef MINISHELL_H
# define MINISHELL_H

#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

#define ABS(x) x > 0 ? x : -x 

char **environment;

// ENV UTILS
int     valid_envar_name(const char *n);

// BUILTINS
int		export(char *args[]);

// ERROR MANAGEMENT
void    ft_perrorc(const char *from, const char *arg, const char *msg);

char **environment;

int             change_dir(char **arg);
char    		*get_key_value(char **tab, char *key);
int  			keycmp(char *str, char *key);

#endif
