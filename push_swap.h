/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:06:21 by hurabe            #+#    #+#             */
/*   Updated: 2024/09/22 18:44:26 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//include
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>

//struct Doubly Linked List
//値を保持する双方向リストの構造体,valueはリストの要素、press_valは座標圧縮で使用。
typedef struct s_dst
{
	long			value; // このノードが保持する主なデータ。この値がソートの対象となる。
	long			press_val; // 追加のデータ。座標圧縮など、ソートに関連する追加の情報を保持するために使われる値。
	struct s_dst	*next; // 次のノードへのポインタ。これにより、双方向リストの次のノードにアクセスできる。
	struct s_dst	*prev; // 前のノードへのポインタ。これにより、双方向リストの前のノードにアクセスできる。
}					t_dst;

//基数ソートの設定を保持するための構造体。lenはスタックの長さ、mux_numはスタック内の最大値を表す。
typedef struct s_config
{
	int		len;
	int		max_num;
}			t_config;

//libft
int		ft_atoi(const char *str);
long	ft_atol(char *str);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
int		ft_strcmp(char *s1, char *s2);
t_dst	*ft_lstnew(long value);
int		ft_lstsize(t_dst *dst);
t_dst	*ft_lstlast(t_dst *dst);
void	ft_lstadd_back(t_dst **dst, t_dst *new);
void	ft_lstclear(t_dst **lst);


//command process function
//スタックを操作するコマンド関数
//void	push(t_dst **send, t_dst **recieve);
//void	reverse_rotate(t_dst **dst);
//void	rotate(t_dst **dst);
//void	swap(t_dst **dst);

//command process items
//スタックを操作するコマンド関数
void	sa(t_dst **a);
void	sb(t_dst **b);
void	ss(t_dst **a, t_dst **b);
void	pa(t_dst **a, t_dst **b);
void	pb(t_dst **a, t_dst **b);
void	ra(t_dst **a);
void	rb(t_dst **b);
void	rr(t_dst **a, t_dst **b);
void	rra(t_dst **a);
void	rrb(t_dst **b);
void	rrr(t_dst **a, t_dst **b);

//error
//エラーチェック
int		output_error(void);
void	error_component(char **stk, char **argv, int i);
int		is_argv_error(char **argv);

//coordinate press
//座標圧縮、値の範囲を縮めて基数ソートの効率を図る
//int		partition(long *arr, int low, int high);
//void	quicksort(long *arr, int low, int high);
//long	*sort(char **argv, int len);
long	*coordinate_press(char **argv, int len);

// init_dst
void	init_dst(t_dst **a, t_dst **b, char **argv, t_config *conf);
int		is_ascending(t_dst **a);
int		is_descending(t_dst **b);

// ps_isfunction
void	three_arg(char **argv, t_dst **a, t_dst **b);
int		is_swap(t_dst **a, t_dst **b);
int		is_rotate(t_dst **a, t_dst **b);
void	let_go(t_dst **a, t_dst **b, int is_swap, int is_rotate);
int		alg_1(t_dst **a, t_dst **b);

//radix sort
//基数ソート本体、スタックA（t_dst **a）をソートし、必要に応じてスタックB（t_dst **b）を使用してデータの移動を行う
//long	get_top(t_dst *dst);
void	radix_sort(t_dst **a, t_dst **b, t_config *conf);

// sep_pivot
long	get_pivot_n(char **argv);
void	sep_pivot(char **argv, t_dst **a, t_dst **b, long pivot_num);

//main
int			count_argv(char **argv);
void		many_pb(t_dst **a, t_dst **b);
int			under_5_argv(t_dst **a, t_dst **b, char **argv, t_config *conf);


#endif