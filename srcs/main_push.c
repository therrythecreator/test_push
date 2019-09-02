/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 02:11:42 by yodana            #+#    #+#             */
/*   Updated: 2019/07/22 02:12:02 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	finish_push(t_all *res)
{
	while (res->b->size > 0)
		check_move(res, "pa");
}

int		check_tab_b(int *target, int size)
{
	int i;

	i = 0;
	while (i + 1 < size)
	{
		if (target[i] < target[i + 1])
			return (-1);
		i++;
	}
	return (1);
}
int		find_median(int *a, int size)
{
	return (a[(size / 2)]);
}

int		find_quartile_2(t_pile *a)
{
	return (find_median(&a->numbers[(a->size / 2)], a->size / 2));
}

int		find_quartile(int *a, int size)
{
	return (a[(size / 4)]);	
}

void	init_pf(t_all *res)
{
	res->pf->numbers[3] = find_quartile(res->a->numbers, res->a->size);
	res->pf->numbers[2] = find_median(res->a->numbers, res->a->size);
	res->pf->numbers[1] = find_quartile_2(res->a);
	res->pf->numbers[0] = res->a->numbers[res->a->size - 1];
	//	ft_printf("quaritle 2 == %d", res->pf->numbers[0]);
	//ft_printf("quaritle 2 == %d", i);

}

int		main(int argc, char **argv)
{
	t_all	res;
	int		mv;

	mv = 0;
	if (argc == 1)
		return (0);
	res.verif_exe = 1;
	if (init(&res, argv, ft_size(argv)) == -1)
		ft_error();
	if (check(argv) == -1 || check_double(res.a) == -1)
		ft_error();
	while (res.a->size > 1 && check_win(res.a, res.b) == -1)
		algo_go(&res, 0);
	while (check_win(res.a, res.b) == -1)
	{
		while (check_win(res.a, res.b) == -1
			&& check_tab(res.a->numbers, res.a->size) == 1)
			algo_go(&res, 1);
		while (check_tab(res.a->numbers, res.a->size) == -1)
			algo_go(&res, 2);
	}
	all_free(&res);
	return (0);
}
