/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 09:49:25 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/20 16:46:58 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_dir_error(char *path, char *file)
{
	char	*join;

	ft_putchar('\n');
	join = ft_str3join(path, ":\nls: ", file);
	perror(join);
	free(join);
	free(path);
}

static void	dir_opened(char *path, char *file, char *options, int ac)
{
	if (ft_strcmp(file, ".") != 0 && ft_strcmp(file, "..") != 0)
	{
		if (file[0] == '.' && has(options, 'a'))
			ft_ls(options, path, ac, 0);
		else if (file[0] != '.')
			ft_ls(options, path, ac, 0);
	}
}

void		option_r(char *name, char **files, char *options, int ac_i)
{
	int		i;
	char	*path;
	DIR		*sub;

	i = -1;
	while (files[++i])
	{
		path = ft_str3join(name, "/", files[i]);
		if (is_directory(path))
		{
			if ((sub = opendir(path)) == NULL)
			{
				print_dir_error(path, files[i]);
				continue ;
			}
			else
			{
				dir_opened(path, files[i], options, ac_i);
				(closedir(sub) == -1) ? perror("closedir") : 0;
			}
		}
		free(path);
	}
}
