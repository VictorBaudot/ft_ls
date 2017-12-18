/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 22:30:11 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/18 14:57:02 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ls_file(const char *path, t_pad pad)
{
	struct stat	sb;
	char		*date;
	int			i;
	int pad_l;
	int pad_s;
	long		nb_l;
	long long	nb_s;

	if (lstat(path, &sb) == -1)
	{
		putf("ls_file: %s: ", path);
		perror("");
		exit(EXIT_SUCCESS);
	}
	putf((S_ISDIR(sb.st_mode)) ? "d" : "-");
	putf((sb.st_mode & S_IRUSR) ? "r" : "-");
	putf((sb.st_mode & S_IWUSR) ? "w" : "-");
	putf((sb.st_mode & S_IXUSR) ? "x" : "-");
	putf((sb.st_mode & S_IRGRP) ? "r" : "-");
	putf((sb.st_mode & S_IWGRP) ? "w" : "-");
	putf((sb.st_mode & S_IXGRP) ? "x" : "-");
	putf((sb.st_mode & S_IROTH) ? "r" : "-");
	putf((sb.st_mode & S_IWOTH) ? "w" : "-");
	putf((sb.st_mode & S_IXOTH) ? "x" : "-");
	nb_l = (long) sb.st_nlink;
	pad_l = (nb_l > 0) ? 0 : 1;
	while (nb_l > 0)
	{
		nb_l /= 10;
		pad_l++;
	}
	i = -1;
	while (++i < pad.pad_links - pad_l)
		putf(" ");
	putf("%l ", (long) sb.st_nlink);
	putf("%s", getpwuid(sb.st_uid)->pw_name);
	i = -1;
	while (++i < pad.pad_usr - (int)ft_strlen(getpwuid(sb.st_uid)->pw_name))
		putf(" ");
	putf("  %s", getgrgid(sb.st_gid)->gr_name);
	i = -1;
	while (++i < pad.pad_grp - (int)ft_strlen(getgrgid(sb.st_gid)->gr_name))
		putf(" ");
	nb_s = (long long) sb.st_size;
	pad_s = (nb_s > 0) ? 0 : 1;
	while (nb_s > 0)
	{
		nb_s /= 10;
		pad_s++;
	}
	i = -1;
	while (++i < pad.pad_size - pad_s)
		putf(" ");
	putf("%L ", (long long) sb.st_size);
	if (time(0) - sb.st_mtime > 15552000)
		date = ft_strjoin(ft_strsub(ctime(&sb.st_mtime), 4, 7), ft_strsub(ctime(&sb.st_mtime), 19, 5));
	else
		date = ft_strsub(ctime(&sb.st_mtime), 4, 12);
	putf("%s ", date);
	free(date);
}

static long	nb_blocks(const char *name)
{
	struct stat sb;

	if (lstat(name, &sb) == -1)
	{
		putf("nb_blocks: %s: ", name);
		perror("");
		exit(EXIT_SUCCESS);
	}
	return ((long) sb.st_blocks);
}

void		count_blocks(char *options, DIR *dirp, char *name)
{
	struct dirent *dp;
	char *path;
	long nb;
	int flag;

	nb = 0;
	flag = 0;
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
