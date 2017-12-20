/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ok_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 10:41:42 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/20 10:41:52 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char  **ok_files(int i, int ac, char **av)
{
	int ok;
	int j;
	struct stat	sb;
	char	**files;

	ok = 0;
	i--;
	j = i;
	while (++i < ac)
	{
		if (lstat(av[i], &sb) == -1)
		{
			putf("ls: ");
			perror(av[i]);
		}
		else
			ok++;
	}
	if (!(files = (char**)malloc(sizeof(char *) * (ok + 1))))
		ft_error();
	files[ok] = 0;
	ok = -1;
	while (++j < ac)
		if (lstat(av[j], &sb) != -1)
			files[++ok] = ft_strdup(av[j]);
	return (files);
}
