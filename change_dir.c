/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 11:44:50 by suzie             #+#    #+#             */
/*   Updated: 2020/03/16 14:05:49 by suzie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int change_dir(char **arg)
{
    int ret;

    if (!arg[1])
        ret = chdir("/home/suzie"); //variable HOME
    else
        ret = chdir(arg[1]);
    if (ret)
        ft_fprintf(2, "{RED}ERROR:{EOC}Not such file or directory\n");
    return (ret);
}
