// 42 HEADER

#ifndef MINISHELL_H
# define MINISHELL_H

// TODO: rm stdio inc when project is complete
#include <stdio.h>

#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>


#define ABS(x) x > 0 ? x : -x // who are u ? what are u doin here ?

#define COMMAND_NOT_FOUND 1270 
#define RDEND 0
#define WREND 1

enum	e_node_type
{
	COMMAND,
	REDIR_OUT_1,
	REDIR_OUT_2,
	REDIR_IN_1,
	PIPE,
	AND,
	OR,
	OPERATOR_ARG
};

typedef struct	s_node
{
	enum e_node_type type;
	char **args;
	struct s_node *left;
	struct s_node *right;
}				t_node;

typedef struct	s_options
{
	int	current_pwrite;
	int	current_pread;
	int	previous_pwrite;
	int	previous_pread;

}				t_options;

typedef int		(*t_eval_node_function)(t_node *n, t_options *options);

typedef int		(*t_builtin_function)(char *args[]);

char **environment;

// PROCESS MANAGEMENT
int		process_container(t_node *root);
int		eval_node(t_node *node, t_options *options);
int		run_process(t_node *n, t_options *options);
int     redirect_out_trunc(t_node *n, t_options *options);
int     redirect_out_append(t_node *n, t_options *options);
int     redirect_in(t_node *n, t_options *options);
int     pipe_processes(t_node *n, t_options *options);

// PROCESS UTILS
int     isbuiltin(char *bname);
int     call_builtin_function(int builtin_index, char *args[]);
char    *isbinary(char *bname);

// FD UTILS
int     close_pipe(int *read_end, int *write_end);

char    *try_path(char *path);
char    *build_path(char *paths, char *bname);

// BTREE UTILS
void	btree_delete(t_node *node);
t_node  *btree_node_new(int type, char **args);

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
int		ft_pwd(char *arg[]);

// ERROR MANAGEMENT
void    ft_perrorc(const char *from, const char *arg, const char *msg);

#endif
