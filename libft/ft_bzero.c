/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 11:30:45 by youjeon           #+#    #+#             */
/*   Updated: 2021/05/13 18:38:09 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *str, size_t n)
{
	unsigned char	*ptr_str;
	size_t			i;

	ptr_str = str;
	i = 0;
	while (i < n)
	{
		*ptr_str = 0;
		ptr_str++;
		i++;
	}
	return (str);
}
