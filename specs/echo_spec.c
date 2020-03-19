#include "../minishell.h"
#include <stdio.h>

/*
**	echo
**	$
**	echo -n
**	%
**	echo arg1 arg2 arg3
**	arg1 arg2 arg3$
**
**	echo -n arg1 arg2 arg3
**	arg1 arg2 arg3%
**
**	echo -n -n -n -n -n arg1 arg2 arg3
**	arg1 arg2 arg3%
**
**	echo -n -n -n -n -n arg1 arg2 arg3 -n -n
**	arg1 arg2 arg3 -n -n%
*/

int	main(int ac, char **av)
{
	return(echo(av));
}
