/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:18:44 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/20 14:35:16 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*options_init(int *i, int ac, char **av, int k)
{
	int		j;
	int		l;
	char	*options;

	*i = 0;
	options = (char*)malloc(sizeof(char) * 10);
	ft_bzero(options, 10);
	while (++(*i) < ac && k < 8 && av[*i][0] == '-' && ft_strcmp(av[*i], "--"))
	{
		j = 0;
		while (av[*i][++j] && k < 8)
		{
			l = -1;
			while (++l < 8)
				if (av[*i][j] == options[l])
					break ;
				else if (av[*i][j] != 'l' && av[*i][j] != 'R' &&
				av[*i][j] != 'a' && av[*i][j] != 'r' && av[*i][j] != 't'
				&& av[*i][j] != 'G' && av[*i][j] != 'f' && av[*i][j] != 'g')
					print_usage(av[*i][j]);
			if (l == 8 && (av[*i][j] == 'l' || av[*i][j] == 'R' ||
			av[*i][j] == 'a' || av[*i][j] == 'r' || av[*i][j] == 't'
			|| av[*i][j] == 'G' || av[*i][j] == 'f' || av[*i][j] == 'g'))
				options[++k] = av[*i][j];
		}
	}
	if (has(options, 'f'))
	{
		options[++k] = 'a';
		k = -1;
		while (options[++k] && k < 8)
			(options[k] == 'r' || options[k] == 't' || options[k] == '.')
			? (options[k] = 'a') : 0;
	}
	return (options);
}
