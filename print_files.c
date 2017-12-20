/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 09:32:15 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/20 16:22:25 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_symlink(char *path, char *file, char *options)
{
	int			count;
	char		*link;

	if (!(link = malloc(1024)))
		ft_error();
	count = readlink(path, link, 1023);
	if (count >= 0)
	{
		link[count] = '\0';
		if (has(options, 'G'))
			putf(B_MA "%s" NC " -> %s\n", file, link);
		else
			putf("%s -> %s\n", file, link);
	}
	free(link);
}

void		print_file(char *path, char *file, char *options, t_pad pad)
{
	(has(options, 'l') || has(options, 'g')) ? ls_file(path, pad, options) : 0;
	if (is_directory(path) && has(options, 'G'))
		putf(B_CY "%s" NC "\n", file);
	else if (is_symlink(path) && (has(options, 'l') || has(options, 'g')))
		print_symlink(path, file, options);
	else if (is_symlink(path) && has(options, 'G'))
		putf(B_MA "%s" NC "\n", file);
	else if (is_socket(path) && has(options, 'G'))
		putf(B_G "%s" NC "\n", file);
	else if (is_fifo(path) && has(options, 'G'))
		putf(YEL "%s" NC "\n", file);
	else if (is_chr(path) && has(options, 'G'))
		putf(B_Y "%s" NC "\n", file);
	else if (is_blk(path) && has(options, 'G'))
		putf(B_BLU "%s" NC "\n", file);
	else if (is_exec(path) && has(options, 'G'))
		putf(B_R "%s" NC "\n", file);
	else
		putf("%s\n", file);
}

void		print_files(char *name, char **files, char *options, t_pad pad)
{
	int		i;
	char	*path;

	i = -1;
	while (files[++i])
	{
		path = ft_str3join(name, "/", files[i]);
		if (files[i][0] == '.' && has(options, 'a'))
			print_file(path, files[i], options, pad);
		else if (files[i][0] != '.')
			print_file(path, files[i], options, pad);
		free(path);
	}
}
