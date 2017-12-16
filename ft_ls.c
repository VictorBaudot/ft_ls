/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:17:00 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/16 01:44:16 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		count_files(DIR *dirp)
{
	struct dirent *dp;
	long nb;

	nb = 1;
	while ((dp = readdir(dirp)) != NULL)
		nb++;
	(void)closedir(dirp);
	return (nb);
}

void	ft_ls(char *options, char *name)
{
	DIR *dirp;
	struct dirent *dp;
	char **files;
	int nb_f;
	int i;
	t_pad pad;

	(has(options, 'l')) ? init_padding(&pad, name, options) : 0;
	if ((dirp = opendir(name)) == NULL)
	{
		has(options, 'l') ? ls_file(name, pad) : printf("%s\n", name);
		return ;
	}
	(has(options, 'l')) ? count_blocks(options, dirp) : 0;
	(has(options, 'l')) ? (dirp = opendir(name)) : 0;
	if (ft_strcmp(".", name) != 0)
		printf("%s:\n", name);
	nb_f = count_files(dirp);
	files = (char **)malloc(sizeof(char *) * nb_f);
	files[nb_f] = 0;
	if ((dirp = opendir(name)) == NULL)
	{
		perror("opendir");
		return ;
	}
	i = -1;
	while ((dp = readdir(dirp)) != NULL)
		files[++i] = strdup(dp->d_name);
	sort_ascii(0, nb_f - 1, &files);
	(has(options, 't')) ? sort_time(0, nb_f - 1, &files) : 0;
	(has(options, 'r')) ? sort_rev(0, nb_f - 1, &files) : 0;
	i = -1;
	while (files[++i])
	{
		if (files[i][0] == '.' && has(options, 'a'))
			has(options, 'l') ? ls_file(files[i], pad) : printf("%s\n", files[i]);
		else if (files[i][0] != '.')
			has(options, 'l') ? ls_file(files[i], pad) : printf("%s\n", files[i]);
	}
	(void)closedir(dirp);
	i = -1;
	while (files[++i])
		free(files[i]);
	free(files);
}
