/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 14:57:11 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/19 16:29:15 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	check_pad_s(char *name, int pad_size)
{
	int			nb;
	struct stat	sb;
	long long	nb_s;

	nb = 0;
	sb = e_lstat(name);
	nb_s = (long long)sb.st_size;
	while (nb_s > 0)
	{
		nb_s /= 10;
		nb++;
	}
	return ((pad_size > nb) ? pad_size : nb);
}

static int	check_pad_l(char *name, int pad_size)
{
	int			nb;
	struct stat	sb;
	long		nb_l;

	nb = 0;
	sb = e_lstat(name);
	nb_l = (long)sb.st_nlink;
	while (nb_l > 0)
	{
		nb_l /= 10;
		nb++;
	}
	return ((pad_size > nb) ? pad_size : nb);
}

static int	check_pad_u(char *name, int pad_size)
{
	int			nb;
	struct stat	sb;

	sb = e_lstat(name);
	nb = (long)ft_strlen(getpwuid(sb.st_uid)->pw_name);
	return ((pad_size > nb) ? pad_size : nb);
}

static int	check_pad_g(char *name, int pad_size)
{
	int			nb;
	struct stat	sb;

	sb = e_lstat(name);
	nb = (long)ft_strlen(getgrgid(sb.st_gid)->gr_name);
	return ((pad_size > nb) ? pad_size : nb);
}

void		check_all_pads(char *path, t_pad **pad)
{
	(*pad)->pad_links = check_pad_l(path, (*pad)->pad_links);
	(*pad)->pad_size = check_pad_s(path, (*pad)->pad_size);
	(*pad)->pad_usr = check_pad_u(path, (*pad)->pad_usr);
	(*pad)->pad_grp = check_pad_g(path, (*pad)->pad_grp);
}
