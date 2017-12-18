/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:36:59 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/18 14:02:15 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_time(int i, int ac, char ***av, char *name)
{
	int j;
	int k;
	char *path1;
	char *path2;
	char *tmp;
	struct stat sb1;
	struct stat sb2;

	j = -1;
	while (++j < ac - i - 1)
	{
		k = -1;
		while (++k < ac - i)
		{
			path1 = ft_str3join(name, "/", (*av)[i + k]);
			path2 = ft_str3join(name, "/", (*av)[i + k + 1]);
			if (lstat(path1, &sb1) == -1 || lstat(path2, &sb2))
			{
				perror("sort_files");
				exit(EXIT_SUCCESS);
			}
			if (sb2.st_mtime > sb1.st_mtime)
			{
				tmp = (*av)[i + k + 1];
				(*av)[i + k + 1] = (*av)[i + k];
				(*av)[i + k] = tmp;
			}
			free(path1);
			free(path2);
		}
	}
}

void	sort_rev(int i, int ac, char ***av)
{
	int k;
	char *tmp;

	k = -1;
	while (++k < (ac - i - 1) / 2)
	{
		tmp = (*av)[ac - i - 1 - k];
		(*av)[ac - i - 1 - k] = (*av)[i + k];
		(*av)[i + k] = tmp;
	}
}

void	rev_ascii(int i, int ac, char ***av)
{
	int j;
	int k;
	char *tmp;

	j = -1;
	while (++j < ac - i - 1)
	{
		k = -1;
		while (++k < ac - i)
		{
			if (ft_strcmp((*av)[i + k], (*av)[i + k + 1]) < 0)
			{
				tmp = (*av)[i + k + 1];
				(*av)[i + k + 1] = (*av)[i + k];
				(*av)[i + k] = tmp;
			}
		}
	}
}

void	sort_ascii(int i, int ac, char ***av)
{
	int j;
	int k;
	char *tmp;

	j = -1;
	while (++j < ac - i - 1)
	{
		k = -1;
		while (++k < ac - i)
		{
			if (ft_strcmp((*av)[i + k], (*av)[i + k + 1]) > 0)
			{
				tmp = (*av)[i + k + 1];
				(*av)[i + k + 1] = (*av)[i + k];
				(*av)[i + k] = tmp;
			}
		}
	}
}

void	sort_files_by_type(int i, int ac, char ***av, char *options)
{
	int j;
	int k;
	char *tmp;

	j = -1;
	(void)options;
	while (++j < ac - i - 1)
	{
		k = -1;
		while (++k < ac - i)
		{
			if (is_directory((*av)[i + k]) && !is_directory((*av)[i + k + 1]))
			{
				tmp = (*av)[i + k + 1];
				(*av)[i + k + 1] = (*av)[i + k];
				(*av)[i + k] = tmp;
			}
		}
	}
}
