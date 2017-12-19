/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 11:21:50 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/19 16:33:35 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

DIR			*e_opendir(const char *name)
{
	DIR *dirp;

	if ((dirp = opendir(name)) == NULL)
	{
		putf("ls: ");
		perror(name);
		exit(EXIT_SUCCESS);
	}
	return (dirp);
}

struct stat	e_lstat(const char *name)
{
	struct stat	sb;

	if (lstat(name, &sb) == -1)
	{
		putf("ls: ");
		perror(name);
		exit(EXIT_SUCCESS);
	}
	return (sb);
}
