/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_try_sort.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 15:29:37 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/28 22:08:18 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header.h"

int		ft_data_side(t_pile *pile)
{
	int		max;
	int		size;
	int		count;

	size = ft_pile_size(pile);
	count = 0;
	max = ft_pile_max(pile, &size);
	while (pile)
	{
		if (pile->data == max)
			break ;
		count++;
		pile = pile->next;
	}
	return (count < size / 2 ? 1 : 0);
}

int		ft_another_check_sort(t_pile *pile, t_pile *b)
{
	int		max;

	if (!pile->next)
		return (1);
	max = ft_pile_max(b, 0);
	while (pile->next)
	{
		if (pile->data < pile->next->data || pile->data < max)
			return (0);
		pile = pile->next;
	}
	if (pile->data < max)
		return (0);
	return (1);
}

int		ft_try_sort(t_pile *a, t_pile *b, t_conv *conv)
{
	int		max;

	max = ft_pile_max(a, 0);
	while (!ft_another_check_sort(a, b))
	{
		if (ft_last(a)->data == max || ft_pile_second_max(a))
			ft_printf(ft_sort_ra(&a, &b, conv) ? "ra\n" : "");
		else
			ft_printf(ft_sort_pb(&a, &b, conv) ? "pb\n" : "");
	}
	while (b)
	{
		if (ft_last(b)->data == ft_pile_max(b, 0))
			ft_printf(ft_sort_pa(&a, &b, conv) ? "pa\n" : "");
		else if (ft_data_side(b))
			ft_printf(ft_sort_rrb(&a, &b, conv) ? "rrb\n" : "");
		else
			ft_printf(ft_sort_rb(&a, &b, conv) ? "rb\n" : "");
	}
	ft_pile_del(&a);
	return (1);
}
