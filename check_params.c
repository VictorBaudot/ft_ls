/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:41:32 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/19 16:29:34 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	is_directory(const char *path)
{
	struct stat	sb;

	sb = e_lstat(path);
	return (((sb.st_mode & S_IFMT) == S_IFDIR) ? 1 : 0);
}

int	is_exec(const char *path)
{
	struct stat	sb;

	sb = e_lstat(path);
	return (((sb.st_mode > 0) && (S_IEXEC & sb.st_mode)) ? 1 : 0);
}

int	is_symlink(const char *path)
{
	struct stat	sb;

	sb = e_lstat(path);
	return (((sb.st_mode & S_IFMT) == S_IFLNK) ? 1 : 0);
}

int	is_socket(const char *path)
{
	struct stat	sb;

	sb = e_lstat(path);
	return (((sb.st_mode & S_IFMT) == S_IFSOCK) ? 1 : 0);
}

int	has(const char *options, const char option)
{
	int i;

	i = -1;
	while (options[++i])
		if (options[i] == option)
			return (1);
	return (0);
}
