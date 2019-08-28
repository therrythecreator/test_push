/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 18:54:20 by yodana            #+#    #+#             */
/*   Updated: 2019/08/28 18:54:43 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		find_pivot_five(t_pile *a)
{
	int i;

	i = a->size - 1;
	while (i > 0)
	{
		if (a->numbers[i] < a->numbers[i - 1])
			return (a->numbers[i]);
		i--;
	}
	return (a->numbers[a->size - 1]);
}

void	algo_five_b(t_all *res)
{
	int c;
	int pivot;
	int size;

	size = res->b->size;
	pivot = res->b->numbers[res->b->size - 1];
	c = 0;
	while (c < size)
	{
		if (pivot > res->b->numbers[0])
			check_move(res, "rb");
		else
			check_move(res, "pa");
		if (res->a->size > 1 && res->a->numbers[0] > res->a->numbers[1])
			check_move(res, "sa");
		c++;
	}
}

int		algo_a_follow(int pivot, t_all *res, int c, int size)
{
	if (res->a->numbers[0] == pivot)
		return (size);
	if (pivot < res->a->numbers[0])
		check_move(res, "ra");
	else
		check_move(res, "pb");
	if (res->b->size > 1 && res->b->numbers[0] < res->b->numbers[1])
	{
		if (res->b->size == 3 && res->b->numbers[0]
			< res->b->numbers[res->b->size - 1])
			check_move(res, "rb");
		else
			check_move(res, "sb");
	}
	return (c);
}

int		algo_five_a(t_all *res, int c, int size, int pivot)
{
	if (check_tab_pivot(res->a, pivot) == 1
		&& pivot == res->a->numbers[res->a->size - 1])
	{
		check_move(res, "rra");
		return (0);
	}
	while (res->a->size > 1 && c < size)
	{
		if (res->a->numbers[1] == pivot
			&& res->a->numbers[0] > res->a->numbers[1])
		{
			if (res->a->numbers[0] < res->a->numbers[res->a->size - 1])
				check_move(res, "sa");
			else
				check_move(res, "ra");
			c++;
		}
		if (check_tab(res->a->numbers, res->a->size) == 1
			&& (res->a->numbers[0] == pivot || res->a->size == 2))
			return (1);
		c = algo_a_follow(pivot, res, c, size);
		c++;
	}
	return (0);
}

void	algo_five(t_all *res)
{
	int c;

	c = 0;
	while (check_win(res->a, res->b) == -1)
	{
		while (res->a->size > 1 && c == 0)
			c = algo_five_a(res, 0, res->a->size, find_pivot_five(res->a));
		c = 0;
		while (res->b->size > 0)
			algo_five_b(res);
	}
}
