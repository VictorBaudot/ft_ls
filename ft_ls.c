/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:17:00 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/13 17:40:10 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_file(char *name)
{
	struct stat sb;
	struct tm tm;

	if (stat(name, &sb) == -1) {
		perror("stat");
		exit(EXIT_SUCCESS);
	}

	printf("Type de fichier :                  ");

	switch (sb.st_mode & S_IFMT) {
		case S_IFBLK:  printf("périphérique de bloc\n");      break;
		case S_IFCHR:  printf("périphérique de caractère\n"); break;
		case S_IFDIR:  printf("répertoire\n");                break;
		case S_IFIFO:  printf("FIFO/tube\n");                 break;
		case S_IFLNK:  printf("lien symbolique\n");           break;
		case S_IFREG:  printf("fichier ordinaire\n");         break;
		case S_IFSOCK: printf("socket\n");                    break;
		default:       printf("inconnu ?\n");                 break;
	}
	printf("Numéro d'inœud :                   %ld\n", (long) sb.st_ino);
	printf("Mode :                             %lo (octal)\n", (unsigned long) sb.st_mode);
	printf("Nombre de liens :                  %ld\n", (long) sb.st_nlink);
	printf("Propriétaires :                    UID=%ld   GID=%ld\n",
	(long) sb.st_uid, (long) sb.st_gid);

	printf("Taille de bloc d’E/S :             %ld octets\n",
	(long) sb.st_blksize);
	printf("Taille du fichier :                %lld octets\n",
	(long long) sb.st_size);
	printf("Blocs alloués :                    %lld\n",
	(long long) sb.st_blocks);
	printf("Dernier changement d’état :        %s", ctime(&sb.st_ctime));
	printf("Dernier accès au fichier :         %s", ctime(&sb.st_atime));
	printf("Dernière modification du fichier:  %s", ctime(&sb.st_mtime));
	tm = 5;
	printf("%d %s\n", tm.tm_hour, name);
	exit(EXIT_SUCCESS);
}

void	ft_ls(char *name)
{
	DIR *dirp;
	struct dirent *dp;
	int len;

//	printf("%s\n", name);
	dirp = opendir(name);
	if ((dirp = opendir(name)) == NULL)
	{
		ls_file(name);
		return ;
	}
	len = strlen(name);
	while ((dp = readdir(dirp)) != NULL)
	{
		printf("%s\n", dp->d_name);
	}
	(void)closedir(dirp);
}
