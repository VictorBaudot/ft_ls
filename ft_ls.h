/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:37:18 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/20 12:55:41 by vbaudot          ###   ########.fr       */
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

# define YEL "\x1b[33m"
# define BLU "\x1b[34m"
# define RED "\x1b[31m"
# define NC "\x1b[0m"
# define MAG "\x1b[35m"
# define CYA "\x1b[36m"
# define GRE "\x1b[32m"
# define BOL "\x1b[1m"
# define B_BLA "\x1b[90m"
# define B_R  "\x1b[91m"
# define B_G  "\x1b[92m"
# define B_Y "\x1b[93m"
# define B_BLU  "\x1b[94m"
# define B_MA  "\x1b[95m"
# define B_CY "\x1b[96m"
# define B_WH  "\x1b[97m"

typedef struct	s_pad
{
	int			pad_links;
	int			pad_size;
	int			pad_usr;
	int			pad_grp;
}				t_pad;

char			**ok_files(int i, int ac, char **av);
void			ft_error(void);
void			init_padding_files(t_pad *pad, char **av, char *options);
void			check_all_pads(char *path, t_pad **pad);
struct stat		help_norm(char *name, char *file);
struct stat		e_lstat(const char *name);
DIR				*e_opendir(const char *name);
int				count_files(char *name);
void			option_r(char *name, char **files, char *options, int ac_i);
void			print_file(char *path, char *file, char *options, t_pad pad);
void			print_files(char *name, char **files, char *options, t_pad pad);
void			sort_rev(int ac, char ***av);
void			sort_time(int ac, char ***av, char *name);
void			init_padding(t_pad *pad, char *name, char *options);
void			ls_file(char *name, t_pad pad);
void			count_blocks(char *options, char *name);
void			rev_ascii(int ac, char ***av);
int				has(const char *options, const char option);
int				is_chr(const char *path);
int				is_fifo(const char *path);
int				is_blk(const char *path);
int				is_socket(const char *path);
int				is_symlink(const char *path);
int				is_exec(const char *path);
int				is_directory(const char *path);
void			sort_files_by_type(int ac, char ***av);
void			sort_ascii(int i, int ac, char ***av);
char			*options_init(int *i, int ac, char **av, int k);
void			ft_ls(char *options, char *name, int ac);
void			print_usage(char c);

#endif
