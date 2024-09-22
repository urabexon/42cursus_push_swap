/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:06:14 by hurabe            #+#    #+#             */
/*   Updated: 2024/09/22 22:07:02 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// 配列の長さカウント用
int	count_argv(char **argv)
{
	int	argv_count;

	argv_count = 0;
	while (argv[argv_count])
		argv_count++;
	return (argv_count);
}

// リストbに格納されている全ての要素をリストaに移動する
// ft_lstsize(*b)でリストbのサイズ（要素数）を取得し、その要素数だけpa関数を呼び出してリストbの要素をaに移動させる
void	many_pb(t_dst **a, t_dst **b)
{
	int	b_count;
	int	i;

	b_count = ft_lstsize(*b);
	i = 0;
	while (i < b_count)
	{
		pa(a, b);
		i++;
	}
	return ;
}

// 引数の数が5以下の場合の処理
int	under_5_argv(t_dst **a, t_dst **b, char **argv, t_config *conf)
{
	// conf->len == 2の場合、sa(a)を呼び出してaリストの先頭の2つの要素を入れ替える
	// saでスタックaの先頭2つを交換
	if (conf->len == 2)
	{
		sa(a);
		return (1);
	}
	// conf->len == 3の場合、three_argという関数を使って3つの引数をソート
	if (conf->len == 3)
	{
		three_arg(argv, a, b);
		return (1);
	}
	// conf->len > 6の場合、radix_sortを使用してソート
	if (conf->len > 6)
	{
		radix_sort(a, b, conf);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_dst		**a;
	t_dst		**b;
	t_config	*conf;

	if (argc <= 1)
		exit(0); // 引数が1つなら終了
	if (argc == 2)
		return (output_error()); // 引数が2つだけならエラー処理
	if (is_argv_error(argv))
		return (output_error()); // 引数のエラーチェック
	// リストaとb、設定情報を格納するためにmalloc
	a = (t_dst **)malloc(sizeof(t_dst *));
	b = (t_dst **)malloc(sizeof(t_dst *));
	conf = (t_config *)malloc(sizeof(t_config));
	// メモリ確保失敗時の処理
	if (!a || !b || !conf)
		return (free(a), free(b), free(conf), 0);
	// 初期化処理
	init_dst(a, b, argv, conf);
	// すでにソートされているか、または引数が5つ以下の場合は終了
	if (is_ascending(a) || under_5_argv(a, b, argv, conf))
		exit(0);
	// ピボットに基づいてリストを分割する
	sep_pivot(argv, a, b, get_pivot_n(argv));
	// ソート処理の実行と結果の適用
	return (alg_1(a, b), many_pb(a, b), exit(0), 0);
}

// 流れ
// 1. 引数のチェック:
//・argc <= 1の場合は、引数がないのでプログラムを終了
//・argc == 2の場合はエラー処理を行い、output_error()が呼び出される
//・is_argv_error(argv)で引数にエラーがないかを確認し、エラーがあれば終了

// 2. メモリの確保:
// ・a、b、confはそれぞれリストa、リストb、および設定（t_config）用の構造体。これらのメモリを確保する

// 3. リストの初期化:
// ・init_dst(a, b, argv, conf)でリストaとb、および設定情報を初期化する

// 4. ソートが必要かどうかの確認:
// ・すでにリストが昇順にソートされているか、5つ以下の引数が処理された場合はexit(0)で終了する

// 5. ピボットを使った分割処理:
// ・sep_pivot(argv, a, b, get_pivot_n(argv))で、ピボット（基準値）を使ってリストを分割する

// 6. ソートの実行:
// ・alg_1(a, b)でソートアルゴリズムを適用し、many_pb(a, b)でリストbの全ての要素をリストaに戻す