/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 10:49:57 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/19 11:50:44 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static long	nb_blocks(const char *name)
{
	struct stat	sb;

	if (lstat(name, &sb) == -1)
	{
		putf("nb_blocks: %s: ", name);
		perror("");
		exit(EXIT_SUCCESS);
	}
	return ((long)sb.st_blocks);
}

void		count_blocks(char *options, char *name)
{
	struct dirent	*dp;
	char			*path;
	DIR				*dirp;
	long			nb;
	int				flag;

	nb = 0;
	flag = 0;
	dirp = e_opendir(name);
	while ((dp = readdir(dirp)) != NULL)
	{
		flag++;
		path = ft_str3join(name, "/", dp->d_name);
		if (dp->d_name[0] == '.' && has(options, 'a'))
			nb += nb_blocks(path);
		else if (dp->d_name[0] != '.')
			nb += nb_blocks(path);
		free(path);
	}
	(flag > 2) ? putf("total %l\n", nb) : 0;
	(void)closedir(dirp);
}

int			count_files(char *name)
{
	DIR				*dirp;
	struct dirent	*dp;
	long			nb;

	nb = 0;
	dirp = e_opendir(name);
	while ((dp = readdir(dirp)) != NULL)
		nb++;
	(void)closedir(dirp);
	return (nb);
}
