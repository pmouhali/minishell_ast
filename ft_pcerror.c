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
	if (from)
	{
		ft_putstr(from);	
		ft_putstr(":");
	}
	if (arg)
	{
		ft_putstr(arg);	
		ft_putstr(":");
	}
	if (msg)
		ft_putstr(from);	
	ft_putstr("\n");
}
