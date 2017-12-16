/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 22:30:11 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/16 00:29:00 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ls_file(const char *name, t_pad pad)
{
	struct stat	sb;
	char		*date;
	int			i;
	int pad_l;
	int pad_s;
	long		nb_l;
	long long	nb_s;

	if (lstat(name, &sb) == -1)
	{
		perror("lstat");
		exit(EXIT_SUCCESS);
	}
	printf((S_ISDIR(sb.st_mode)) ? "d" : "-");
	printf((sb.st_mode & S_IRUSR) ? "r" : "-");
	printf((sb.st_mode & S_IWUSR) ? "w" : "-");
	printf((sb.st_mode & S_IXUSR) ? "x" : "-");
	printf((sb.st_mode & S_IRGRP) ? "r" : "-");
	printf((sb.st_mode & S_IWGRP) ? "w" : "-");
	printf((sb.st_mode & S_IXGRP) ? "x" : "-");
	printf((sb.st_mode & S_IROTH) ? "r" : "-");
	printf((sb.st_mode & S_IWOTH) ? "w" : "-");
	printf((sb.st_mode & S_IXOTH) ? "x" : "-");
	nb_l = (long) sb.st_nlink;
	pad_l = (nb_l > 0) ? 0 : 1;
	while (nb_l > 0)
	{
		nb_l /= 10;
		pad_l++;
	}
	i = -1;
	while (++i < pad.pad_links - pad_l)
		printf(" ");
	printf("%ld ", (long) sb.st_nlink);
	printf("%s ", getpwuid(sb.st_uid)->pw_name);
	printf(" %s ", getgrgid(sb.st_gid)->gr_name);
	nb_s = (long long) sb.st_size;
	pad_s = (nb_s > 0) ? 0 : 1;
	while (nb_s > 0)
	{
		nb_s /= 10;
		pad_s++;
	}
	i = -1;
	while (++i < pad.pad_size - pad_s)
		printf(" ");
	printf("%lld ", (long long) sb.st_size);
	date = ft_strsub(ctime(&sb.st_mtime), 4, 12);
	printf("%s ", date);
	printf("%s\n", name);
	free(date);
}

static long	nb_blocks(const char *name)
{
	struct stat sb;

	if (lstat(name, &sb) == -1)
	{
		perror("lstat");
		exit(EXIT_SUCCESS);
	}
	return ((long) sb.st_blocks);
}

void		count_blocks(char *options, DIR *dirp)
{
	struct dirent *dp;
	long nb;

	nb = 0;
	while ((dp = readdir(dirp)) != NULL)
	{
		if (dp->d_name[0] == '.' && has(options, 'a'))
			nb += nb_blocks(dp->d_name);
		else if (dp->d_name[0] != '.')
			nb += nb_blocks(dp->d_name);
	}
	printf("total %ld\n", nb);
	(void)closedir(dirp);
}
