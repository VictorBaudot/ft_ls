/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 09:49:25 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/20 16:02:56 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	option_r(char *name, char **files, char *options, int ac_i)
{
	int		i;
	char	*path;
	DIR		*sub;
	char	*join;

	i = -1;
	while (files[++i])
	{
		path = ft_str3join(name, "/", files[i]);
		if (is_directory(path))
		{
			if ((sub = opendir(path)) == NULL)
			{
				ft_putchar('\n');
				join = ft_str3join(path, ":\nls: ", files[i]);
				perror(join);
				free(join);
				free(path);
				continue ;
			}
			else
			{
				if (ft_strcmp(files[i], ".") != 0 && ft_strcmp(files[i], "..") != 0)
				{
					if (files[i][0] == '.' && has(options, 'a'))
						ft_ls(options, path, ac_i, 0);
					else if (files[i][0] != '.')
						ft_ls(options, path, ac_i, 0);
					(closedir(sub) == -1) ? perror("closedir") : 0;
				}
				else if (ft_strcmp(files[i], ".") == 0
				|| ft_strcmp(files[i], "..") == 0)
					(closedir(sub) == -1) ? perror("closedir") : 0;
			}
		}
		free(path);
	}
}
