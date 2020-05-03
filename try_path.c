/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:20:13 by pmouhali          #+#    #+#             */
/*   Updated: 2020/02/14 13:20:37 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Role : vérifier si le path corresponds à un executable
**
**	Vérifie si le path reçu existe dans le filesystem
**	Retourne null si le path n'existe pas
**
**	Si le path existe mais est un dossier, errno est set et la fonction
**	retourne null
*/

char	*try_path(char *path)
{
	struct stat	file;

	if (stat(path, &file) == -1)
		return (NULL);
	if ((file.st_mode & S_IFMT) == S_IFDIR)
	{
		errno = EISDIR;
		return (NULL);
	}
	return (path);
}
