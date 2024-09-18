/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:21:15 by hurabe            #+#    #+#             */
/*   Updated: 2024/09/18 21:30:05 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate(t_dst **dst)
{
	t_dst	*front; // frontはリストの現在の先頭ノードを操作するための変数
	t_dst	*bottom_most; // bottom_mostはリストの最後のノードを操作するための変数

	// リストが空か、または一つしかない場合は何もしない
	if (!dst || ! *dst || !(*dst)->next)
		return ;
	front = *dst; // リストの先頭ノード
	bottom_most = ft_lstlast(*dst); // リストの最後のノード

	// 最後のノードを先頭に移動
	if (bottom_most->prev) // リストが2つ以上の要素を持っているかを確認
		bottom_most->prev->next = NULL; //新しい最後のノードのnextをNULLにする

	bottom_most->next = front; //最後のノードのnextを現在の先頭にする 
	bottom_most->prev = NULL; //最後のノードのprevをNULLにする(新しい先頭として設定する)
	front->prev = bottom_most; //旧先頭ノードのprevを新しい先頭ノードにする

	*dst = bottom_most; // リストの新しい先頭を更新する
}

// スタック a のすべての要素を 1 だけシフトダウンする。
// 最後の要素が最初の要素になる。
void	rra(t_dst **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

// スタック b のすべての要素を 1 だけシフトダウンする。
// 最後の要素が最初の要素になる。
void	rrb(t_dst **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

// rra と rrb を同時に行う。
void	rrr(t_dst **a, t_dst **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}

// 1. 先頭ノードと最後のノードの取得:
// frontでリストの先頭ノードを、bottom_mostでリストの最後のノードを取得する。

// 2. リンクの更新:
// 最後のノード（bottom_most）を先頭に移動させるために、以下のリンクを調整する：
// bottom_most->prev->next = NULLで、リストの新しい最後のノードを設定する。
// bottom_most->next = frontで、最後のノードを先頭ノードにリンクする。
// bottom_most->prev = NULLで、新しい先頭のprevをNULLにする。
// front->prev = bottom_mostで、元の先頭のprevを新しい先頭に設定する。

// 3. リストの先頭の更新:
// *dst = bottom_most; で、bottom_mostを新しい先頭ノードに設定する。