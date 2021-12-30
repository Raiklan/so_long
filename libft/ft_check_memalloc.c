/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_memalloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 17:55:04 by saich             #+#    #+#             */
/*   Updated: 2021/12/30 17:55:10 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_malloc(void *dest, size_t size)
{
	*(void **) dest = malloc(size);
	if (*(void **) dest == NULL)
		return (1);
	memset(*(void **) dest, 0, size);
	return (0);
}
