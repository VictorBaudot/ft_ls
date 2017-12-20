/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 09:43:26 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/20 10:03:59 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int ok_files(int i, int ac, char **av)
{
	int ok;
	struct stat	sb;

	ok = 0;
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
	return (ok);
}

void	sort_and_call_ls(int i, int ac, char **av, char *options)
{
	int		args;
	t_pad	pad;
	int		ok;

	sort_ascii(i, ac, &av);
	(has(options, 't')) ? sort_time(i, ac, &av, ".") : 0;
	(has(options, 'r')) ? sort_rev(i, ac, &av) : 0;
	ok = ok_files(i, ac, av);
	putf("ok: %d\n", ok);
	sort_files_by_type(i, ac, &av, options);
	(has(options, 'l')) ? init_padding_files(&pad, &av[i], options) : 0;
	args = ac - i;
	while (i < ac && !is_directory(av[i]))
	{
		print_file(av[i], av[i], options, pad);
		i++;
	}
	while (i < ac)
	{
		ft_ls(options, av[i], args);
		i++;
	}
}

int		main(int ac, char **av)
{
	int		i;
	char	*options;

	i = 0;
	options = options_init(&i, ac, av, -1);
	if (i > 1 && i != ac)
		if (ft_strcmp(av[i], "--") == 0)
			i++;
//	putf("Options: %s\n", options);
	if (i == ac)
		ft_ls(options, ".", 0);
	else
	{
		sort_and_call_ls(i, ac, av, options);
	}
	free(options);
//	while (42){}
	return (EXIT_SUCCESS);
}
