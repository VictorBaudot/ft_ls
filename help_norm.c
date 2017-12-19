/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_norm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 11:59:51 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/19 12:07:09 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

struct stat	help_norm(char *name, char *file)
{
	char		*path;
	struct stat	sb;

	path = ft_str3join(name, "/", file);
	sb = e_lstat(path);
	free(path);
	return (sb);
}
