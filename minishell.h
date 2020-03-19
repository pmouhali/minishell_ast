// 42 HEADER

#ifndef MINISHELL_H
# define MINISHELL_H

// TODO: rm stdio inc when project is complete
#include <stdio.h>

#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

#define ABS(x) x > 0 ? x : -x 

char **environment;

// ENV UTILS
int     valid_envar_name(const char *n);
char    		*get_key_value(char **tab, char *key);
int  			keycmp(char *str, char *key);
int     push_envar(const char *str);


// BUILTINS
int		export(char *args[]);

// ERROR MANAGEMENT
void    ft_perrorc(const char *from, const char *arg, const char *msg);

char **environment;

int             change_dir(char **arg);

#endif
