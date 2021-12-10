/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:45:39 by youjeon           #+#    #+#             */
/*   Updated: 2021/10/14 16:10:59 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*new_mem;
	size_t	length;

	new_mem = NULL;
	length = size * n;
	if (length == 0)
	{
		new_mem = malloc(0);
		return (new_mem);
	}
	if (length / n != size || length % size != 0)
		return (NULL);
	new_mem = malloc(length);
	if (!(new_mem))
		return (NULL);
	ft_bzero(new_mem, length);
	return (new_mem);
}
