/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:17:00 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/15 18:31:00 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_file(const char *name)
{
	struct stat sb;
	char *date;

	printf("%s\n", name);
	if (lstat(name, &sb) == -1) {
		perror("stat");
		exit(EXIT_SUCCESS);
	}
	printf( (S_ISDIR(sb.st_mode)) ? "d" : "-");
    printf( (sb.st_mode & S_IRUSR) ? "r" : "-");
    printf( (sb.st_mode & S_IWUSR) ? "w" : "-");
    printf( (sb.st_mode & S_IXUSR) ? "x" : "-");
    printf( (sb.st_mode & S_IRGRP) ? "r" : "-");
    printf( (sb.st_mode & S_IWGRP) ? "w" : "-");
    printf( (sb.st_mode & S_IXGRP) ? "x" : "-");
    printf( (sb.st_mode & S_IROTH) ? "r" : "-");
    printf( (sb.st_mode & S_IWOTH) ? "w" : "-");
    printf( (sb.st_mode & S_IXOTH) ? "x" : "-");
	printf("  %ld ", (long) sb.st_nlink);
	printf("%s ", getpwuid(sb.st_uid)->pw_name);
	printf(" %s ", getgrgid(sb.st_gid)->gr_name);
	printf(" %lld ", (long long) sb.st_size);
	date = ft_strsub(ctime(&sb.st_mtime), 4, 12);
	printf("%s ", date);
	printf("%s\n", name);
}

void	ft_ls(char *options, char *name)
{
	DIR *dirp;
	struct dirent *dp;
	int len;

	(void)options;
	dirp = opendir(name);
	if ((dirp = opendir(name)) == NULL)
	{
		has(options, 'l') ? ls_file(name) : printf("%s\n", name);
		return ;
	}
	if (ft_strcmp(".", name) != 0)
		printf("%s:\n", name);
	len = strlen(name);
	while ((dp = readdir(dirp)) != NULL)
	{
		if (dp->d_name[0] == '.' && has(options, 'a'))
			has(options, 'l') ? ls_file(dp->d_name) : printf("%s\n", dp->d_name);
		else if (dp->d_name[0] != '.')
			has(options, 'l') ? ls_file(dp->d_name) : printf("%s\n", dp->d_name);
	}
	(void)closedir(dirp);
}
