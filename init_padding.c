/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_padding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 22:58:41 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/20 13:18:16 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_padding(t_pad *pad, char *name, char *options)
{
	DIR				*dirp;
	char			*path;
	struct dirent	*dp;

	dirp = e_opendir(name);
	while ((dp = readdir(dirp)) != NULL)
	{
		path = ft_str3join(name, "/", dp->d_name);
		if (dp->d_name[0] == '.' && has(options, 'a'))
			check_all_pads(path, &pad);
		else if (dp->d_name[0] != '.')
		{
			if (is_chr(path))
				pad->pad_size = 8;
			check_all_pads(path, &pad);
		}
		free(path);
	}
	(void)closedir(dirp);
}

void	init_padding_files(t_pad *pad, char **av, char *options)
{
	char	*path;
	int		i;

	i = -1;
	pad->pad_links = 1;
	pad->pad_size = 1;
	pad->pad_usr = 1;
	pad->pad_grp = 1;
	while (av[++i] && !is_directory(av[i]))
	{
		path = ft_str3join(".", "/", av[i]);
		if (av[i][0] == '.' && has(options, 'a'))
			check_all_pads(path, &pad);
		else if (av[i][0] != '.')
			check_all_pads(path, &pad);
		free(path);
	}
}
