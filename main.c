/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 09:43:26 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/14 17:21:45 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_files_dir(int i, int ac, char ***av, char *options)
{
	int j;
	int k;
	char *tmp;

	j = -1;
	(void)options;
	while (++j < ac - i - 1)
	{
		k = -1;
		while (++k < ac - i - 1)
		{
			if (ft_strcmp((*av)[i + k], (*av)[i + k + 1]) > 0)
			{
				tmp = (*av)[i + k + 1];
				(*av)[i + k + 1] = (*av)[i + k];
				(*av)[i + k] = tmp;
			}
		}
	}
}

int	main(int ac, char **av)
{
	int i;
	char *options;

	i = 0;
	options = options_init(&i, ac, av);
	printf("Options: %s\n", options);
	if (i == ac)
		ft_ls(options, ".");
	else
	{
		sort_files_dir(i, ac, &av, options);
		while (i < ac)
		{
			ft_ls(options, av[i]);
			(++i < ac) ? printf("\n") : 0;
		}
	}
	free(options);
//	while (42){}
	return (EXIT_SUCCESS);
}
