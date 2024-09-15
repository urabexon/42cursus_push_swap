/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:06:21 by hurabe            #+#    #+#             */
/*   Updated: 2024/09/15 22:51:47 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//include
# include "src/libft/libft.h"

//struct Doubly Linked List
//値を保持する双方向リストの構造体,valueはリストの要素、press_valは座標圧縮で使用。
typedef struct s_dst
{
	long			value;
	long			press_val;
	struct s_dst	*next;
	struct s_dst	*prev;
}					t_dst;

//基数ソートの設定を保持するための構造体。lenはスタックの長さ、mux_numはスタック内の最大値を表す。
typedef struct s_config
{
	int		len;
	int		max_num;
}			t_config;

//command process function
//スタックを操作するコマンド関数
void	push(t_dst **send, t_dst **recieve);
void	reverse_rotate(t_dst **dst);
void	rotate(t_dst **dst);
void	swap(t_dst **dst);

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
long	*coordinate_press(char **argv, int len);

//radix sort
//基数ソート本体、スタックA（t_dst **a）をソートし、必要に応じてスタックB（t_dst **b）を使用してデータの移動を行う
long	get_top(t_dst *dst);
void	radix_sort(t_dst **a, t_dst **b, t_config *conf);

//main
int			count_argv(char **argv);
void		many_pb(t_dst **a, t_dst **b);
int			argv_checker(t_dst **a, t_dst **b, char **argv, t_config *conf);

#endif