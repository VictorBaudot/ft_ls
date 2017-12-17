/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 09:43:26 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/17 14:53:34 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	int i;
	char *options;

	i = 0;
	options = options_init(&i, ac, av);
//	putf("Options: %s\n", options);
	if (i == ac)
		ft_ls(options, ".");
	else
	{
		(has(options, 'r')) ? rev_ascii(i, ac, &av) : sort_ascii(i, ac, &av);
		sort_files_by_type(i, ac, &av, options);
		while (i < ac)
		{
			ft_ls(options, av[i]);
			(++i < ac) ? putf("\n") : 0;
		}
	}
	free(options);
//	while (42){}
	return (EXIT_SUCCESS);
}
