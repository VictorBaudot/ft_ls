/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:18:44 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/17 14:39:13 by vbaudot          ###   ########.fr       */
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
	options = (char*)malloc(sizeof(char) * 6);
	options[5] = 0;
	while (++(*i) < ac && k < 5 && av[*i][0] == '-')
	{
		j = 0;
		while (av[*i][++j] && k < 5)
		{
			l = -1;
			while (++l < 5)
				if (av[*i][j] == options[l])
				{
					break ;
				}
			if (l == 5 && (av[*i][j] == 'l' || av[*i][j] == 'R' ||
			av[*i][j] == 'a' || av[*i][j] == 'r' || av[*i][j] == 't'))
			{
				options[++k] = av[*i][j];
			}
		}
	}
	while (options[++k] && k < 5)
		options[k] = '.';
	return (options);
}
