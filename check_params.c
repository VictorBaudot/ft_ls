/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:41:32 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/15 16:56:09 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_directory(const char *path)
{
   struct stat statbuf;

   if (stat(path, &statbuf) != 0)
       return (0);
   return (S_ISDIR(statbuf.st_mode));
}

int		has(const char *options, const char option)
{
	int i;

	i = -1;
	while (options[++i])
		if (options[i] == option)
			return (1);
	return (0);
}
