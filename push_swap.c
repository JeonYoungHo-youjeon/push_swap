/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:43:08 by youjeon           #+#    #+#             */
/*   Updated: 2022/01/15 14:15:19 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	print_error(int type)
{
	if (type >= 1)
	{
		write(2, "Error\n", 6);
	}
	exit(1);
	return (-1);
}

t_numbers	*ft_stack_new(void)
{
	t_numbers	*new_mem;

	new_mem = NULL;
	new_mem = (t_numbers *)malloc(sizeof(t_numbers));
	new_mem->prev = NULL;
	new_mem->content = 0;
	new_mem->next = NULL;
	return (new_mem);
}

t_info	*ft_info_new(void)
{
	t_numbers	*stack_a;
	t_info		*new_mem;

	new_mem = NULL;
	new_mem = (t_info *)malloc(sizeof(t_info));
	stack_a = ft_stack_new();
	new_mem->array = NULL;
	new_mem->size_a = 0;
	new_mem->top_a = stack_a;
	new_mem->bottom_a = stack_a;
	new_mem->size_b = 0;
	return (new_mem);
}

int	main(int ac, char *av[])
{
	int			array_size;
	int			*num_array;
	t_info		*info;

	if (ac < 2)
	{
		print_error(-1);
	}	
	array_size = 0;
	info = ft_info_new();
	array_size = get_str_size(ac, av);
	num_array = ft_av_to_array(ac, av, array_size);
	ft_arr_to_stack(info, num_array, array_size);
	ft_check_array_sort(num_array, array_size, 0);
	info->array = (int *)num_array;
	ft_sort(info);
	return (0);
}
