/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:43:08 by youjeon           #+#    #+#             */
/*   Updated: 2022/01/15 13:03:29 by youjeon          ###   ########.fr       */
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

int	get_size_split_str(char **split_str)
{
	int	index;

	index = 0;
	while (split_str[index])
	{
		index++;
	}
	return (index);
}

void	ft_free_str(char **array)
{
	int	index;

	index = 0;
	while (array[index])
	{
		free(array[index]);
		index++;
	}
	free(array);
}

int	get_str_size(int ac, char *av[])
{
	int		index;
	int		size;
	char	**split_str;

	index = 0;
	size = 0;
	while (index < ac)
	{
		split_str = ft_split(av[index], ' ');
		size += get_size_split_str(split_str);
		ft_free_str(split_str);
		index++;
	}
	return (size - 1);
}



int	ft_atoll(const char *str)
{
	long long	result;
	int			np;
	int			chker;

	result = 0;
	np = 1;
	chker = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		np = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
		chker++;
	}
	result = result * np;
	if (*str != '\0' || chker > 10
		|| result > 2147483647 || result < -2147483648)
		print_error(1);
	return ((int)result);
}

void	set_str_to_array(int *array, int *arr_index, char **str)
{
	int	tmp_number;
	int	index;

	index = 0;
	while (str[index])
	{
		tmp_number = ft_atoll(str[index]);
		array[*arr_index] = tmp_number;
		(*arr_index)++;
		index++;
	}
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
		print_error(-12);
}

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

void	ra(t_info *info)
{
	t_numbers	*tmp;

	if (info->size_a < 2)
	{
		return ;
	}
	tmp = info->top_a;
	info->top_a = info->top_a->next;
	info->top_a->prev = NULL;
	info->bottom_a->next = tmp;
	tmp->prev = info->bottom_a;
	info->bottom_a = tmp;
	info->bottom_a->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_info *info)
{
	t_numbers	*tmp;

	if (info->size_b < 2)
	{
		return ;
	}
	tmp = info->top_b;
	info->top_b = info->top_b->next;
	info->top_b->prev = NULL;
	info->bottom_b->next = tmp;
	tmp->prev = info->bottom_b;
	info->bottom_b = tmp;
	info->bottom_a->next = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_info *info)
{
	t_numbers	*tmp;

	if (info->size_b < 2 || info->size_a < 2)
	{
		return ;
	}
	tmp = info->top_a;
	info->top_a = info->top_a->next;
	info->top_a->prev = NULL;
	info->bottom_a->next = tmp;
	tmp->prev = info->bottom_a;
	info->bottom_a = tmp;
	info->bottom_a->next = NULL;
	tmp = info->top_b;
	info->top_b = info->top_b->next;
	info->top_b->prev = NULL;
	info->bottom_b->next = tmp;
	tmp->prev = info->bottom_b;
	info->bottom_b = tmp;
	info->bottom_a->next = NULL;
	write(1, "rr\n", 3);
}

void	rra(t_info *info)
{
	t_numbers	*tmp;

	if (info->size_a < 2)
	{
		return ;
	}
	tmp = info->bottom_a;
	info->bottom_a = info->bottom_a->prev;
	info->bottom_a->next = NULL;
	info->top_a->prev = tmp;
	tmp->next = info->top_a;
	info->top_a = tmp;
	info->top_a->prev = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_info *info)
{
	t_numbers	*tmp;

	if (info->size_b < 2)
	{
		return ;
	}
	tmp = info->bottom_b;
	info->bottom_b = info->bottom_b->prev;
	info->bottom_b->next = NULL;
	info->top_b->prev = tmp;
	tmp->next = info->top_b;
	info->top_b = tmp;
	info->top_b->prev = NULL;
	write(1, "rrb\n", 4);
}

void	rrr(t_info *info)
{
	t_numbers	*tmp;

	if (info->size_b < 2 || info->size_a < 2)
	{
		return ;
	}
	tmp = info->bottom_a;
	info->bottom_a = info->bottom_a->prev;
	info->bottom_a->next = NULL;
	info->top_a->prev = tmp;
	tmp->next = info->top_a;
	info->top_a = tmp;
	info->top_a->prev = NULL;
	tmp = info->bottom_b;
	info->bottom_b = info->bottom_b->prev;
	info->bottom_b->next = NULL;
	info->top_b->prev = tmp;
	tmp->next = info->top_b;
	info->top_b = tmp;
	info->top_b->prev = NULL;
	write(1, "rrr\n", 4);
}

void	ft_sort_a_three(t_info *info)
{
	int	top;
	int	mid;
	int	bot;

	top = info->top_a->content;
	mid = info->top_a->next->content;
	bot = info->top_a->next->next->content;
	if (top > mid && mid > bot && top > bot)
	{
		sa(info);
		rra(info);
	}
	else if (top > mid && bot > mid && top > bot)
		ra(info);
	else if (mid > top && mid > bot && bot > top)
	{
		sa(info);
		ra(info);
	}
	else if (top > mid && bot > mid && bot > top)
		sa(info);
	else if (mid > top && mid > bot && top > bot)
		rra(info);
}

void	ft_sort_3div_insruct(t_info *info, int pivot1, int pivot2)
{
	if (info->top_a->content < pivot1)
	{
		pb(info);
		rb(info);
	}
	else if (info->top_a->content < pivot2)
		pb(info);
	else
		ra(info);
}

void	ft_sort_three_division(t_info *info)
{
	int	index;
	int	pivot1;
	int	pivot2;

	index = info->size_a / 3;
	pivot1 = info->array[index];
	index = info->size_a * 2 / 3;
	pivot2 = info->array[index];
	index = info->size_a;
	while (index)
	{
		ft_sort_3div_insruct(info, pivot1, pivot2);
		index--;
	}
}

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

int	set_a_location(int num, t_info *info)
{
	int	ret;

	if (num < get_stack_min(info->top_a))
		ret = set_a_location_min(info);
	else if (num > get_stack_max(info->top_a))
		ret = set_a_location_max(info);
	else
		ret = set_a_location_mid(num, info);
	return (ret);
}

int	ft_get_bigger(int a, int b, int a_loc, int b_loc)
{
	if (a < 0)
		a = a * -1;
	if (b < 0)
		b = b * -1;
	if (a_loc < 0)
		a_loc = a_loc * -1;
	if (b_loc < 0)
		b_loc = b_loc * -1;
	if (a + b > a_loc + b_loc)
		return (1);
	else
		return (0);
}

void	get_min_rotate(t_info *info, int *a, int *b)
{
	int			a_location;
	int			b_location;
	int			index;
	t_numbers	*stack_b;
	int			num;

	index = 0;
	stack_b = info->top_b;
	while (index < info->size_b)
	{
		num = stack_b->content;
		a_location = set_a_location(num, info);
		if (index >= (info->size_b + 1) / 2)
			b_location = (info->size_b - index) * -1;
		else
			b_location = index;
		if (index == 0 || ft_get_bigger(*a, *b, a_location, b_location))
		{
			*a = a_location;
			*b = b_location;
		}
		stack_b = stack_b->next;
		index++;
	}
}

void	ft_rotate_same(t_info *info, int *a, int *b)
{
	while (*a && *b && (*a > 0 && *b > 0))
	{
		rr(info);
		*a = *a - 1;
		*b = *b - 1;
	}
	while (*a && *b && (*a < 0 && *b < 0))
	{
		rrr(info);
		*a = *a + 1;
		*b = *b + 1;
	}
}

void	ft_rotate_a(t_info *info, int a)
{
	while (a)
	{
		if (a > 0)
		{
			ra(info);
			a--;
		}
		else
		{
			rra(info);
			a++;
		}
	}
}

void	ft_rotate_b(t_info *info, int b)
{
	while (b)
	{
		if (b > 0)
		{
			rb(info);
			b--;
		}
		else
		{
			rrb(info);
			b++;
		}
	}
}

void	ft_sort_big_last(t_info *info)
{
	int	min;
	int	min_location;

	min = get_stack_min(info->top_a);
	min_location = set_a_location_min(info);
	while (min_location)
	{
		if (min_location > 0)
		{
			ra(info);
			min_location--;
		}
		else
		{
			rra(info);
			min_location++;
		}
	}
}

void	ft_sort_big(t_info *info)
{
	int	a;
	int	b;

	ft_sort_three_division(info);
	while (info->size_a > 3)
		pb(info);
	if (info->size_a == 2)
	{
		if (info->top_a->content > info->top_a->next->content)
			sa(info);
	}
	if (info->size_a == 3)
		ft_sort_a_three(info);
	while (info->size_b)
	{
		a = 0;
		b = 0;
		get_min_rotate(info, &a, &b);
		ft_rotate_same(info, &a, &b);
		ft_rotate_a(info, a);
		ft_rotate_b(info, b);
		pa(info);
	}
	ft_sort_big_last(info);
}

void	ft_sort(t_info *info)
{
	if (info->size_a == 2)
	{
		if (info->top_a->content > info->top_a->next->content)
			sa(info);
	}
	else if (info->size_a == 3)
	{
		ft_sort_a_three(info);
	}
	else
	{
		ft_sort_big(info);
	}
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
