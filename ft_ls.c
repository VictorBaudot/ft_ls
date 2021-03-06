/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:17:00 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/20 16:22:01 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	cut_ft_ls(char *options, char *name, int ac, t_pad pad)
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
	(!has(options, 'f')) ? sort_ascii(0, nb_f, &files) : 0;
	(has(options, 't')) ? sort_time(nb_f, &files, name) : 0;
	(has(options, 'r')) ? sort_rev(nb_f, &files) : 0;
	print_files(name, files, options, pad);
	(has(options, 'R')) ? option_r(name, files, options, ac) : 0;
	(void)closedir(dirp);
	i = -1;
	while (files[++i])
		free(files[i]);
	free(files);
}

static int	check_dir(char *name)
{
	DIR		*dirp;
	char	*join;

	if ((dirp = opendir(name)) == NULL)
	{
		join = ft_strjoin("ls: ", name);
		perror(join);
		free(join);
		return (-1);
	}
	(void)closedir(dirp);
	return (1);
}

void		ft_ls(char *options, char *name, int ac, int j)
{
	t_pad		pad;
	static int	i = 0;

	pad.pad_links = 1;
	pad.pad_size = 1;
	pad.pad_usr = 1;
	pad.pad_grp = 1;
	if (!is_directory(name))
	{
		print_file(name, name, options, pad);
		return ;
	}
	((has(options, 'R') && has(name, '/')) || (ac > 1 && (i > 0 || j == 1))) ?
	putf("\n") : 0;
	((has(options, 'R') && has(name, '/')) || (ac > 1)) ?
	putf("%s:\n", name) : 0;
	i++;
	if (check_dir(name) == -1)
		return ;
	(has(options, 'l') || has(options, 'g')) ?
	init_padding(&pad, name, options) : 0;
	(has(options, 'l') || has(options, 'g')) ? count_blocks(options, name) : 0;
	cut_ft_ls(options, name, ac, pad);
}
