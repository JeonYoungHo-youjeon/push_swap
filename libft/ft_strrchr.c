/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 18:00:47 by youjeon           #+#    #+#             */
/*   Updated: 2021/10/14 16:13:50 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ptr_str;
	char	to_find;
	int		i;

	ptr_str = (char *)str;
	to_find = (char)c;
	i = ft_strlen(str);
	if (to_find == '\0')
		return (&ptr_str[i]);
	while (i >= 0)
	{
		if (ptr_str[i] == to_find)
			return (&ptr_str[i]);
		i--;
	}
	return (NULL);
}
