/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:36:59 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/19 14:02:31 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_time(int i, int ac, char ***av, char *name)
{
	int			j;
	int			k;
	char		*tmp;
	struct stat	sb1;
	struct stat	sb2;

	j = -1;
	while (++j < ac - i - 1)
	{
		k = -1;
		while (++k < ac - i - 1)
		{
			sb1 = help_norm(name, (*av)[i + k]);
			sb2 = help_norm(name, (*av)[i + k + 1]);
			if (sb2.st_mtime > sb1.st_mtime)
			{
				tmp = (*av)[i + k + 1];
				(*av)[i + k + 1] = (*av)[i + k];
				(*av)[i + k] = tmp;
			}
		}
	}
}

void	sort_rev(int i, int ac, char ***av)
{
	int		k;
	char	*tmp;

	k = -1;
	while (++k <= (ac - i - 1) / 2)
	{
		tmp = (*av)[ac - 1 - k];
		(*av)[ac - 1 - k] = (*av)[i + k];
		(*av)[i + k] = tmp;
	}
}

void	rev_ascii(int i, int ac, char ***av)
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

void	sort_files_by_type(int i, int ac, char ***av, char *options)
{
	int		j;
	int		k;
	char	*tmp;

	j = -1;
	(void)options;
	while (++j < ac - i - 1)
	{
		k = -1;
		while (++k < ac - i - 1)
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
