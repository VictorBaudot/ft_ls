/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 09:32:15 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/19 11:44:47 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_symlink(char *path, char *file, char *options)
{
	int			count;
	char		*link;
	struct stat	sb;

	sb = e_lstat(path);
	link = malloc(sb.st_size + 1);
	if (link == NULL)
	{
		fprintf(stderr, "mémoire insuffisante\n");
		exit(EXIT_FAILURE);
	}
	count = readlink(path, link, sb.st_size + 1);
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
	has(options, 'l') ? ls_file(path, pad) : 0;
	if (is_directory(path) && has(options, 'G'))
		putf(B_CY "%s" NC "\n", file);
	else if (is_symlink(path) && has(options, 'G'))
		print_symlink(path, file, options);
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