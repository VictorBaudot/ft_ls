/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 09:43:26 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/20 16:48:05 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_and_call_ls(char **files, char *options, int ac)
{
	t_pad	pad;
	int		i;
	int		j;

	(has(options, 't')) ? sort_time(ac, &files, ".") : 0;
	(has(options, 'r')) ? sort_rev(ac, &files) : 0;
	sort_files_by_type(ac, &files);
	if (has(options, 'l') || has(options, 'g'))
		init_padding_files(&pad, files, options);
	i = -1;
	while (files[++i] && !is_directory(files[i]))
		print_file(files[i], files[i], options, pad);
	j = (i > 0) ? 1 : 0;
	while (files[i])
	{
		ft_ls(options, files[i], ac, j);
		i++;
	}
}

int		main(int ac, char **av)
{
	int		i;
	char	*options;
	char	**files;

	i = 0;
	options = options_init(&i, ac, av, -1);
	if (i > 1 && i != ac)
		(ft_strcmp(av[i], "--") == 0) ? i++ : 0;
	if (i == ac)
		ft_ls(options, ".", 1, 0);
	else
	{
		(!has(options, 'f')) ? sort_ascii(i, ac, &av) : 0;
		files = ok_files(i, ac, av);
		ac = 0;
		while (files[ac])
			ac++;
		sort_and_call_ls(files, options, ac);
		i = -1;
		while (files[++i])
			free(files[i]);
		free(files);
	}
	free(options);
	return (EXIT_SUCCESS);
}
