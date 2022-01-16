/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:06:04 by youjeon           #+#    #+#             */
/*   Updated: 2022/01/16 17:02:09 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	get_str_size(int ac, char *av[])
{
	int		index;
	int		size;
	int		checker;
	char	**split_str;

	index = 0;
	size = 0;
	while (index < ac)
	{
		checker = 0;
		while (av[index][checker])
		{
			if (!ft_isspace(av[index][checker]))
				break ;
			checker++;
		}
		if (av[index][checker] == '\0')
			print_error(1);
		split_str = ft_split(av[index], ' ');
		size += get_size_split_str(split_str);
		ft_free_str(split_str);
		index++;
	}
	return (size - 1);
}

int	*ft_av_to_array(int ac, char *av[], int size)
{
	int		ac_index;
	int		arr_index;
	int		*new_array;
	char	**split_str;

	ac_index = 1;
	arr_index = 0;
	new_array = (int *)malloc(sizeof(int) * size);
	if (!new_array)
		print_error(1);
	while (ac_index < ac)
	{
		split_str = ft_split(av[ac_index], ' ');
		set_str_to_array(new_array, &arr_index, split_str);
		ft_free_str(split_str);
		ac_index++;
	}
	new_array[arr_index] = '\0';
	return (new_array);
}

void	ft_arr_to_stack(t_info *info, int *array, int size)
{
	t_numbers	*new_node;
	int			index;

	index = 0;
	while (index < size)
	{
		new_node = ft_stack_new();
		info->size_a += 1;
		info->bottom_a->content = (int)array[index];
		info->bottom_a->next = new_node;
		new_node->prev = info->bottom_a;
		info->bottom_a = new_node;
		index++;
	}
	info->bottom_a = info->bottom_a->prev;
	free(new_node);
}

void	ft_check_array_sort(int *array, int size, int index)
{
	int	j;
	int	checker;
	int	tmp;

	checker = 0;
	while (index < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				checker++;
			}
				j++;
		}
		if (array[index] == array[index + 1])
			print_error(1);
		index++;
	}
	if (checker == 0)
		print_error(-1);
}
