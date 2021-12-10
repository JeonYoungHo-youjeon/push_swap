/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 18:39:21 by youjeon           #+#    #+#             */
/*   Updated: 2021/10/14 16:06:14 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (lst == NULL || new == NULL)
	{
		return ;
	}
	current = NULL;
	if (*lst)
	{
		current = ft_lstlast(*lst);
		current->next = new;
	}
	else
	{
		*lst = new;
	}
}
