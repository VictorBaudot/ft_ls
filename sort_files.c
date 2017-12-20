/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:36:59 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/20 11:42:16 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_time(int ac, char ***av, char *name)
{
	int		j;
	int		k;
	char	*tmp;
	struct stat	sb1;
	struct stat	sb2;

	j = -1;
	while (++j < ac - 1)
	{
		k = -1;
		while (++k < ac - 1)
		{
			sb1 = help_norm(name, (*av)[k]);
			sb2 = help_norm(name, (*av)[k + 1]);
			if (sb2.st_mtime > sb1.st_mtime)
			{
				tmp = (*av)[k + 1];
				(*av)[k + 1] = (*av)[k];
				(*av)[k] = tmp;
			}
		}
	}
}

void	sort_rev(int ac, char ***av)
{
	int		k;
	char	*tmp;

	k = -1;
	while (++k <= (ac - 1) / 2)
	{
		tmp = (*av)[ac - 1 - k];
		(*av)[ac - 1 - k] = (*av)[k];
		(*av)[k] = tmp;
	}
}

void	rev_ascii(int ac, char ***av)
{
	int		j;
	int		k;
	char	*tmp;

	j = -1;
	while (++j < ac - 1)
	{
		k = -1;
		while (++k < ac - 1)
		{
			if (ft_strcmp((*av)[k], (*av)[k + 1]) < 0)
			{
				tmp = (*av)[k + 1];
				(*av)[k + 1] = (*av)[k];
				(*av)[k] = tmp;
			}
		}
	}
}

void	sort_ascii(int i, int ac, char ***av)
{
	int		j;
	int		k;
	char	*tmp;

	j = -1;
	while (++j < ac - i - 1)
	{
		k = -1;
		while (++k < ac - i - 1)
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

void	sort_files_by_type(int ac, char ***av)
{
	int		j;
	int		k;
	char	*tmp;

	j = -1;
	while (++j < ac - 1)
	{
		k = -1;
		while (++k < ac - 1)
		{
			if (is_directory((*av)[k]) && !is_directory((*av)[k + 1]))
			{
				tmp = (*av)[k + 1];
				(*av)[k + 1] = (*av)[k];
				(*av)[k] = tmp;
			}
		}
	}
}
