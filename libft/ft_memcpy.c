/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:11:21 by youjeon           #+#    #+#             */
/*   Updated: 2021/05/23 14:54:21 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	ptr_dest = dest;
	ptr_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*ptr_dest = *ptr_src;
		ptr_dest++;
		ptr_src++;
		i++;
	}
	return (dest);
}
