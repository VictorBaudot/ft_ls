/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:17:00 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/18 14:32:22 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		count_files(DIR *dirp)
{
	struct dirent *dp;
	long nb;

	nb = 0;
	while ((dp = readdir(dirp)) != NULL)
		nb++;
	(void)closedir(dirp);
	return (nb);
}

void	ft_ls(char *options, char *name, int ac_i)
{
	DIR *dirp;
	DIR *sub;
	struct dirent *dp;
	char *path;
	char **files;
	int nb_f;
	int i;
	t_pad pad;

	(has(options, 'l')) ? init_padding(&pad, name, options) : 0;
	if ((dirp = opendir(name)) == NULL)
	{
		has(options, 'l') ? ls_file(name, pad) : putf("%s\n", name);
		return ;
	}
	((has(options, 'R') && has(name, '/')) || ac_i > 1) ? putf("\n%s:\n", name) : 0;
	(has(options, 'l')) ? count_blocks(options, dirp, name) : 0;
	(has(options, 'l')) ? (dirp = opendir(name)) : 0;
	nb_f = count_files(dirp);
	files = (char **)malloc(sizeof(char *) * (nb_f + 1));
	files[nb_f] = 0;
	if ((dirp = opendir(name)) == NULL)
	{
		perror("opendir");
		return ;
	}
	i = -1;
	while ((dp = readdir(dirp)) != NULL)
		files[++i] = ft_strdup(dp->d_name);
	sort_ascii(0, nb_f - 1, &files);
	(has(options, 't')) ? sort_time(0, nb_f - 1, &files, name) : 0;
	(has(options, 'r')) ? sort_rev(0, nb_f - 1, &files) : 0;
	i = -1;
	while (files[++i])
	{
		path = ft_str3join(name, "/", files[i]);
		if (files[i][0] == '.' && has(options, 'a'))
		{
			has(options, 'l') ? ls_file(path, pad) : 0;
			((is_directory(path) && has(options, 'G'))) ? putf(B_CY "%s" NC "\n", files[i]) : putf("%s\n", files[i]);
		}
		else if (files[i][0] != '.')
		{
			has(options, 'l') ? ls_file(path, pad) : 0;
			((is_directory(path) && has(options, 'G'))) ? putf(B_CY "%s" NC "\n", files[i]) : putf("%s\n", files[i]);
		}
		free(path);
	}
	i = -1;
	if (has(options, 'R'))
		while (files[++i])
		{
			path = ft_str3join(name, "/", files[i]);
			if ((sub = opendir(path)) != NULL &&
			ft_strcmp(files[i], ".") != 0 && ft_strcmp(files[i], "..") != 0)
			{
				ft_ls(options, path, ac_i);
				(closedir(sub) == -1) ? perror("closedir") : 0;
			}
			else if (ft_strcmp(files[i], ".") == 0 || ft_strcmp(files[i], "..") == 0)
				(closedir(sub) == -1) ? perror("closedir") : 0;
			free(path);
		}
	(void)closedir(dirp);
	i = -1;
	while (files[++i])
		free(files[i]);
	free(files);
}
