/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_tool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 16:01:21 by suzie             #+#    #+#             */
/*   Updated: 2020/03/18 11:41:59 by suzie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

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
**	corresponding string, if it was found, or NULL;
**
*/

char    *get_key_value(char **tab, char *key)
{
	int i;

    i = ft_tabindex((const void**)tab, (const void*)key, (void*)&keycmp);
	if (i == -1)
		return (NULL);
	return ((tab[i]) + ft_strlen(key) + 1);
}

/*
**	[NAME] : keycmp 
**	[DESCRIPTION] :
**	check if the given string match the given key
**	the string must be like "KEY=VALUE", this string match the key "KEY"
**
**	[RETURN VALUES]
**	returns 0 if this is a match, 1 if not
*/

int  keycmp(char *str, char *key)
{
    unsigned int i;

	i = 0;
	while (str[i] == key[i] && key[i] != '\0' && key[i] != '=' && str[i] != '\0')
		i++;
	if (str[i] == '=' || !str[i])
		return (0);
	return (1);
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
**	push the given environment variable in the environment array
**	the variable must be passed as a string like "key=value"
**
**	if a variable already exists with the same key, it will be deleted
**	and replaced with the new key-content
**
**	if a variable exists with the same key, but the received variable have no
**	content, the received variable isn't push, no modifications are performed
**
**	[RETURN VALUES]
**	0 on succes, 1 on failure
*/

int		push_envar(const char *str)
{
	int i;
	int old_var_i;

	if (str == NULL)
		return (0);
	// isole key TEST=content TEST= TEST
	i = ft_index(str, '=');

	// check is exists
	//old_var_i = ft_tabindex(environment, key, (void*)keycmp);
	// delete + push
	//		or
	// push
	// return
}
