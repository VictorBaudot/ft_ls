/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:37:18 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/15 17:32:09 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <sys/xattr.h>
# include "libft.h"

/*
typedef struct	s_ls
{
	char		*options;
	char		*primary;
	char		*secondary;
}				t_ls;
*/

void			rev_ascii(int i, int ac, char ***av);
int				has(const char *options, const char option);
int				is_directory(const char *path);
void			sort_files_by_type(int i, int ac, char ***av, char *options);
void			sort_ascii(int i, int ac, char ***av);
char			*options_init(int *i, int ac, char **av);
void			ft_ls(char *options, char *name);
void			print_usage(void);
void			ft_error(void);

#endif
