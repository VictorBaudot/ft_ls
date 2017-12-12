/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:54:27 by vbaudot           #+#    #+#             */
/*   Updated: 2017/11/13 10:06:06 by vbaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_bis(char *ret, int n, long i, long m)
{
	long p;

	p = ft_abs(n);
	if (n == 0)
		return (ft_strdup("0"));
	i = 0;
	while (p != 0)
	{
		ret[i] = (p % 10) + 48;
		p /= 10;
		i++;
	}
	if (m == 1)
	{
		ret[i] = '-';
		i++;
	}
	ret[i] = '\0';
	return (ft_strreverse(ret));
}

char		*ft_itoa(int n)
{
	long	i;
	long	m;
	int		count;
	char	*ret;

	i = 1;
	m = 0;
	count = 1;
	if (n < 0)
		m = 1;
	if (m == 1)
		while (-i >= n)
		{
			i *= 10;
			count++;
		}
	else
		while (i <= n)
		{
			i *= 10;
			count++;
		}
	if (!(ret = (char *)malloc(sizeof(char) * (count + 1 + m))))
		return (NULL);
	return (ft_itoa_bis(ret, n, i, m));
}
