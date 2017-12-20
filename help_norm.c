/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_norm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 11:59:51 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/20 16:16:29 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

struct stat	help_norm(char *name, char *file)
{
	struct stat	sb;
	char		*path;

	path = ft_str3join(name, "/", file);
	sb = e_lstat(path);
	free(path);
	return (sb);
}

void		put_file_type(mode_t m)
{
	(m == S_IFREG) ? putf("-") : 0;
	(m == S_IFDIR) ? putf("d") : 0;
	(m == S_IFLNK) ? putf("l") : 0;
	(m == S_IFSOCK) ? putf("s") : 0;
	(m == S_IFIFO) ? putf("p") : 0;
	(m == S_IFCHR) ? putf("c") : 0;
	(m == S_IFBLK) ? putf("b") : 0;
}
