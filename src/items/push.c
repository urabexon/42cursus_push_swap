/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:21:09 by hurabe            #+#    #+#             */
/*   Updated: 2024/09/22 21:38:32 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	push(t_dst **send, t_dst **recieve)
{
	t_dst	*send_to_recieve; // send_to_recieveはリストの現在の先頭ノードを操作するための変数
	t_dst	*next_send_top; // next_send_topは、送信元リストの2番目のノードを操作するための変数

	// 送信元からの場合は何もしない
	if (!send || !*send)
		return ;
	send_to_recieve = *send; // 送信元の先頭要素
	next_send_top = send_to_recieve->next; // 送信元の2番目の要素

	// 送信元の先頭要素を切り離し、次の要素を新しい先頭にする
	if (next_send_top)
		next_send_top->prev = NULL;
	*send = next_send_top;

	// 送信先の先頭に送信元の要素を追加する
	send_to_recieve->next = *recieve;
	if (*recieve)
		(*recieve)->prev = send_to_recieve;
	send_to_recieve->prev = NULL; // 新しい先頭の前はNULL

	// 送信元の要素を送信先の新しい先頭にする
	*recieve = send_to_recieve;
}

// bの先頭の要素を取ってaの先頭に置く。
// bが空の場合は何もしない。
void	pa(t_dst **a, t_dst **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

// aの先頭の要素を取り、bの先頭に置く。
// aが空の場合は何もしない。
void	pb(t_dst **a, t_dst **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}

// 動作の流れ
// 1. 送信元リストの先頭要素の切り離し:
// sendの先頭要素（send_to_recieve）を切り離し、2番目の要素（next_send_top）を新しい先頭に設定します。
// next_send_top->prev = NULL; によって、次の要素のprevをクリアしてリストの整合性を保ちます。

// 2. 送信先リストへの追加:
// send_to_recieveを送信先リスト（recieve）の先頭に追加します。
// 送信先が空でない場合（*recieveがNULLでない場合）、send_to_recieve->nextを現在の先頭に設定し、prevを適切に更新します。

// 3. ポインタの更新:
//*recieve = send_to_recieve; によって、送信元の要素を送信先の新しい先頭に設定します。
