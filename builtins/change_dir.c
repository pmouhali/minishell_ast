/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 11:44:50 by suzie             #+#    #+#             */
/*   Updated: 2020/03/19 22:02:12 by suzie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void change_path(char *path, int ret)
{
    char *buff;
    
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
}

static int path_variable(char *arg[], int ret)
{
    if (!arg[1] || (arg[1][0] == '~' && !arg[1][1]))
    {
        if ((ret = chdir(get_key_value(environment, "HOME"))))
            ft_perrorc("minishell: cd", "HOME not set", NULL);
        return(ret);
    }
    if (arg[1][0] == '-')
    {
        if ((ret = chdir(get_key_value(environment, "OLDPWD"))))
            ft_perrorc("minishell: cd", "OLDPWD not set", NULL);
        else
            ft_dprintf(1, "%s\n", get_key_value(environment, "OLDPWD"));
        return (ret);
    }
    return(1);
}

static int give_path_tofunction(char *arg[], int ret, char *buff)
{
    if (arg[1] && arg[2])
        ft_perrorc("minishell: cd", "too many arguments", NULL);
    else
    {
        if ((ret = path_variable(arg, ret)) == 1)
        {
            if (!(ft_strncmp(arg[1], "~root", 5)))
                arg[1][0] = '/';
            if (arg[1][0] == '~')
            {
                    ft_strcpy(buff, "/home/");
                    ft_strcpy(buff + 6, arg[1] + 1);
            }
            else
                ft_strcpy(buff, arg[1]);
            if ((ret = chdir(buff)))
                ft_perrorc("minishell: cd", arg[1], strerror(errno));
        }
    }
    return (ret);
}

int change_dir(char *arg[])
{
    int     ret;
    char    path[PATH_MAX];
    char    buff[PATH_MAX];

    getcwd(path, PATH_MAX);
    ret = 1;
    ret = give_path_tofunction(arg, ret, buff);
    change_path(path, ret);
    ret ? ret = 1 : 0;
    return (ret);
}
