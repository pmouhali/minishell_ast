/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_tool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 16:01:21 by suzie             #+#    #+#             */
/*   Updated: 2020/03/18 15:02:03 by suzie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	[NAME] : get_key_value
**  [DESCRIPTION] :
**	use the 'keycmp' function to find the value of a key in a
**	two-dimensional array formatted as follow :
**
**	{"KEY=VALUE", "VAR=CONTENT", ..., NULL}
**
**	[RETURN VALUE] :
**	returns the value of the key, as a pointer to the start of the content in the
**	corresponding string, if it was found or NULL;
**
*/

char    *get_key_value(char **tab, char *key)
{
	int i;
	char *ret;
	
    i = ft_tabindex((const void**)tab, (const void*)key, (void*)&keycmp);
	if (i == -1)
		return (NULL);
	ret = (tab[i]) + ft_strlenn(key, '=');
	if (ret[0] == '=')
		return (ret + 1);
	else
		return (ret);
}

/*
**	[NAME] : keycmp 
**	[DESCRIPTION] :
**	check if the given string match the given key
**	the string must be like "KEY=VALUE"
**
**	[RETURN VALUES]
**	returns 0 if this is a match, -1 if not
*/

int  keycmp(char *str, char *key)
{
    unsigned int i;

	i = 0;
	while (str[i] == key[i] && key[i] != '\0' && key[i] != '=' && str[i] != '\0')
		i++;
	if (str[i] == '=' || !str[i])
		return (0);
	return (-1);
}

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
