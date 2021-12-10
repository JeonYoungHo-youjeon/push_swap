/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:08:48 by youjeon           #+#    #+#             */
/*   Updated: 2021/10/14 16:13:22 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_mem;
	unsigned int	len;
	unsigned int	i;

	new_mem = NULL;
	if (s == 0 || f == 0)
		return (NULL);
	len = ft_strlen(s);
	new_mem = (char *)malloc(sizeof(char) * (len + 1));
	if (!(new_mem))
		return (NULL);
	new_mem[len] = 0;
	i = 0;
	while (i < len)
	{
		new_mem[i] = f(i, s[i]);
		i++;
	}
	return (new_mem);
}
