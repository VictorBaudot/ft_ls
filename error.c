/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 11:21:50 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/20 10:13:14 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_error(void)
{
	putf("Malloc error.");
	exit(EXIT_SUCCESS);
}

DIR			*e_opendir(const char *name)
{
	DIR *dirp;
	char *join;

	if ((dirp = opendir(name)) == NULL)
	{
		join = ft_strjoin("ls: ", name);
		perror(join);
		free(join);
		exit(EXIT_SUCCESS);
	}
	return (dirp);
}

struct stat	e_lstat(const char *name)
{
	struct stat	sb;
	char *join;

	if (lstat(name, &sb) == -1)
	{
		join = ft_strjoin("ls: ", name);
		perror(join);
		free(join);
		exit(EXIT_SUCCESS);
	}
	return (sb);
}
