// 42 HEADER

/*
**	[NAME] :
**	ft_perrorc - stands for print error custom	
**
**	[DESCRIPTION] :
**	print an error message on STDERR
**	the message is build with the 3 optional arguments
**	':' is added after both of the 1st and 2scd argument if present
**
**	use for copy bash error's display behavior
*/

#include "minishell.h"

// TODO:
// SI ON GARDE CETTE FONCTION, L'OPTIMISER POUR EVITER TROIS APPELS A WRITE

void	ft_perrorc(const char *from, const char *arg, const char *msg)
{
	int fr;
	int ar;
	int ms;

	fr = ft_strlen(from);
	ar = ft_strlen(arg);
	ms = ft_strlen(msg);
	ft_dprintf(2, "%.*s%.*s%.*s%.*s%.*s\n",
	fr, from, ar ? 2 : 0, ": ",
	ar, arg, ms ? 2 : 0, ": ",
	ms, msg);
}
