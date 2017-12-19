/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 11:21:50 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/19 13:29:17 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_error(void)
{
	ft_putstr("error.\n");
	exit(EXIT_FAILURE);
}

DIR			*e_opendir(char *name)
{
	DIR *dirp;

	if ((dirp = opendir(name)) == NULL)
	{
		putf("%s: ", name);
		perror("opendir");
		ft_error();
	}
	return (dirp);
}

struct stat	e_lstat(char *name)
{
	struct stat	sb;

	if (lstat(name, &sb) == -1)
	{
		putf("%s: ", name);
		perror("lstat");
		exit(EXIT_SUCCESS);
	}
	return (sb);
}
