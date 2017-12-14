/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:37:18 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/14 15:21:07 by vbaudot          ###   ########.fr       */
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
# include <uuid/uuid.h>
# include "libft.h"

/*
typedef struct	s_ls
{
	char		*options;
	char		*primary;
	char		*secondary;
}				t_ls;
*/

void			sort_files_dir(int i, int ac, char ***av, char *options);
char			*options_init(int *i, int ac, char **av);
void			ft_ls(char *options, char *name);
void			print_usage(void);
void			ft_error(void);

#endif
