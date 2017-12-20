/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 14:04:58 by vbaudot           #+#    #+#             */
/*   Updated: 2017/12/20 14:35:23 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_usage(char c)
{
	putf("ls: illegal option -- %c\nusage: ./ft_ls [-lRGgartf] [file ...]\n", c);
	exit(EXIT_SUCCESS);
}
