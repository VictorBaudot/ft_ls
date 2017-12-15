/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_padding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 22:58:41 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/15 23:22:11 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		check_pad_s(char *name, int pad_size)
{
	int			nb;
	struct stat	sb;
	long long	nb_s;

	nb = 1;
	if (lstat(name, &sb) == -1)
	{
		perror("lstat");
		exit(EXIT_SUCCESS);
	}
	nb_s = (long long) sb.st_size;
	while (nb_s > 0)
	{
		nb_s /= 10;
		nb++;
	}
	return ((pad_size > nb) ? pad_size : nb);
}

static int		check_pad_l(char *name, int pad_size)
{
	int			nb;
	struct stat	sb;
	long		nb_l;

	nb = 2;
	if (lstat(name, &sb) == -1)
	{
		perror("lstat");
		exit(EXIT_SUCCESS);
	}
	nb_l = (long) sb.st_nlink;
	while (nb_l > 0)
	{
		nb_l /= 10;
		nb++;
	}
	return ((pad_size > nb) ? pad_size : nb);
}

void			init_padding(t_pad *pad, char *name, char *options)
{
	DIR *dirp;
	struct dirent *dp;

	pad->pad_links = 2;
	pad->pad_size = 2;
	if ((dirp = opendir(name)) == NULL)
	{
		perror("opendir");
		return ;
	}
	while ((dp = readdir(dirp)) != NULL)
	{
		if (dp->d_name[0] == '.' && has(options, 'a'))
		{
			pad->pad_links = check_pad_l(dp->d_name, pad->pad_links);
			pad->pad_size = check_pad_s(dp->d_name, pad->pad_size);
		}
		else if (dp->d_name[0] != '.')
		{
			pad->pad_links = check_pad_l(dp->d_name, pad->pad_links);
			pad->pad_size = check_pad_s(dp->d_name, pad->pad_size);
		}
	}
	(void)closedir(dirp);
}
