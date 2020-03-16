/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 11:44:50 by suzie             #+#    #+#             */
/*   Updated: 2020/03/16 19:11:37 by suzie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int change_dir(char **arg)
{
    int ret;

    ret = -1;
    if (arg[2])
        ft_dprintf(2, "bash: cd: too many arguments\n");
    else
    {
        if (!arg[1])
            if ((ret = chdir(get_key_value(environment, "HOME"))))
                ft_dprintf(2, "bash: cd: HOME not set\n");
        else
            if ((ret = chdir(arg[1])))
                ft_dprintf(2, "bash: cd: %s: No such file or directory\n", arg[1]);
    }
    return (ret);
}
