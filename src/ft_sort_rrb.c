/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort_rrb.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/14 21:11:28 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/22 19:18:26 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header.h"

int			ft_sort_rrb(t_pile **a, t_pile **b, t_conv *conv)
{
	t_pile	*tmp;

	(void)a;
	if (!*b || ft_pile_size(*b) < 2)
		return (1);
	tmp = *b;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_recreate_elem((*b)->data, conv);
	tmp = *b;
	*b = (*b)->next;
	free(tmp);
	return (1);
}
