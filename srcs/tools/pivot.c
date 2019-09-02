/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:40:12 by yodana            #+#    #+#             */
/*   Updated: 2019/08/26 16:40:17 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		check_tab_pivot_b(t_pile *a, int pivot)
{
	int i;

	i = 0;
	while (i + 1 < a->size)
	{
		if (a->numbers[i] > pivot)
			return (-1);
		i++;
	}
	return (1);
}

int		check_tab_pivot(t_pile *a, int pivot)
{
	int i;

	i = 0;
	while (i + 1 < a->size)
	{
		if (a->numbers[i] < pivot)
			return (-1);
		i++;
	}
	return (1);
}

int		find_pivot_median(t_pile *tmp, int i, int j, int e_inf)
{
	int e_sup;
	int res;

	if (tmp->size % 2 == 1)
		res = 1;
	else
		res = 0;
	e_sup = 0;
	while (++i < tmp->size - 1)
	{
		while (++j < tmp->size - 1)
		{
			if (tmp->numbers[i] < tmp->numbers[j])
				e_inf++;
			else if (tmp->numbers[i] > tmp->numbers[j])
				e_sup++;
		}
		if (e_sup - e_inf == res)
			return (i);
		e_sup = 0;
		e_inf = 0;
		j = -1;
	}
	return (i);
}

int		find_pos_pivot(t_pile *target, int pile)
{
	int i;

	i = 0;
	pile = 1;
	i = target->size / 2;
	return (i);
}

void	add_pivot(t_pile *p, int pivot)
{
	int i;

	i = p->size;
	p->numbers[i] = pivot;
	p->size = p->size + 1;
}
