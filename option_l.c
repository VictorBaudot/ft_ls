/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 22:30:11 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/20 13:09:01 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_mode(struct stat sb)
{
	((sb.st_mode & S_IFMT) == S_IFREG) ? putf("-") : 0;
	((sb.st_mode & S_IFMT) == S_IFDIR) ? putf("d") : 0;
	((sb.st_mode & S_IFMT) == S_IFLNK) ? putf("l") : 0;
	((sb.st_mode & S_IFMT) == S_IFSOCK) ? putf("s") : 0;
	((sb.st_mode & S_IFMT) == S_IFIFO) ? putf("p") : 0;
	((sb.st_mode & S_IFMT) == S_IFCHR) ? putf("c") : 0;
	((sb.st_mode & S_IFMT) == S_IFBLK) ? putf("b") : 0;
	((sb.st_mode & S_IFMT) == S_IFWHT) ? putf("w") : 0;
	putf((sb.st_mode & S_IRUSR) ? "r" : "-");
	putf((sb.st_mode & S_IWUSR) ? "w" : "-");
	putf((sb.st_mode & S_IXUSR) ? "x" : "-");
	putf((sb.st_mode & S_IRGRP) ? "r" : "-");
	putf((sb.st_mode & S_IWGRP) ? "w" : "-");
	putf((sb.st_mode & S_IXGRP) ? "x" : "-");
	putf((sb.st_mode & S_IROTH) ? "r" : "-");
	putf((sb.st_mode & S_IWOTH) ? "w" : "-");
	putf((sb.st_mode & S_IXOTH) ? "x" : "-");
}

static int	nb_length(long nb)
{
	int pad;

	pad = (nb > 0) ? 0 : 1;
	while (nb > 0)
	{
		nb /= 10;
		pad++;
	}
	return (pad);
}

static void	print_middle(struct stat sb, t_pad pad, int i)
{
	int			pad_l;
	long		nb_l;

	nb_l = (long)sb.st_nlink;
	pad_l = nb_length(nb_l);
	while (++i < pad.pad_links - pad_l)
		putf(" ");
	putf("  %l ", (long)sb.st_nlink);
	putf("%s", getpwuid(sb.st_uid)->pw_name);
	i = -1;
	while (++i < pad.pad_usr - (int)ft_strlen(getpwuid(sb.st_uid)->pw_name))
		putf(" ");
	putf("  %s", getgrgid(sb.st_gid)->gr_name);
	i = -1;
	while (++i < pad.pad_grp - (int)ft_strlen(getgrgid(sb.st_gid)->gr_name))
		putf(" ");
}

static void	print_size(struct stat sb, t_pad pad, int i)
{
	int			pad_s;
	long long	nb_s;

	nb_s = (long long)sb.st_size;
	if ((sb.st_mode & S_IFMT) == S_IFCHR || (sb.st_mode & S_IFMT) == S_IFBLK)
	{
		pad_s = nb_length((long) major(sb.st_rdev));
		while (++i < 4 - pad_s)
			putf(" ");
		putf(" %l,", (long) major(sb.st_rdev));
		pad_s = nb_length((long) minor(sb.st_rdev));
		i = -1;
		while (++i < 3 - pad_s)
			putf(" ");
		putf(" %l ", (long) minor(sb.st_rdev));
	}
	else
	{
		pad_s = nb_length(nb_s);
		while (++i < pad.pad_size - pad_s)
			putf(" ");
		putf("  %L ", (long long)sb.st_size);
	}
}

void		ls_file(char *path, t_pad pad)
{
	struct stat	sb;
	char		*date;

	sb = e_lstat(path);
	print_mode(sb);
	print_middle(sb, pad, -1);
	print_size(sb, pad, -1);
	if (time(0) - sb.st_mtime > 15552000 || time(0) - sb.st_mtime < -60 * 60)
		date = ft_strjoin(ft_strsub(ctime(&sb.st_mtime), 4, 7),
		ft_strsub(ctime(&sb.st_mtime), 19, 5));
	else
		date = ft_strsub(ctime(&sb.st_mtime), 4, 12);
	putf("%s ", date);
	free(date);
}
