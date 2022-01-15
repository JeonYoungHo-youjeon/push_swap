/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   introduction_sspa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:52:31 by youjeon           #+#    #+#             */
/*   Updated: 2022/01/15 14:13:42 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	sa(t_info *info)
{
	int	tmp;

	if (info->size_a < 2)
	{
		return ;
	}
	tmp = info->top_a->content;
	info->top_a->content = info->top_a->next->content;
	info->top_a->next->content = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_info *info)
{
	int	tmp;

	if (info->size_b < 2)
	{
		return ;
	}
	tmp = info->top_b->content;
	info->top_b->content = info->top_b->next->content;
	info->top_b->next->content = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_info *info)
{
	int	tmp;

	if (info->size_a < 2)
	{
		return ;
	}
	if (info->size_b < 2)
	{
		return ;
	}
	tmp = info->top_a->content;
	info->top_a->content = info->top_a->next->content;
	info->top_a->next->content = tmp;
	tmp = info->top_b->content;
	info->top_b->content = info->top_b->next->content;
	info->top_b->next->content = tmp;
	write(1, "ss\n", 3);
}

void	pa(t_info *info)
{
	t_numbers	*tmp;

	if (info->size_b < 1)
		return ;
	tmp = info->top_b;
	if (info->size_b > 1)
	{
		info->top_b = info->top_b->next;
		info->top_b->prev = NULL;
	}
	if (info->size_a == 0)
	{
		tmp->next = NULL;
		info->top_a = tmp;
		info->bottom_a = tmp;
	}
	else
	{
		tmp->next = info->top_a;
		info->top_a->prev = tmp;
		info->top_a = tmp;
	}
	info->size_a += 1;
	info->size_b -= 1;
	write(1, "pa\n", 3);
}

void	pb(t_info *info)
{
	t_numbers	*tmp;

	if (info->size_a < 1)
		return ;
	tmp = info->top_a;
	if (info->size_a > 1)
	{
		info->top_a = info->top_a->next;
		info->top_a->prev = NULL;
	}
	if (info->size_b == 0)
	{
		tmp->next = NULL;
		info->top_b = tmp;
		info->bottom_b = tmp;
	}
	else
	{
		tmp->next = info->top_b;
		info->top_b->prev = tmp;
		info->top_b = tmp;
	}
	info->size_a -= 1;
	info->size_b += 1;
	write(1, "pb\n", 3);
}
