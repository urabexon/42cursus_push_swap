/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:21:19 by hurabe            #+#    #+#             */
/*   Updated: 2024/09/22 18:45:58 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// 渡されたスタック(双方向リスト)の先頭2つの要素を入れ替える関数。
// front_to_backは最初のノード、back_to_frontは2番目のノード
// ノードが2つ以上ある場合に、先頭2つのノードを入れ替える。
// third_numは3番目のノードを指す。これにより、最初の2つのノードを入れ替えた後のリストの整合性を保つ。

static void	swap(t_dst **dst)
{
	// これらの3つの変数は双方向リストの先頭2つのノードを入れ替える操作を行うためのポインタ。

	// 最初のノード、リストの最初野のノードの1を変更し、2番目のノードと入れ替えるために使われる。
	t_dst	*front_to_back;
	// 2番目のノードをスタックの先頭に持ってくる。入れ替え後は新しい先頭ノードになる。
	t_dst	*back_to_front;
	// 3番目のノードを指す。入れ替え後もリストの整合性を維持するために使用する。
	t_dst	*third_num;

	front_to_back = *dst;
	back_to_front = NULL;
	if (!front_to_back || !back_to_front)
		return ;
	back_to_front = front_to_back->next;
	third_num = back_to_front->next;
	// 先頭2つの要素を入れ替える
	front_to_back->next = third_num;
	front_to_back->prev = back_to_front;
	back_to_front->next = front_to_back;
	back_to_front->prev = NULL;
	// 3番目の要素がある場合、その前へのリンクを更新する
	if (third_num)
		third_num->prev = front_to_back;
	// dstが新しい先頭を指すようにする
	*dst = back_to_front;
}

// スタックaの先頭の2つの要素を入れ替える。
// 要素が1つしかないか、何もない場合は何もしない。
void	sa(t_dst **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

// スタック b の先頭の 2 つの要素を入れ替える。
// 要素が1つしかない場合は何もしない。
void	sb(t_dst **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

// sa と sb を同時に実行する。
void	ss(t_dst **a, t_dst **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
