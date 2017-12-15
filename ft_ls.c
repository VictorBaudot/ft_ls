/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:17:00 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/15 23:07:59 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls(char *options, char *name)
{
	DIR *dirp;
	struct dirent *dp;
	t_pad pad;

	(has(options, 'l')) ? init_padding(&pad, name, options) : 0;
	if ((dirp = opendir(name)) == NULL)
	{
		has(options, 'l') ? ls_file(name, pad) : printf("%s\n", name);
		return ;
	}
	(has(options, 'l')) ? count_files(options, dirp) : 0;
	(has(options, 'l')) ? (dirp = opendir(name)) : 0;
	if (ft_strcmp(".", name) != 0)
		printf("%s:\n", name);
	while ((dp = readdir(dirp)) != NULL)
	{
		if (dp->d_name[0] == '.' && has(options, 'a'))
			has(options, 'l') ? ls_file(dp->d_name, pad) : printf("%s\n", dp->d_name);
		else if (dp->d_name[0] != '.')
			has(options, 'l') ? ls_file(dp->d_name, pad) : printf("%s\n", dp->d_name);
	}
	(void)closedir(dirp);
}
