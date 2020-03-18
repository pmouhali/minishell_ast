/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 12:50:09 by suzie             #+#    #+#             */
/*   Updated: 2020/03/18 14:43:50 by suzie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_pwd(char *args[])
{
    char    path[PATH_MAX];

    (void)arg;
    if (!(getcwd(path, PATH_MAX)))
        return (1);
    else
        ft_dprintf(1, "%s\n", path);
    return (0);
}
