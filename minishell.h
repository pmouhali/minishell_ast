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
int     valid_envar_id(const char *n);
char    *get_key_value(char **tab, char *key);
int     keycmp(char *str, char *key);
int     push_envar(const char *str);


// BUILTINS
int		ft_export(char *args[]);
int		echo(char *args[]);
int		env(char *args[]);
int     change_dir(char *arg[]);
int     ft_unset(char *arg[]);

// ERROR MANAGEMENT
void    ft_perrorc(const char *from, const char *arg, const char *msg);

char **environment;


#endif
