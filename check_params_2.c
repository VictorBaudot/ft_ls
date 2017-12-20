/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 11:49:19 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/20 11:51:18 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	is_chr(const char *path)
{
	struct stat	sb;

	sb = e_lstat(path);
	return (((sb.st_mode & S_IFMT) == S_IFCHR) ? 1 : 0);
}

int	is_fifo(const char *path)
{
	struct stat	sb;

	sb = e_lstat(path);
	return (((sb.st_mode & S_IFMT) == S_IFIFO) ? 1 : 0);
}

int	is_blk(const char *path)
{
	struct stat	sb;

	sb = e_lstat(path);
	return (((sb.st_mode & S_IFMT) == S_IFBLK) ? 1 : 0);
}
