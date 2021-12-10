/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:53:17 by youjeon           #+#    #+#             */
/*   Updated: 2021/10/14 16:12:08 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;
	size_t			i;

	if (!dest && !src)
		return (0);
	ptr_dest = (unsigned char *) dest;
	ptr_src = (unsigned char *) src;
	i = 0;
	if (src < dest)
		while (n--)
			ptr_dest[n] = ptr_src[n];
	else
		ft_memcpy(ptr_dest, ptr_src, n);
	return (dest);
}
