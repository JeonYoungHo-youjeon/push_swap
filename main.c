/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:43:08 by youjeon           #+#    #+#             */
/*   Updated: 2022/01/15 12:26:15 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t len)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	i = 0;
	while (src[src_len])
		src_len++;
	if (len == 0)
	{
		return (src_len);
	}
	while (i < len - 1 && *src)
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	*dst = '\0';
	return (src_len);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

static size_t	get_word_cnt(char const *str, char c)
{
	size_t	count;
	int		chker;

	count = 0;
	chker = 1;
	while (*str != '\0' && *str == c)
		str++;
	while (*str)
	{
		if (chker == 1 && *str != c)
		{
			count++;
			chker = 0;
		}
		if (*str == c)
			chker = 1;
		str++;
	}
	return (count);
}

static void	*is_free(char **str, int str_index)
{
	int	i;

	i = 0;
	while (i < str_index)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static char	**set_worddup(char const *s, char c, char **mem)
{
	size_t	word_length;
	int		i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		word_length = 0;
		while (s[word_length] && s[word_length] != c)
			word_length++;
		mem[i] = (char *)malloc(sizeof(char) * (word_length + 1));
		if (!(mem[i]))
			return (is_free(mem, i));
		ft_strlcpy(mem[i], s, word_length + 1);
		s = s + word_length;
		i++;
	}
	mem[i] = NULL;
	return (mem);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	char	**new_mem;

	new_mem = NULL;
	if (!s)
		return (NULL);
	word_count = get_word_cnt(s, c);
	new_mem = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!(new_mem))
		return (NULL);
	new_mem = set_worddup(s, c, new_mem);
	return (new_mem);
}

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

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
	{
		return (1);
	}
	return (0);
}

int		ft_atoll(const char *str)
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

int		*ft_av_to_array(int ac, char *av[], int size)
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

// void	test_print_array(int *array, int size)
// {
// 	int	index;

// 	index = 0;
// 	while (index < size)
// 	{
// 		index++;
// 	}
// }

int test_index = 0;

void	test_print_stack(t_info *info)
{
	int			index;
	t_numbers	*stack;

	test_index++;
	
	//printf("test_index = %d\n", test_index);
	printf("stack_a\n");
	index = 0;
	stack = info->top_a;
	while (index < info->size_a)
	{
		printf("%d\n", stack->content);
		stack = stack->next;
		index++;
	}
	printf("stack_b\n");
	index = 0;
	stack = info->top_b;
	while (index < info->size_b)
	{
		printf("%d\n", stack->content);
		stack = stack->next;
		index++;
	}
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

void	test_instuct(t_info *info)
{
	printf("test_instuct\n");
	test_print_stack(info);
	printf("size_a = %d\n", info->size_a);
	sa(info);
	test_print_stack(info);
	pb(info);
	pb(info);
	pb(info);
	test_print_stack(info);
	printf("size_a = %d\n", info->size_a);
	printf("size_b = %d\n", info->size_b);
	sb(info);
	test_print_stack(info);
	pa(info);
	test_print_stack(info);
	printf("size_a = %d\n", info->size_a);
	printf("size_b = %d\n", info->size_b);
	ss(info);
	test_print_stack(info);
	pa(info);
	pa(info);
	test_print_stack(info);
	pb(info);
	pb(info);
	pb(info);
	pb(info);
	test_print_stack(info);
	printf("size_a = %d\n", info->size_a);
	printf("size_b = %d\n", info->size_b);
	pa(info);
	pa(info);
	pa(info);
	pa(info);
	test_print_stack(info);
	printf("size_a = %d\n", info->size_a);
	printf("size_b = %d\n", info->size_b);
	pb(info);
	pb(info);
	pb(info);
	test_print_stack(info);
	printf("size_a = %d\n", info->size_a);
	printf("size_b = %d\n", info->size_b);
	ra(info);
	rb(info);
	test_print_stack(info);
	rr(info);
	test_print_stack(info);
	rra(info);
	rrb(info);
	test_print_stack(info);
	rrr(info);
	test_print_stack(info);
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

int		get_stack_min(t_numbers *stack)
{
	int	ret;


	//printf("get_stack_min start\n");
	ret = stack->content;
	while (stack)
	{
		// printf("get_stack_min ret = %d\n", ret);
		// printf("get_stack_min stack->content = %d\n", stack->content);
		if (ret > stack->content)
		{
			ret = stack->content;
			//printf("get_stack_min ret = %d\n", ret);
		}
		stack = stack->next;
	}
	//printf("get_stack_min end\n");
	return (ret);
}

int		set_a_location_min(t_info *info)
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


int		get_stack_max(t_numbers *stack)
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

int		set_a_location_max(t_info *info)
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

int		set_a_location_mid(int num, t_info *info)
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

int		set_a_location(int num, t_info *info)
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

int		ft_get_bigger(int a, int b, int a_loc, int b_loc)
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
		//printf("get_min_rotate *a = %d, *b = %d, a_location = %d, b_location = %d\n", *a, *b, a_location, b_location);
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

void	ft_rotate_diff(t_info *info, int a, int b)
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
		//test_print_stack(info);
		get_min_rotate(info, &a, &b);
		ft_rotate_same(info, &a, &b);
		ft_rotate_diff(info, a, b);
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
	system("leaks main > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
	return (0);
}
