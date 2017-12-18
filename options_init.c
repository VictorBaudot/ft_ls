/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:18:44 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/18 13:14:32 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*options_init(int *i, int ac, char **av)
{
	int		j;
	int		k;
	int		l;
	char	*options;

	*i = 0;
	k = -1;
	options = (char*)malloc(sizeof(char) * 7);
	ft_bzero(options, 7);
	while (++(*i) < ac && k < 6 && av[*i][0] == '-')
	{
		j = 0;
		while (av[*i][++j] && k < 6)
		{
			l = -1;
			while (++l < 6)
				if (av[*i][j] == options[l])
				{
					break ;
				}
			if (l == 6 && (av[*i][j] == 'l' || av[*i][j] == 'R' ||
			av[*i][j] == 'a' || av[*i][j] == 'r' || av[*i][j] == 't'
			|| av[*i][j] == 'G'))
			{
				options[++k] = av[*i][j];
			}
		}
	}
	while (options[++k] && k < 6)
		options[k] = '.';
	return (options);
}
