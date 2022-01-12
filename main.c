/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:43:08 by youjeon           #+#    #+#             */
/*   Updated: 2022/01/12 17:20:23 by youjeon          ###   ########.fr       */
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
	printf("%d\n", type);
	if (type >= 1)
	{
		write(2, "Error\n", 6);
	}
	else if (type <= -1)
	{
		write(2, "\n", 1);
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
	t_info	*new_mem;

	new_mem = NULL;
	new_mem = (t_info *)malloc(sizeof(t_info));
	new_mem->size_a = 0;
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

long long	ft_atoll(const char *str)
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
	return (result);
}

void	set_str_to_array(long long *array, int *arr_index, char **str)
{
	long long	tmp_number;
	int			index;

	index = 0;
	while (str[index])
	{
		tmp_number = ft_atoll(str[index]);
		array[*arr_index] = tmp_number;
		(*arr_index)++;
		index++;
	}
}

long long	*ft_av_to_array(int ac, char *av[], int size)
{
	int			ac_index;
	int			arr_index;
	long long	*new_array;
	char		**split_str;

	ac_index = 1;
	arr_index = 0;
	new_array = (long long *)malloc(sizeof(long long) * size);
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

void	ft_arr_to_stack(t_numbers *stack, long long *array, t_info *info, int size)
{
	t_numbers	*new_node;
	int			index;

	index = 0;
	while (index < size)
	{
		new_node = ft_stack_new();
		info->size_a++;
		stack->content = (int)array[index];
		stack->next = new_node;
		new_node->prev = stack;
		stack = stack->next;
		index++;
	}
	printf("ft_arr_to_stack index = %d\n", index);
}

void	ft_array_sort(long long *array, int size)
{
	int	index;
	int	checker;
	int	tmp;

	index = 0;
	checker = 0;
	while (index < size - 1)
	{
		if (array[index] > array[index + 1])
		{
			tmp = array[index];
			array[index] = array[index + 1];
			array[index + 1] = tmp;
			checker++;
		}
		if (array[index] == array[index + 1])
		{
			print_error(1);
		}
		index++;
	}
	if (checker == 0)
	{
		print_error(-1);
	}
}

void	test_print_array(long long *array, int size)
{
	int	index;

	printf("test_print_array\n");
	index = 0;
	while (index < size)
	{
		printf("%d\n", (int)array[index]);
		index++;
	}
}

void	test_print_stack(t_numbers *stack)
{
	while (stack->next)
	{
		printf("%d\n", stack->content);
		stack = stack->next;
	}
}

void	sa(t_numbers *a, t_info *info)
{
	int	tmp;

	if (info->size_a < 2)
	{
		print_error(3);
	}
	tmp = a->next->content;
	a->next->content = a->content;
	a->content = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_numbers *b, t_info *info)
{
	int	tmp;

	if (info->size_b < 2)
	{
		print_error(4);
	}
	tmp = b->next->content;
	b->next->content = b->content;
	b->content = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_numbers *a, t_numbers *b, t_info *info)
{
	int	tmp;

	if (info->size_a < 2)
	{
		print_error(5);
	}
	if (info->size_b < 2)
	{
		print_error(6);
	}
	tmp = a->next->content;
	a->next->content = a->content;
	a->content = tmp;
	tmp = b->next->content;
	b->next->content = b->content;
	b->content = tmp;
	write(1, "ss\n", 3);
}

void	pa(t_numbers **a, t_numbers **b, t_info *info)
{
	t_numbers	*tmp;

	if (info->size_b < 1)
	{
		print_error(7);
	}
	tmp = *b;
	*b = (*b)->next;
	(*a)->prev = tmp;
	tmp->next = (*a);
	*a = tmp;
	info->size_a += 1;
	info->size_b -= 1;
	write(1, "pa\n", 3);
}

void	pb(t_numbers **a, t_numbers **b, t_info *info)
{
	t_numbers	*tmp;

	if (info->size_a < 1)
	{
		print_error(8);
	}
	tmp = *a;
	*a = (*a)->next;
	(*b)->prev = tmp;
	tmp->next = (*b);
	*b = tmp;
	info->size_a -= 1;
	info->size_b += 1;
	write(1, "pb\n", 3);
}

void	test_instuct(t_numbers *a, t_numbers *b, t_info *info)
{
	printf("test_instuct\n");
	printf("test_print_stack(a);\n");
	test_print_stack(a);
	printf("size_a = %d\n", info->size_a);
	printf("sa(a, info);\n");
	sa(a, info);
	test_print_stack(a);
	printf("pb(&a, &b, info)*3 stack_a b\n");
	pb(&a, &b, info);
	pb(&a, &b, info);
	pb(&a, &b, info);
	printf("stack_a\n");
	test_print_stack(a);
	printf("size_a = %d\n", info->size_a);
	printf("stack_b\n");
	test_print_stack(b);
	printf("size_b = %d\n", info->size_b);
	sb(b, info);
	printf("stack_b\n");
	test_print_stack(b);
	pa(&a, &b, info);
	printf("stack_a\n");
	test_print_stack(a);
	printf("size_a = %d\n", info->size_a);
	printf("stack_b\n");
	test_print_stack(b);
	printf("size_b = %d\n", info->size_b);
	ss(a, b, info);
	printf("stack_a\n");
	test_print_stack(a);
	printf("stack_b\n");
	test_print_stack(b);
}

int	main(int ac, char *av[])
{
	int			array_size;
	long long	*num_array;
	t_numbers	*stack_a;
	t_numbers	*stack_b;
	t_info		*info;

	if (ac < 2)
	{
		print_error(-1);
	}	
	array_size = 0;
	stack_a = ft_stack_new();
	stack_b = ft_stack_new();
	info = ft_info_new();
	array_size = get_str_size(ac, av);
	num_array = ft_av_to_array(ac, av, array_size);
	test_print_array(num_array, array_size);
	// printf("size_a = %d\n", info->size_a);
	ft_arr_to_stack(stack_a, num_array, info, array_size);
	// printf("size_a = %d\n", info->size_a);
	// printf("size = %d\n" , get_stack_size(stack_a));
	// printf("size = %d\n" , get_stack_size(stack_b));
	// test_print_stack(stack_a);
	test_instuct(stack_a, stack_b, info);
	ft_array_sort(num_array, array_size);
	// test_print_array(num_array, array_size);
	//system("leaks main > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
	return (0);
}
