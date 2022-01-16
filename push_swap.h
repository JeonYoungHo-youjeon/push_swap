/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:57:59 by youjeon           #+#    #+#             */
/*   Updated: 2022/01/15 14:40:19 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_numbers
{
	struct s_numbers	*prev;
	int					content;
	struct s_numbers	*next;
}			t_numbers;

typedef struct s_info
{
	int					*array;
	int					size_a;
	struct s_numbers	*top_a;
	struct s_numbers	*bottom_a;
	int					size_b;
	struct s_numbers	*top_b;
	struct s_numbers	*bottom_b;
}			t_info;

/*
	array_util.c
*/
int			get_size_split_str(char **split_str);
void		ft_free_str(char **array);
int			ft_atoll(const char *str);
void		set_str_to_array(int *array, int *arr_index, char **str);

/*
	array.c
*/
int			get_str_size(int ac, char *av[]);
int			*ft_av_to_array(int ac, char *av[], int size);
void		ft_arr_to_stack(t_info *info, int *array, int size);
void		ft_check_array_sort(int *array, int size, int index);

/*
	introduction_rr.c
*/
void		ra(t_info *info);
void		rb(t_info *info);
void		rr(t_info *info);

/*
	introduction_rrr.c
*/
void		rra(t_info *info);
void		rrb(t_info *info);
void		rrr(t_info *info);

/*
	introduction_sspa.c
*/
void		sa(t_info *info);
void		sb(t_info *info);
void		ss(t_info *info);
void		pa(t_info *info);
void		pb(t_info *info);

/*
	push_swap.c
*/
int			print_error(int type);
t_numbers	*ft_stack_new(void);
t_info		*ft_info_new(void);
int			main(int ac, char *av[]);

/*
	sort_rotate_util.c
*/
int			get_stack_min(t_numbers *stack);
int			set_a_location_min(t_info *info);
int			get_stack_max(t_numbers *stack);
int			set_a_location_max(t_info *info);
int			set_a_location_mid(int num, t_info *info);

/*
	sort_rorate.c
*/
void		ft_rotate_same(t_info *info, int *a, int *b);
void		ft_rotate_a(t_info *info, int a);
void		ft_rotate_b(t_info *info, int b);
int			set_a_location(int num, t_info *info);

/*
	sort_util.c
*/
void		ft_sort_big_last(t_info *info);
void		ft_sort_3div_insruct(t_info *info, int pivot1, int pivot2);
void		ft_sort_three_division(t_info *info);
int			ft_get_bigger(int a, int b, int a_loc, int b_loc);
void		get_min_rotate(t_info *info, int *a, int *b);

/*
	sort.c
*/
void		ft_sort_a_three(t_info *info);
void		ft_sort_big(t_info *info);
void		ft_sort(t_info *info);

#endif