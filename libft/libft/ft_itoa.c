/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 16:28:48 by saich             #+#    #+#             */
/*   Updated: 2021/11/04 17:00:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	power(long nbr, int powa)
{
	if (powa < 0)
		return (0);
	if (powa == 0)
		return (1);
	return (nbr * power(nbr, powa - 1));
}

static int	nega(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static int	nul(int n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		i = 1;
		return (i);
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		i;
	int		j;
	long	nbr;

	i = 0;
	nbr = n;
	i = nul(n);
	while (nbr != 0 && i++ <= 2147483647)
		nbr /= 10;
	dest = malloc(sizeof(char) * i + 1 + nega(n));
	if (!dest)
		return (0);
	j = 0;
	nbr = n;
	if (nega(nbr) == 1)
	{
		dest[0] = '-';
		j = 1;
		nbr = -nbr;
	}
	while (i-- > 0)
		dest[j++] = nbr / power(10, i) % 10 + '0';
	dest[j] = '\0';
	return (dest);
}
/*
char			*ft_itoa(int n)
{
	char	*dest;
	int		i;
	int		j;
	long	nbr;

	i = 0;
	nbr = n;
	n == 0 ? i = 1 : 0;
	while (nbr != 0 && i++ <= 2147483647)
		nbr /= 10;
	if (!(dest = malloc(sizeof(char) * i + 1 + (n < 0 ? 1 : 0))))
		return (0);
	j = 0;
	nbr = n;
	if (nega(nbr) == 1)
	{
		dest[0] = '-';
		j = 1;
		nbr = -nbr;
	}
	while (i-- > 0)
		dest[j++] = nbr / power(10, i) % 10 + '0';
	dest[j] = '\0';
	return (dest);
}
*/
