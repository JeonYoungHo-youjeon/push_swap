/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_get_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:59:29 by youjeon           #+#    #+#             */
/*   Updated: 2022/01/15 14:01:48 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	get_stack_min(t_numbers *stack)
{
	int	ret;

	ret = stack->content;
	while (stack)
	{
		if (ret > stack->content)
		{
			ret = stack->content;
		}
		stack = stack->next;
	}
	return (ret);
}

int	set_a_location_min(t_info *info)
{
	int			ret;
	int			index;
	int			tmp;
	t_numbers	*stack_a;

	ret = 0;
	tmp = 0;
	stack_a = info->top_a;
	index = get_stack_min(stack_a);
	while (stack_a)
	{
		tmp = stack_a->content;
		if (tmp == index)
			break ;
		ret++;
		stack_a = stack_a->next;
	}
	if (ret >= (info->size_a + 1) / 2)
		ret = (info->size_a - ret) * -1;
	return (ret);
}

int	get_stack_max(t_numbers *stack)
{
	int	ret;

	ret = stack->content;
	while (stack)
	{
		if (ret < stack->content)
		{
			ret = stack->content;
		}
		stack = stack->next;
	}
	return (ret);
}

int	set_a_location_max(t_info *info)
{
	int			ret;
	int			index;
	int			tmp;
	t_numbers	*stack_a;

	ret = 0;
	tmp = 0;
	stack_a = info->top_a;
	index = get_stack_max(stack_a);
	while (stack_a)
	{
		tmp = stack_a->content;
		if (tmp == index)
			break ;
		ret++;
		stack_a = stack_a->next;
	}
	ret++;
	if (ret >= (info->size_a + 1) / 2)
		ret = (info->size_a - ret) * -1;
	return (ret);
}

int	set_a_location_mid(int num, t_info *info)
{
	t_numbers	*stack_a;
	int			ret;

	stack_a = info->top_a;
	ret = 1;
	while (stack_a->next)
	{
		if (num > stack_a->content && num < stack_a->next->content)
			break ;
		ret++;
		stack_a = stack_a->next;
	}
	if (ret >= (info->size_a + 1) / 2)
		ret = (info->size_a - ret) * -1;
	return (ret);
}
