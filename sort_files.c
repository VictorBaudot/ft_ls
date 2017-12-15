/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:36:59 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/15 16:56:57 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	rev_ascii(int i, int ac, char ***av)
{
	int j;
	int k;
	char *tmp;

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
	int j;
	int k;
	char *tmp;

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
	int j;
	int k;
	char *tmp;

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
