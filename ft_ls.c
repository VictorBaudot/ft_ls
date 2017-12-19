/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:17:00 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/19 14:45:45 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	cut_ft_ls(char *options, char *name, int ac_i, t_pad pad)
{
	DIR				*dirp;
	char			**files;
	int				nb_f;
	struct dirent	*dp;
	int				i;

	nb_f = count_files(name);
	if (!(files = (char **)malloc(sizeof(char *) * (nb_f + 1))))
		ft_error();
	files[nb_f] = 0;
	dirp = e_opendir(name);
	i = -1;
	while ((dp = readdir(dirp)) != NULL)
		files[++i] = ft_strdup(dp->d_name);
	sort_ascii(0, nb_f, &files);
	(has(options, 't')) ? sort_time(0, nb_f, &files, name) : 0;
	(has(options, 'r')) ? sort_rev(0, nb_f, &files) : 0;
	print_files(name, files, options, pad);
	(has(options, 'R')) ? option_r(name, files, options, ac_i) : 0;
	(void)closedir(dirp);
	i = -1;
	while (files[++i])
		free(files[i]);
	free(files);
}

void		ft_ls(char *options, char *name, int ac_i)
{
	t_pad	pad;

	pad.pad_links = 1;
	pad.pad_size = 1;
	pad.pad_usr = 1;
	pad.pad_grp = 1;
	if (!is_directory(name))
	{
		print_file(name, name, options, pad);
		return ;
	}
	(has(options, 'l')) ? init_padding(&pad, name, options) : 0;
	((has(options, 'R') && has(name, '/')) || ac_i > 1) ?
	putf("\n%s:\n", name) : 0;
	(has(options, 'l')) ? count_blocks(options, name) : 0;
	cut_ft_ls(options, name, ac_i, pad);
}
