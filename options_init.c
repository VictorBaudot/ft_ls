/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:18:44 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/20 16:32:11 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	*check_f(char *options, int k)
{
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

static int	check_params(char c, int l)
{
	if (l == 8 && (c == 'l' || c == 'R' ||
	c == 'a' || c == 'r' || c == 't'
	|| c == 'G' || c == 'f' || c == 'g'))
		return (1);
	return (0);
}

char		*options_init(int *i, int ac, char **av, int k)
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
			(check_params(av[*i][j], l) == 1) ? options[++k] = av[*i][j] : 0;
		}
	}
	options = check_f(options, k);
	return (options);
}
