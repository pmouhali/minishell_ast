/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 11:44:50 by suzie             #+#    #+#             */
/*   Updated: 2020/03/19 13:00:59 by suzie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int change_dir(char *arg[])
{
    int     ret;
    char    path[PATH_MAX];
    char    *buff;

    getcwd(path, PATH_MAX);
    buff = NULL;
    ret = 1;
    if (arg[1] && arg[2])
        ft_dprintf(2, "bash: cd: too many arguments\n");
    else
    {
        if (!arg[1])
        {
            if (ret = chdir(get_key_value(environment, "HOME")))
                ft_dprintf(2, "bash: cd: HOME not set\n");
        }
        if (arg[1] && arg[1][0] == '~')
        {
            buff = ft_strjoin("/home/", arg[1] + 1);
            if (ret = chdir(buff))
                ft_dprintf(2, "bash: cd: %s: No such file or directory\n", arg[1]);
            ft_strdel(&buff);
        }
        else
        {
            if (ret = chdir(arg[1]))
               ft_dprintf(2, "bash: cd: %s: No such file or directory\n", arg[1]);
        }
    }
    ret ? ret = 1 : 0;
    if (!ret)
    {
        buff = ft_strjoin("OLDPWD=", path);
        push_envar(buff);
        ft_strdel(&buff);
        getcwd(path, PATH_MAX);
        buff = ft_strjoin("PWD=", path);
        push_envar(buff);
        ft_strdel(&buff);
    }
    return (ret);
}
