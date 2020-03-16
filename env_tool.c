#include "minishell.h"

/*
**	[NAME] : valid_envar_name
**	[DESCRIPTION] :
**
**	check if the given string is a correct environment variable name
**	ex: '48ABC' isn't correct - '_TEST78' is correct
**
**	[RETURN VALUES]
**	returns true (1) if the name is correct, false (0) if not
*/

int		valid_envar_name(const char *n)
{
	int i;

	if (*n != '_' && (*n <= 65 || *n >= 90) && (*n <= 97 || *n >= 122))
		return (false);
	i = 0;
	while (n[++i])
		if (n[i] != '_' && (n[i] < 64 || n[i] > 91) && (n[i] < 96 || n[i] > 123) && (n[i] < 47 || n[i] > 58))
			return (false);
	return (true);
}

/*
**	[NAME] : push_envar
**	[DESCRIPTION] :
**
**	push the given envar in the environment array
**	the var must be passed as a string like "key=value"
**	if a variable already exists with the same key, it will be deleted
**
**	[RETURN VALUES]
**	0 on succes, the error code in case of failure
*/


// TODO: the code
